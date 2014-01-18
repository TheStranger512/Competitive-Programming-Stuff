/* Solved
 * 1476. Maximum Profit
 * File:   PROFIT.cpp
 * Author: Andy Y.F. Huang
 * Created on April 21, 2013, 1:21 AM
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

namespace PROFIT {

template <class Flow, size_t MAXV, size_t MAXE> struct MaxFlow {
  Flow cap[MAXE << 1], flow[MAXE << 1], limit[MAXV];
  int last[MAXV], to[MAXE << 1], next[MAXE << 1];
  int prev[MAXV], cur[MAXV], height[MAXV], cnt[MAXV + 1];
  int edgecnt, vertices;

  void resetflow() {
    fill(flow, flow + edgecnt, 0);
  }

  void init(int size) {
    memset(last, -1, sizeof (int) * (size + 1));
    vertices = edgecnt = 0;
  }

  void _addedge(int a, int b, Flow c) {
    flow[edgecnt] = 0;
    to[edgecnt] = b;
    cap[edgecnt] = c;
    next[edgecnt] = last[a];
    if (last[a] == -1) vertices++;
    last[a] = edgecnt++;
  }

  void addedge(int start, int end, Flow capacity, bool directed = true) {
    _addedge(start, end, capacity);
    _addedge(end, start, directed ? 0 : capacity);
  }

  Flow go(int source, int sink) {
    const Flow INF = numeric_limits<Flow>::max();
    Flow maxflow = 0;
    memset(prev, -1, sizeof (prev));
    memset(cur, -1, sizeof (cur));
    memset(height, 0, sizeof (height));
    memset(cnt, 0, sizeof (cnt));
    fill(limit, limit + MAXV, 0);
    cnt[0] = vertices;
    int at = source, e = -1;
    limit[at] = INF;
    while (height[source] < vertices) {
      for (e = cur[at]; e > -1; e = next[e])
        if (flow[e] < cap[e] && height[to[e]] + 1 == height[at]) break;
      if (e > -1) {
        cur[at] = prev[to[e]] = e;
        limit[to[e]] = min(limit[at], cap[e] - flow[e]);
        at = to[e];
        if (at == sink)
          for (maxflow += limit[sink]; at != source; at = to[prev[at] ^ 1])
            flow[prev[at]] += limit[sink], flow[prev[at] ^ 1] -= limit[sink];
      }
      else {
        if (--cnt[height[at]] == 0) break;
        height[at] = vertices;
        for (e = last[at]; e > -1; e = next[e])
          if (flow[e] < cap[e] && height[to[e]] + 1 < height[at])
            height[at] = height[to[e]] + 1, cur[at] = e;
        cnt[height[at]]++;
        if (at != source) at = to[prev[at] ^ 1];
      }
    }
    return maxflow;
  }
} ;

#define SOURCE 55200
#define SINK 55211
MaxFlow<int, 55555, 166666 > maxflow;

void solve(int test_num) {
  int cities, calls;
  scanf("%d %d", &cities, &calls);
  maxflow.init(cities + calls + 5);
  maxflow.last[SOURCE] = -1;
  maxflow.last[SINK] = -1;
  for (int i = 1, cost; i <= cities; i++) {
    scanf("%d", &cost);
    maxflow.addedge(SOURCE, i, cost);
  }
  int total = 0;
  for (int i = 1, a, b, gain; i <= calls; i++) {
    scanf("%d %d %d", &a, &b, &gain);
    maxflow.addedge(a, i + cities, 111);
    maxflow.addedge(b, i + cities, 111);
    maxflow.addedge(i + cities, SINK, gain);
    total += gain;
  }
  total -= maxflow.go(SOURCE, SINK);
  printf("%d\n", total);
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
  PROFIT::solve();
  return 0;
}

