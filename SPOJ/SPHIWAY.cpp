/* Solved
 * 5115. Two "Ways"
 * File:   SPHIWAY.cpp
 * Author: Andy Y.F. Huang
 * Created on February 27, 2013, 11:25 PM
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

namespace SPHIWAY {
const unsigned int buffer_size = 1 << 16;
char input_buffer[buffer_size];
unsigned int bytes_read = 0;
unsigned int input_index = 0;

inline char next_char() {
  if (input_index == bytes_read) {
    bytes_read = fread(input_buffer, sizeof (char) , buffer_size, stdin);
    input_buffer[bytes_read] = '\0'; //sentinel
    input_index = 0;
  }
  return input_buffer[input_index++];
}

inline int next_int() {
  char c = 0;
  int ans = 0;
  while (c < '-') c = next_char();
  while (c >= '0') {
    ans = (ans << 1) + (ans << 3);
    ans += c - '0';
    c = next_char();
  }
  return ans;
}

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
    for (int i = 0; i < 2; i++) {
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

MinCostFlow<int, long long, 11111, 222222 > mcmf;
#define SOURCE 10001
#define SINK 10002

void solve(int test_num) {
  mcmf.init();
  int vertices, edges, src, dest;
  vertices = next_int();
  edges = next_int();
  src = next_int();
  dest = next_int();
  //scanf("%d %d %d %d", &vertices, &edges, &src, &dest);
  for (int e = 0, u, v, dist; e < edges; e++) {
    u = next_int();
    v = next_int();
    dist = next_int();
    //scanf("%d %d %d", &u, &v, &dist);
    mcmf.addedge(u, v, 1, dist);
    mcmf.addedge(v, u, 1, dist);
  }
  mcmf.addedge(SOURCE, src, 2, 0);
  mcmf.addedge(dest, SINK, 2, 0);
  pair<int, long long> ans = mcmf.go(SOURCE, SINK);
  if (ans.first != 2) puts("-1");
  else printf("%lld\n", ans.second);
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
  SPHIWAY::solve();
  return 0;
}

