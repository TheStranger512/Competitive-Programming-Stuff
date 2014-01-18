/* Solved
 * 4227. "Shortest" pair of paths
 * File:   MSE06I.cpp
 * Author: Andy Y.F. Huang
 * Created on May 29, 2013, 12:17 AM
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

namespace MSE06I {

template <class Flow, class Cost, size_t MAXV, size_t MAXE> struct MinCostFlow {
  int last[MAXV], to[MAXE << 1], next[MAXE << 1], queue[8 * MAXV], prev[MAXV];
  Flow cap[MAXE << 1], flow[MAXE << 1], amount[MAXV];
  Cost cost[MAXE << 1], dist[MAXV];
  bool vis[MAXV];
  int edgecnt;

  void init() {
    memset(last, -1, sizeof (last));
    edgecnt = 0;
  }

  void __addedge(int s, int t, Flow f, Cost c) {
    to[edgecnt] = t;
    next[edgecnt] = last[s];
    cap[edgecnt] = f;
    flow[edgecnt] = 0;
    cost[edgecnt] = c;
    last[s] = edgecnt++;
  }

  void addedge(int from, int to, Flow flow, Cost cost) {
    __addedge(from, to, flow, cost);
    __addedge(to, from, 0, -cost);
  }

  pair<Flow, Cost> go(int source, int sink) {
    Flow maxflow = 0;
    Cost mincost = 0;
    const Flow INF_FLOW = numeric_limits<Flow>::max();
    const Cost INF_COST = numeric_limits<Cost>::max();
    while (maxflow < 2) {
      fill(dist, dist + MAXV, INF_COST);
      memset(vis, false, sizeof (vis));
      prev[source] = -2;
      dist[source] = 0;
      amount[source] = INF_FLOW;
      int qf = 0, qb = 0;
      queue[qb++] = source;
      vis[source] = true;
      for (; qf < qb; qf++) {
        int at = queue[qf];
        Cost cdist = dist[at];
        for (int id = last[at], v; id != -1; id = next[id]) {
          v = to[id];
          if (flow[id] < cap[id] && cdist + cost[id] < dist[v]) {
            dist[v] = cdist + cost[id];
            prev[v] = id;
            amount[v] = min(amount[at], cap[id] - flow[id]);
            if (!vis[v])
              vis[queue[qb++] = v] = true;
          }
        }
        vis[at] = false;
      }
      if (dist[sink] == INF_COST) break;
      Flow by = amount[sink];
      maxflow += by;
      mincost += dist[sink] * by;
      for (int e = prev[sink]; e > -1; e = prev[to[e ^ 1]])
        flow[e] += by, flow[e ^ 1] -= by;
    }
    return make_pair(maxflow, mincost);
  }

} ;

MinCostFlow<int, int, 555, 555 > net;
int vertices, edges;

void solve(int test_num) {
  net.init();
  for (int e = 0, a, b, cost; e < edges; e++) {
    scanf("%d %d %d", &a, &b, &cost);
    net.addedge(a + vertices, b, 1, cost);
  }
  for (int v = 1; v < vertices - 1; v++)
    net.addedge(v, v + vertices, 1, 0);
  net.addedge(0, 0 + vertices, 2, 0);
  pair<int, int> res = net.go(0, vertices - 1);
  printf("Instance #%d:  ", test_num);
  if (res.first < 2)
    puts("Not possible");
  else printf("%d\n", res.second);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  for (int i = 1; scanf("%d %d", &vertices, &edges) != EOF; i++)
    if (vertices + edges > 0)
      solve(i);
}
}

int main() {
  MSE06I::solve();
  return 0;
}

