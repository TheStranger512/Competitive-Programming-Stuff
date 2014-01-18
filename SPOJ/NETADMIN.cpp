/* Solved
 * 287. Smart Network Administrator
 * File:   NETADMIN.cpp
 * Author: Andy Y.F. Huang
 * Created on February 18, 2013, 12:33 PM
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
namespace NETADMIN {

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

  T calcflow(int source, int sink) {
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

MaxFlow<int, 511, 255555 > maxflow;

void solve(int test_num) {
  const int sink = 502;
  maxflow.init();
  int vertices, edges, need;
  scanf("%d %d %d", &vertices, &edges, &need);
  for (int i = 0, house; i < need; i++) {
    scanf("%d", &house);
    maxflow.addedge(house, sink, 1);
  }
  for (int e = 0, a, b; e < edges; e++) {
    scanf("%d %d", &a, &b);
    maxflow.addedge(a, b, need, false);
  }
  int ans = need;
  for (int low = 1, high = need, mid; low <= high; ) {
    mid = (low + high) >> 1;
    maxflow.resetflow();
    for (int e = 2 * need; e < maxflow.edgecnt; e++)
      maxflow.cap[e] = mid;
    if (maxflow.calcflow(1, sink) == need) {
      ans = min(ans, mid);
      high = mid - 1;
    }
    else low = mid + 1;
  }
  printf("%d\n", ans);
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
  NETADMIN::solve();
  return 0;
}

