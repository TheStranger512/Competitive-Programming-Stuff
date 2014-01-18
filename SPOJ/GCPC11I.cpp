/*
 * Solved
 * 9125. Suiting Weavers
 * File:   GCPC11I.cpp
 * Author: Andy Y.F. Huang
 * Created on January 19, 2013, 5:44 PM
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
namespace GCPC11I {

template <class T, size_t MAXV, size_t MAXE> struct MaxFlow {
  static const T zero = 0;
  T cap[MAXE << 1], flow[MAXE << 1];
  int last[MAXV], prev[MAXV], queue[MAXV], to[MAXE << 1], next[MAXE << 1];
  int edgecnt;

  void resetflow() {
    fill(flow, flow + edgecnt, (T) zero);
  }

  void init() {
    memset(last, 0xFF, sizeof (last));
    edgecnt = 0;
  }

  void addedge(int start, int end, T capacity, bool directed = true) {
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

  T dinics(int source, int sink) {
    T maxflow = zero;
    while (true) {
      memset(prev, 0xFF, sizeof (prev));
      int qf = 0, qb = 0;
      T total = zero;
      prev[queue[qb++] = source] = -2;
      while (qf < qb)
        for (int cur = queue[qf++], i = last[cur]; i != -1; i = next[i])
          if (prev[to[i]] == -1 && cap[i] - flow[i] > zero)
            prev[queue[qb++] = to[i]] = i;
      if (prev[sink] == -1) break;
      for (int i = last[sink]; i != -1; i = next[i]) {
        if (prev[to[i]] == -1) continue;
        T minflow = cap[i ^ 1] - flow[i ^ 1];
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

#define INF (1 << 28)
#define sqr(x) (x) * (x)
MaxFlow<int, 550, 44444 > maxflow;
int nestx[111], nesty[111], have[111], radius[111];

void solve(int test_num) {
  maxflow.init();
  const int source = 501, sink = 502;
  int weavers, fibers, total = 0;
  scanf("%d %d", &weavers, &fibers);
  for (int w = 0; w < weavers; w++) {
    scanf("%d %d %d %d", &nestx[w], &nesty[w], &have[w], &radius[w]);
    radius[w] *= radius[w];
    total += have[w];
  }
  int canget = have[0];
  for (int f = 0; f < fibers; f++) {
    int x, y, cnt;
    scanf("%d %d %d", &x, &y, &cnt);
    maxflow.addedge(source, f, cnt);
    total += cnt;
    bool can = false;
    for (int w = 0; w < weavers; w++)
      if (sqr(x - nestx[w]) + sqr(y - nesty[w]) <= radius[w]) {
        can = true;
        if (w == 0) {
          canget += cnt;
          break;
        }
        maxflow.addedge(f, w + fibers, INF);
      }
    if (!can) total -= cnt;
  }
  for (int w = 1; w < weavers; w++) {
    maxflow.addedge(source, w + fibers, have[w]);
    maxflow.addedge(w + fibers, sink, canget);
  }
  int flow = maxflow.dinics(source, sink);
  if (flow + canget == total) puts("Suiting Success");
  else puts("Lonesome Willy");
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
  GCPC11I::solve();
  return 0;
}

