/* Solved
 * 3977. Police Query
 * File:   POLQUERY.cpp
 * Author: Andy Y.F. Huang
 * Created on April 27, 2013, 8:28 PM
 */

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

namespace POLQUERY {
#define MAXV 100100
#define MAXE 500500
const char *NO = "ne", *YES = "da";
typedef long long llong;
int last[MAXV], to[2 * MAXE], next[2 * MAXE];
int cur[MAXV], low[MAXV], in[MAXV], out[MAXV];
int par[17][MAXV];
llong bridges[MAXV];
bool iscut[MAXV], isbridge[2 * MAXE];
int bridgecnt, maxlog;

int nextnum() {
  static int X = 0;
  return ++X;
}

void addedge(int a, int b) {
  static int e = 0;
  to[e] = b;
  next[e] = last[a];
  last[a] = e++;
}

bool isanc(int a, int b) {
  return in[a] <= in[b] && out[b] <= out[a];
}

int getlca(int a, int b) {
  if (isanc(a, b)) return a;
  for (int i = maxlog; i >= 0; i--)
    if (!isanc(par[i][a], b))
      a = par[i][a];
  return par[0][a];
}

int getdesc(int A, int B) {
  //find first child of B that is ancestor of A
  //assert(isanc(B, A));
  //pln(A, B);
  for (int i = maxlog; i >= 0; i--)
    if (!isanc(par[i][A], B))
      A = par[i][A];
  //pln(A);
  return A;
}

void dfs(int at) {
  //pln(at, par[0][at]);
  low[at] = in[at] = nextnum();
  int size = 0;
  for (int e = last[at]; e > -1; e = next[e]) {
    if (to[e] == par[0][at]) continue;
    if (in[to[e]] > -1)
      low[at] = min(low[at], in[to[e]]);
    else {
      size++;
      par[0][to[e]] = at;
      dfs(to[e]);
      low[at] = min(low[at], low[to[e]]);
      if (in[at] < low[to[e]])
        isbridge[e] = isbridge[e ^ 1] = true;
      if (in[at] <= low[to[e]] && par[0][at] != at)
        iscut[at] = true;
    }
  }
  if (at == par[0][at] && size > 1) iscut[at] = true;
  out[at] = nextnum();
}

void solve(int test_num) {
  bridgecnt = 0;
  memset(in, -1, sizeof (in));
  memset(last, -1, sizeof (last));
  memset(isbridge, false, sizeof (isbridge));
  memset(iscut, false, sizeof (iscut));
  int vertices, edges;
  scanf("%d %d", &vertices, &edges);
  for (int e = 0, a, b; e < edges; e++) {
    scanf("%d %d", &a, &b);
    if (b > a) swap(a, b);
    addedge(a, b);
    addedge(b, a);
  }
  par[0][1] = 1;
  dfs(1);
  maxlog = 0;
  while ((1 << maxlog) < vertices)
    maxlog++;
  maxlog--;
  for (int j = 1; j <= maxlog; j++)
    for (int i = 1; i <= vertices; i++)
      par[j][i] = par[j - 1][par[j - 1][i]];
  edges <<= 1;
  for (int e = 0; e < edges; e += 2)
    if (isbridge[e])
      bridges[bridgecnt++] = 1000000LL * to[e] + to[e ^ 1];
  sort(bridges, bridges + bridgecnt);
  //plnarr(bridges, bridges + bridgecnt);
  //plnarr(iscut + 1, iscut + 1 + vertices);
  int quests;
  scanf("%d", &quests);
  for (int q = 0, a, b, g1, g2, v, type, lca; q < quests; q++) {
    scanf("%d %d %d", &type, &a, &b);
    if (type == 1) {
      //bridge
      scanf("%d %d", &g1, &g2);
      if (g2 < g1)
        swap(g1, g2);
      if (!binary_search(bridges, bridges + bridgecnt, 1000000LL * g1 + g2))
        puts(YES);
      else {
        lca = getlca(a, b);
        if (in[g2] < in[g1])
          swap(g1, g2);
        //g1 is parent of g2
        //assert(par[0][g2] == g1);
        if (isanc(lca, g1) && (isanc(g2, a) || isanc(g2, b)))
          puts(NO);
        else
          puts(YES);
      }
    }
    else {
      //cut vertex
      scanf("%d", &v);
      if (!iscut[v]) puts(YES);
      else {
        lca = getlca(a, b);
        if (lca == v) {
          if (low[getdesc(a, v)] >= in[v] || low[getdesc(b, v)] >= in[v])
            puts(NO);
          else
            puts(YES);
        }
        else if (isanc(lca, v) && (isanc(v, a) || isanc(v, b))) {
          //either V is ancestor of A or V is ancestor of B but not both
          int ch = getdesc(isanc(v, a) ? a : b, v);
          if (low[ch] < in[v]) puts(YES);
          else puts(NO);
        }
        else
          puts(YES);
      }
    }
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  solve(1);
}
}

int main() {
  POLQUERY::solve();
  return 0;
}

