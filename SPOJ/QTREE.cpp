/*
 * Solved
 * 375. Query on a tree
 * ONLY TOOK 2 HOURS ...
 * File:   QTREE.cpp
 * Author: Andy Y.F. Huang
 * Created on March 3, 2013, 12:34 PM
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
namespace QTREE {
#define MAX 11111
#define MAXLOG 15
#define INF (1 << 29)
int last[MAX], to[2 * MAX], next[2 * MAX], cost[2 * MAX];
int par[MAXLOG][MAX], top[MAX], depth[MAX], size[MAX];
int rmq[33333], rmqpos[MAX], nextrmq;
int vertices, offset;

int queryrmq(int left, int right) {
  int ans = -INF;
  for (int l = left + offset, r = right + offset + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ans = max(ans, rmq[l++]);
    if (r & 1) ans = max(ans, rmq[--r]);
  }
  return ans;
}

void updatermq(int pos, int val) {
  rmq[pos + offset] = val;
  for (int i = (pos + offset) >> 1; i > 0; i >>= 1)
    rmq[i] = max(rmq[i + i], rmq[i + i + 1]);
}

int getlca(int a, int b) {
  if (depth[b] > depth[a]) swap(a, b);
  for (int i = MAXLOG - 1; i >= 0; i--)
    if (depth[par[i][a]] >= depth[b])
      a = par[i][a];
  if (a == b) return a;
  for (int i = MAXLOG - 1; i >= 0; i--)
    if (par[i][a] != par[i][b])
      a = par[i][a], b = par[i][b];
  return par[0][a];
}

int query(int a, int b) {
  int ans = -INF;
  while (top[a] != top[b]) {
    ans = max(ans, queryrmq(rmqpos[top[a]], rmqpos[a]));
    a = par[0][top[a]];
  }
  ans = max(ans, queryrmq(rmqpos[b] + 1, rmqpos[a]));
  return ans;
}

void dfs1(int at) {
  size[at] = 1;
  for (int id = last[at]; id != -1; id = next[id]) {
    if (to[id] != par[0][at]) {
      par[0][to[id]] = at;
      depth[to[id]] = depth[at] + 1;
      dfs1(to[id]);
      size[at] += size[to[id]];
    }
  }
}

void dfs2(int at, int curtop) {
  top[at] = curtop;
  rmqpos[at] = nextrmq++;
  int son = -1;
  for (int id = last[at]; id != -1; id = next[id])
    if (to[id] != par[0][at] && (son == -1 || size[to[id]] > size[son]))
      son = to[id];
  if (son == -1)  //leaf node
    return;
  dfs2(son, curtop);
  for (int id = last[at]; id != -1; id = next[id])
    if (to[id] != son && to[id] != par[0][at])
      dfs2(to[id], to[id]);
}

void solve(int test_num) {
  memset(last, -1, sizeof (last));
  memset(rmq, 0xF0, sizeof (rmq));
  memset(rmqpos, -1, sizeof (rmqpos));
  scanf("%d", &vertices);
  for (int e = 0, a, b; e < vertices - 1; e++) {
    scanf("%d %d %d", &a, &b, cost + e);
    cost[e + vertices] = cost[e];
    to[e] = b;
    next[e] = last[a];
    last[a] = e;
    to[e + vertices] = a;
    next[e + vertices] = last[b];
    last[b] = e + vertices;
  }
  memset(size, 0, sizeof (size));
  depth[1] = 0;
  par[0][1] = 1;
  nextrmq = 0;
  offset = 1;
  while (offset < vertices)
    offset <<= 1;
  dfs1(1);
  dfs2(1, 1);
  for (int i = 1; i < MAXLOG; i++)
    for (int v = 1; v <= vertices; v++)
      par[i][v] = par[i - 1][par[i - 1][v]];
  rmq[rmqpos[1] + offset] = -INF; //fake edge cost
  for (int e = 0, x; e < vertices - 1; e++) {
    if (depth[to[e]] > depth[to[e + vertices]])
      x = to[e];
    else x = to[e + vertices];
    rmq[rmqpos[x] + offset] = cost[e];
  }
  for (int i = offset - 1; i > 0; i--)
    rmq[i] = max(rmq[i + i], rmq[i + i + 1]);
  while (true) {
    static char str[11];
    scanf("%s", str);
    if (str[0] == 'D') break;
    if (str[0] == 'Q') {
      int a, b;
      scanf("%d %d", &a, &b);
      int lca = getlca(a, b);
      int res = max(query(a, lca), query(b, lca));
      printf("%d\n", res);
    }
    else {
      int ith, ncost, node;
      scanf("%d %d", &ith, &ncost);
      ith--;
      cost[ith] = cost[ith + vertices] = ncost;
      if (depth[to[ith]] > depth[to[ith + vertices]])
        node = to[ith];
      else node = to[ith + vertices];
      updatermq(rmqpos[node], ncost);
    }
  }
  //pln("Done");
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  QTREE::solve();
  return 0;
}

