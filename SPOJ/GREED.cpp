/*
 * Solved
 * 373. Greedy island
 * File:   GREED.cpp
 * Author: Andy Y.F. Huang
 * Created on February 27, 2013, 9:49 PM
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
namespace GREED {

template <class Flow, class Cost, size_t MAXV, size_t MAXE> struct MinCostFlow {
  int last[MAXV], to[MAXE << 1], next[MAXE << 1], queue[5 * MAXV], prev[MAXV];
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

MinCostFlow<int, int, 555, 155000 > mcmf;
#define SOURCE 501
#define SINK 502
int cnt[555];

void solve(int test_num) {
  mcmf.init();
  memset(cnt, 0, sizeof (cnt));
  int cards;
  scanf("%d", &cards);
  for (int i = 0, card; i < cards; i++) {
    scanf("%d", &card);
    cnt[card]++;
  }
  for (int c = 1; c <= cards; c++) {
    if (cnt[c] > 0)
      mcmf.addedge(SOURCE, c, cnt[c], 0);
    mcmf.addedge(c, SINK, 1, 0);
  }
  int edges;
  scanf("%d", &edges);
  for (int e = 0, x, y; e < edges; e++) {
    scanf("%d %d", &x, &y);
    mcmf.addedge(x, y, cards, 1);
    mcmf.addedge(y, x, cards, 1);
  }
  pair<int, int> ans = mcmf.go(SOURCE, SINK);
  //pln(ans);
  printf("%d\n", ans.second);
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
  GREED::solve();
  return 0;
}

