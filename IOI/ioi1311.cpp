/* Solved
 * IOI '13 - Brisbane, Australia
 * Dreaming
 * File:   ioi1311.cpp
 * Author: Andy Y.F. Huang
 * Created on July 15, 2013, 7:19 AM
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

namespace ioi1311 {
#define MAX 111000
#define INF 0x3F3F3F3F
int dist1[MAX], dist2[MAX];
int last[MAX], to[2 * MAX], next[2 * MAX], cost[2 * MAX];
int pred[MAX];
int best;

void dfs1(int at, int par) {
  if (dist1[at] > dist1[best])
    best = at;
  for (int e = last[at]; ~e; e = next[e]) {
    if (to[e] != par) {
      dist1[to[e]] = dist1[at] + cost[e];
      dfs1(to[e], at);
    }
  }
}

void dfs2(int at) {
  if (dist2[at] > dist2[best])
    best = at;
  for (int e = last[at]; ~e; e = next[e]) {
    if (to[e] != pred[at]) {
      pred[to[e]] = at;
      dist2[to[e]] = dist2[at] + cost[e];
      dfs2(to[e]);
    }
  }
}

void add_edge(int a, int b, int c) {
  static int e = 0;
  to[e] = b;
  cost[e] = c;
  next[e] = last[a];
  last[a] = e++;
}

void solve(int test_num) {
  memset(last, -1, sizeof (last));
  int V, E, L;
  scanf("%d %d %d", &V, &E, &L);
  for (int e = 0, a, b, c; e < E; e++) {
    scanf("%d %d %d", &a, &b, &c);
    add_edge(a, b, c);
    add_edge(b, a, c);
  }
  for (int i = 0; i < V; i++)
    dist1[i] = dist2[i] = INF;
  int res = 0;
  vector<int> rads;
  for (int v = 0; v < V; v++) {
    if (dist1[v] < INF) continue;
    dist1[v] = 0;
    best = v;
    dfs1(v, -1);
    dist2[best] = 0;
    pred[best] = -1;
    dfs2(best);
    res = max(res, dist2[best]);
    int rad = dist2[best];
    for (int at = best; ~at; at = pred[at])
      rad = min(rad, max(dist2[at], dist2[best] - dist2[at]));
    rads.push_back(rad);
  }
  sort(rads.begin(), rads.end(), greater<int>());
  if (rads.size() >= 2u)
    res = max(res, rads[0] + rads[1] + L);
  if (rads.size() >= 3u)
    res = max(res, rads[1] + rads[2] + L + L);
  printf("%d\n", res);
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
  ioi1311::solve();
  return 0;
}

