/* Solved
 * 7737. Escape
 * File:   BOI7ESC.cpp
 * Author: Andy Y.F. Huang
 * Created on February 15, 2013, 11:09 PM
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
namespace BOI7ESC {

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

#define LIM 100
#define sqr(x) ((x)*(x))
MaxFlow<int, 555, 222222 > maxflow;
int x[255], y[255];

void solve(int test_num) {
  const int sink = 522, src = 0;
  maxflow.init();
  int length, width, cnt;
  scanf("%d %d %d", &length, &width, &cnt);
  for (int i = 1; i <= cnt; i++)
    scanf("%d %d", x + i, y + i);
  for (int i = 1; i <= cnt; i++) {
    if (y[i] <= LIM)
      maxflow.addedge(src, i, 1);
    if (width - y[i] <= LIM)
      maxflow.addedge(i + cnt, sink, 1);
    maxflow.addedge(i, i + cnt, 1);
    for (int j = i + 1; j <= cnt; j++) {
      if (sqr(1LL * x[i] - x[j]) + sqr(1LL * y[i] - y[j]) <= 40000) {
        maxflow.addedge(i + cnt, j, 1111);
        maxflow.addedge(j + cnt, i, 1111);
      }
    }
  }
  printf("%d\n", maxflow.calcflow(src, sink));
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
  BOI7ESC::solve();
  return 0;
}

