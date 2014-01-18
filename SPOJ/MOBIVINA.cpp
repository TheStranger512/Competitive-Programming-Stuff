/*
 * Solved
 * 4485. MobiZone vs VinaGone
 * File:   MOBIVINA.cpp
 * Author: Andy Y.F. Huang
 * Created on February 27, 2013, 9:41 PM
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
namespace MOBIVINA {

template <class Flow, size_t MAXV, size_t MAXE> struct MaxFlow {
  static const Flow zero = 0;
  Flow cap[MAXE << 1], flow[MAXE << 1];
  int last[MAXV], prev[MAXV], queue[MAXV], to[MAXE << 1], next[MAXE << 1];
  int edgecnt;

  void resetflow() {
    fill(flow, flow + edgecnt, (Flow) zero);
  }

  void init() {
    memset(last, 0xFF, sizeof (last));
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

  Flow calcflow(int source, int sink) {
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

MaxFlow<int, 555, 255000 > maxflow;
#define SOURCE 501
#define SINK 502

void solve(int test_num) {
  maxflow.init();
  int ppl;
  scanf("%d", &ppl);
  for (int p = 0, cost; p < ppl; p++) {
    scanf("%d", &cost);
    maxflow.addedge(SOURCE, p, cost);
  }
  for (int p = 0, cost; p < ppl; p++) {
    scanf("%d", &cost);
    maxflow.addedge(p, SINK, cost);
  }
  for (int i = 0, cost; i < ppl; i++) {
    for (int j = 0; j < ppl; j++) {
      scanf("%d", &cost);
      maxflow.addedge(i, j, cost);
    }
  }
  printf("%d\n", maxflow.calcflow(SOURCE, SINK));
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
  MOBIVINA::solve();
  return 0;
}

