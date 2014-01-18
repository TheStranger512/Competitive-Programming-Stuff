/* Solved
 * 3007. Oil Company
 * File:   OILCOMP.cpp
 * Author: Andy Y.F. Huang
 * Created on June 2, 2013, 1:32 PM
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

namespace OILCOMP {

template <class Flow, size_t MAXV, size_t MAXE> struct MaxFlow {
  static const Flow zero = 0;
  Flow cap[MAXE << 1], flow[MAXE << 1];
  int last[MAXV], prev[MAXV], queue[MAXV], to[MAXE << 1], next[MAXE << 1];
  int edgecnt;

  void resetflow() {
    fill(flow, flow + edgecnt, (Flow) zero);
  }

  void init() {
    memset(last, -1, sizeof (last));
    edgecnt = 0;
  }

  void addedge(int start, int end, Flow capacity, bool directed = true) {
    //pln(start, end);
    flow[edgecnt] = flow[edgecnt ^ 1] = zero;
    to[edgecnt] = end;
    cap[edgecnt] = capacity;
    next[edgecnt] = last[start];
    last[start] = edgecnt++;
    to[edgecnt] = start;
    cap[edgecnt] = directed ? zero : capacity;
    next[edgecnt] = last[end];
    last[end] = edgecnt++;
  }

  Flow go(int source, int sink) {
    Flow maxflow = zero;
    while (true) {
      memset(prev, 0xFF, sizeof (prev));
      int qf = 0, qb = 0;
      Flow total = zero;
      prev[queue[qb++] = source] = -2;
      while (qf < qb)
        for (int cur = queue[qf++], i = last[cur]; i != -1; i = next[i])
          if (prev[to[i]] == -1 && flow[i] < cap[i])
            prev[queue[qb++] = to[i]] = i;
      if (prev[sink] == -1) break;
      for (int i = last[sink]; i != -1; i = next[i]) {
        if (prev[to[i]] == -1) continue;
        Flow minflow = cap[i ^ 1] - flow[i ^ 1];
        for (int e = i ^ 1; e >= 0; e = prev[to[e ^ 1]])
          minflow = min(minflow, cap[e] - flow[e]);
        if (minflow == zero) continue;
        for (int e = i ^ 1; e >= 0; e = prev[to[e ^ 1]])
          flow[e] += minflow, flow[e ^ 1] -= minflow;
        total += minflow;
      }
      maxflow += total;
    }
    //pln(maxflow);
    return maxflow;
  }

} ;

#define INF 13371337
#define SRC 410
#define SINK 411
MaxFlow<int, 444, 2222 > net;

void solve(int test_num) {
  net.init();
  int width, height, total = 0;
  scanf("%d %d", &width, &height);
  for (int r = 0; r < height; r++) {
    for (int c = 0, oil; c < width; c++) {
      scanf("%d", &oil);
      total += oil;
      if ((r + c) & 1)
        net.addedge(r * width + c, SINK, oil);
      else
        net.addedge(SRC, r * width + c, oil);
    }
  }
  for (int r = 0; r < height; r++) {
    for (int c = r & 1; c < width; c += 2) {
      int cur = r * width + c;
      if (r - 1 >= 0)
        net.addedge(cur, cur - width, INF);
      if (r + 1 < height)
        net.addedge(cur, cur + width, INF);
      if (c - 1 >= 0)
        net.addedge(cur, cur - 1, INF);
      if (c + 1 < width)
        net.addedge(cur, cur + 1, INF);
    }
  }
  int res = total - net.go(SRC, SINK);
  printf("Case %d: %d\n", test_num, res);
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
  OILCOMP::solve();
  return 0;
}

