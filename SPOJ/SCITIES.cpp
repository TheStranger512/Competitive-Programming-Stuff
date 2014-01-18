/* Solved
 * 286. Selfish Cities
 * File:   SCITIES.cpp
 * Author: Andy Y.F. Huang
 * Created on March 28, 2013, 10:57 PM
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

namespace SCITIES {

template <class Flow, class Cost, size_t MAXV, size_t MAXE> struct MinCostFlow {
  int last[MAXV], to[MAXE << 1], next[MAXE << 1], queue[8 * MAXV], prev[MAXV];
  Flow cap[MAXE << 1], flow[MAXE << 1], amount[MAXV];
  Cost cost[MAXE << 1], dist[MAXV];
  bool inQ[MAXV];
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
    while (true) {
      fill(dist, dist + MAXV, INF_COST);
      memset(inQ, false, sizeof (inQ));
      prev[source] = -2;
      dist[source] = 0;
      amount[source] = INF_FLOW;
      int qf = 0, qb = 0;
      queue[qb++] = source;
      inQ[source] = true;
      for (; qf < qb; qf++) {
        int at = queue[qf];
        Cost cdist = dist[at];
        for (int id = last[at], v; id != -1; id = next[id]) {
          v = to[id];
          if (flow[id] < cap[id] && cdist + cost[id] < dist[v]) {
            dist[v] = cdist + cost[id];
            prev[v] = id;
            amount[v] = min(amount[at], cap[id] - flow[id]);
            if (!inQ[v])
              inQ[queue[qb++] = v] = true;
          }
        }
        inQ[at] = false;
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

#define SOURCE 201
#define SINK 202
MinCostFlow<int, int, 210, 11000 > mcmf;

void solve(int test_num) {
  mcmf.init();
  int left, right;
  scanf("%d %d", &left, &right);
  for (int i = 0; i < left; i++)
    mcmf.addedge(SOURCE, i, 1, 0);
  for (int i = 0; i < right; i++)
    mcmf.addedge(i + left, SINK, 1, 0);
  for (int a, b, cost; ;) {
    scanf("%d %d %d", &a, &b, &cost);
    if (a == 0) break;
    a--, b--;
    mcmf.addedge(a, b + left, 1, -cost);
  }
  int res = mcmf.go(SOURCE, SINK).second;
  printf("%d\n", -res);
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
  SCITIES::solve();
  return 0;
}

