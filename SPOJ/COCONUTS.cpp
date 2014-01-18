/* Solved
 * 1693. Coconuts
 * Mincut
 * File:   COCONUTS.cpp
 * Author: Andy Y.F. Huang
 * Created on September 27, 2012, 11:55 PM
 */

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <fstream>
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace COCONUTS {
int guards, friends;
const int k_max_vertices = 333, k_max_edges = 111111;
int cap[k_max_vertices][k_max_vertices];
int prev[k_max_vertices], q[k_max_vertices];
int last[k_max_vertices], to[k_max_edges], next[k_max_edges], edgecnt;

int findpath(int source, int sink) {
  memset(prev, 0xFF, sizeof (prev));
  int qf = 0, qb = 0, total = 0;
  prev[q[qb++] = source] = -2;
  while (qf < qb && prev[sink] == -1)
    for (int cur = q[qf++], i = last[cur]; i != -1; i = next[i])
      if (prev[to[i]] == -1 && cap[cur][to[i]])
        prev[q[qb++] = to[i]] = cur;
  if (prev[sink] == -1)
    return 0;
  for (int i = last[sink]; i != -1; i = next[i]) {
    if (!cap[to[i]][sink] || prev[to[i]] == -1)
      continue;
    int mincap = cap[to[i]][sink];
    for (int v = to[i], u = prev[v]; u >= 0; v = u, u = prev[v])
      mincap = min(mincap, cap[u][v]);
    if (!mincap)
      continue;
    total += mincap;
    for (int v = sink, u = to[i]; u >= 0; v = u, u = prev[v]) {
      cap[u][v] -= mincap;
      cap[v][u] += mincap;
    }
  }
  return total;
}

void addedge(int start, int end) {
  to[edgecnt] = end;
  next[edgecnt] = last[start];
  last[start] = edgecnt++;
  to[edgecnt] = start;
  next[edgecnt] = last[end];
  last[end] = edgecnt++;
}

void solve(int test_num) {
  memset(last, 0xFF, sizeof (last));
  memset(cap, 0, sizeof (cap));
  edgecnt = 0;
  int source = guards, sink = guards + 1;
  for (int i = 0; i < guards; i++) {
    int believe;
    scanf("%d", &believe);
    if (believe)
      addedge(source, i), cap[source][i] = 1;
    else
      addedge(i, sink), cap[i][sink] = 1;
  }
  for (int f = 0; f < friends; f++) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--, b--;
    addedge(a, b);
    cap[a][b] = cap[b][a] = 1;
  }
  int ans = 0;
  while (true) {
    int flow = findpath(source, sink);
    if (!flow)
      break;
    ans += flow;
  }
  printf("%d\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (true) {
    scanf("%d %d", &guards, &friends);
    if (guards == 0 && friends == 0)
      break;
    solve(1);
  }
}
}

int main() {
  COCONUTS::solve();
  return 0;
}

