/* Solved
 * 4657. Gas Wars - binary search + maxflow
 * File:   GASWARS.cpp
 * Author: Andy Y.F. Huang
 * Created on August 30, 2012, 5:05 PM
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
namespace GASWARS {
const int k_max_vertices = 150, k_max_edges = 25000, inf = 1 << 25;
int origflow[k_max_vertices][k_max_vertices];
int flow[k_max_vertices][k_max_vertices], cap[k_max_vertices][k_max_vertices];
int prev[k_max_vertices], queue[k_max_vertices];
int last[k_max_vertices], to[k_max_edges], next[k_max_edges], index = 0;
int totry[k_max_edges];

int findpath(int source, int sink, int maxcap) {
  memset(prev, 0xFF, sizeof (prev));
  int qf = 0, qb = 0, total = 0;
  prev[queue[qb++] = source] = -2;
  while (qf < qb && prev[sink] == -1)
    for (int cur = queue[qf++], i = last[cur]; i != -1; i = next[i])
      if (prev[to[i]] == -1 && flow[cur][to[i]]
              && (cap[cur][to[i]] <= maxcap || cap[cur][to[i]] == inf))
        prev[queue[qb++] = to[i]] = cur;
  if (prev[sink] == -1)
    return 0;
  for (int i = last[sink]; i != -1; i = next[i]) {
    if (!flow[to[i]][sink] || prev[to[i]] == -1)
      continue;
    int minflow = flow[to[i]][sink];
    for (int v = to[i], u = prev[v]; u >= 0; v = u, u = prev[v])
      minflow = min(minflow, flow[u][v]);
    if (!minflow)
      continue;
    total += minflow;
    for (int v = sink, u = to[i]; u >= 0; v = u, u = prev[v]) {
      flow[u][v] -= minflow;
      flow[v][u] += minflow;
    }
  }
  return total;
}

int maxflow(int source, int sink, int maxcap) {
  for (int i = 0; i <= sink; i++)
    for (int j = 0; j <= sink; j++)
      flow[i][j] = origflow[i][j];
  int ans = 0;
  while (true) {
    int temp = findpath(source, sink, maxcap);
    if (temp == 0)
      break;
    ans += temp;
  }
  return ans;
}

void addedge(int start, int end, int capacity) {
  origflow[start][end] += capacity;
  origflow[end][start] += capacity;
  cap[start][end] = cap[end][start] = capacity;
  to[index] = end;
  next[index] = last[start];
  last[start] = index++;
  to[index] = start;
  next[index] = last[end];
  last[end] = index++;
}

void solve(int test_num) {
  index = 0;
  memset(last, 0xFF, sizeof (last));
  memset(origflow, 0, sizeof (origflow));
  int vertices, edges, starts, ends, needed;
  scanf("%d %d %d %d %d", &vertices, &edges, &starts, &ends, &needed);
  int source = vertices, sink = source + 1;
  for (int i = 0; i < edges; i++) {
    int start, end, capacity;
    scanf("%d %d %d", &start, &end, &capacity);
    addedge(--start, --end, capacity);
    totry[i] = capacity;
  }
  for (int i = 0; i < starts; i++) {
    int start;
    scanf("%d", &start);
    addedge(source, --start, inf);
  }
  for (int i = 0; i < ends; i++) {
    int end;
    scanf("%d", &end);
    addedge(--end, sink, inf);
  }
  sort(totry, totry + edges);
  int uniquecaps = unique(totry, totry + edges) - totry;
  int ans = totry[uniquecaps - 1];
  if (maxflow(source, sink, totry[uniquecaps - 1]) <= needed) {
    puts("-1");
    return;
  }
  for (int low = 0, high = uniquecaps - 1; low <= high; ) {
    int mid = (low + high) >> 1;
    if (maxflow(source, sink, totry[mid]) >= needed)
      ans = min(ans, totry[mid]), high = mid - 1;
    else
      low = mid + 1;
  }
  printf("%d\n", ans * 100);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  GASWARS::solve();
  return 0;
}

