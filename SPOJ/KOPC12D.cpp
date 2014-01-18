/* Solved
 * 10517. K12-Generating Big Numbers II
 * File:   KOPC12D.cpp
 * Author: Andy Y.F. Huang
 * Created on May 29, 2013, 8:42 PM
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

namespace KOPC12D {

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
    return maxflow;
  }

} ;

#define SRC 201
#define SINK 202
MaxFlow<int, 222, 2222 > net;

void solve(int test_num) {
  net.init();
  int total = 0;
  for (int i = 2, cnt; i <= 9; i++) {
    scanf("%d", &cnt);
    net.addedge(SRC, i, cnt);
    total += cnt;
  }
  for (int d = 2; d <= 9; d++)
    for (int i = 1; i <= 160; i++)
      if (i % d != 0)
        net.addedge(d, i + 10, 1);
  for (int res = 1; ; res++) {
    net.addedge(res + 10, SINK, 1);
    total -= net.go(SRC, SINK);
    if (total == 0) {
      printf("%d\n", res);
      break;
    }
  }
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
  KOPC12D::solve();
  return 0;
}

