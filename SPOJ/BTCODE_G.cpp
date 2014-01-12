/*
 * Solved
 * 8425. Coloring Trees
 * File:   BTCODE_G.cpp
 * Author: Andy Y.F. Huang
 * Created on March 3, 2013, 3:54 PM
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

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace BTCODE_G {
#define MAXCOLS 30
#define MAX 111000
int sum[MAXCOLS + 1][1 << 18];
int last[MAX], to[2 * MAX], next[2 * MAX], color[MAX], dist[MAX];
int par[18][MAX], timein[MAX], timeout[MAX], top[MAX], size[MAX];
int pos[MAX];
int nextpos, OFFSET, MAXLOG;

int nexttime() {
  static int t = 0;
  return t++;
}

int queryrsq(int* tree, int left, int right) {
  int ans = 0;
  for (int l = left + OFFSET, r = right + OFFSET + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ans += tree[l++];
    if (r & 1) ans += tree[--r];
  }
  return ans;
}

void updatersq(int* tree, int pos, int val) {
  tree[pos + OFFSET] = val;
  for (int i = (pos + OFFSET) >> 1; i > 0; i >>= 1)
    tree[i] = tree[i + i] + tree[i + i + 1];
}

bool isanc(int a, int b) {
  return timein[a] <= timein[b] && timeout[b] <= timeout[a];
}

int getlca(int a, int b) {
  if (isanc(a, b)) return a;
  for (int i = MAXLOG; i >= 0; i--)
    if (!isanc(par[i][a], b))
      a = par[i][a];
  return par[0][a];
}

void dfs1(int at) {
  timein[at] = nexttime();
  size[at] = 1;
  for (int id = last[at]; id != -1; id = next[id]) {
    if (to[id] != par[0][at]) {
      par[0][to[id]] = at;
      dist[to[id]] = dist[at] + 1;
      dfs1(to[id]);
      size[at] += size[to[id]];
    }
  }
  timeout[at] = nexttime();
}

void dfs2(int at, int curtop) {
  top[at] = curtop;
  pos[at] = nextpos++;
  int heavy = -1;
  for (int id = last[at]; id != -1; id = next[id])
    if (to[id] != par[0][at] && (heavy == -1 || size[to[id]] > size[heavy]))
      heavy = to[id];
  if (heavy == -1)
    return;
  dfs2(heavy, curtop);
  for (int id = last[at]; id != -1; id = next[id])
    if (to[id] != par[0][at] && to[id] != heavy)
      dfs2(to[id], to[id]);
}

int query(int a, int b, int col) {
  int res = 0;
  while (top[a] != top[b]) {
    res += queryrsq(sum[col], pos[top[a]], pos[a]);
    a = par[0][top[a]];
  }
  res += queryrsq(sum[col], pos[b], pos[a]);
  return res;
}

void solve(int test_num) {
  int vertices;
  scanf("%d", &vertices);
  //memset(sum, 0, sizeof (sum));
  //memset(color, 0, sizeof (color));
  memset(last, -1, sizeof (last));
  for (int e = 1, a, b; e < vertices; e++) {
    scanf("%d %d", &a, &b);
    to[e] = b;
    next[e] = last[a];
    last[a] = e;
    to[e + vertices] = a;
    next[e + vertices] = last[b];
    last[b] = e + vertices;
  }
  par[0][0] = 0;
  dist[0] = 0;
  nextpos = 0;
  OFFSET = 1;
  MAXLOG = 0;
  while (OFFSET < vertices)
    OFFSET <<= 1, MAXLOG++;
  dfs1(0);
  dfs2(0, 0);
  for (int i = 1; i <= MAXLOG; i++)
    for (int v = 0; v < vertices; v++)
      par[i][v] = par[i - 1][par[i - 1][v]];
  for (int v = 0; v < vertices; v++)
    sum[0][pos[v] + OFFSET] = 1;
  for (int i = OFFSET - 1; i > 0; i--)
    sum[0][i] = sum[0][i + i] + sum[0][i + i + 1];
  int quests;
  scanf("%d", &quests);
  for (int q = 0; q < quests; q++) {
    int type, a, b;
    scanf("%d %d %d", &type, &a, &b);
    if (type == 1) {
      color[a] = b;
      updatersq(sum[color[a]], pos[a], 1);
    }
    else {
      int lca = getlca(a, b);
      int cnt = query(a, lca, color[a]) + query(b, lca, color[a]);
      if (color[lca] == color[a])
        cnt--; //added lca twice
      if (color[a] == 0 || cnt != dist[a] + dist[b] - 2 * dist[lca] + 1)
        puts("NO");
      else puts("YES");
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
  BTCODE_G::solve();
  return 0;
}

