/* Solved
 * 6052. PBCGAME
 * File:   PBCGAME.cpp
 * Author: Andy Y.F. Huang
 * Created on January 5, 2013, 1:07 AM
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
namespace PBCGAME {

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

MaxFlow<int, 500, 10000 > maxflow;

void solve(int test_num) {
  maxflow.init();
  const int source = 498, sink = 499;
  int starts, mids, ends;
  scanf("%d %d %d", &starts, &mids, &ends);
  for (int i = 1; i <= starts; i++)
    maxflow.addedge(source, i, 1);
  for (int i = 1; i <= ends; i++)
    maxflow.addedge(i + starts + mids, sink, 1);
  int total = starts + mids + ends;
  for (int i = 1; i <= mids; i++) {
    int cap;
    scanf("%d", &cap);
    maxflow.addedge(i + starts, i + total, cap);
  }
  for (int i = 1; i <= starts; i++) {
    int deg;
    scanf("%d", &deg);
    for (int d = 0; d < deg; d++) {
      int adj;
      scanf("%d", &adj);
      maxflow.addedge(i, adj, 1);
    }
  }
  for (int i = 1; i <= mids; i++) {
    int deg;
    scanf("%d", &deg);
    for (int d = 0; d < deg; d++) {
      int adj;
      scanf("%d", &adj);
      maxflow.addedge(i + total, adj, 1 << 20);
    }
  }
  printf("%d\n", maxflow.dinics(source, sink));
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve(1);
}
}

int main() {
  PBCGAME::solve();
  return 0;
}

