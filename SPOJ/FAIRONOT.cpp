/* Solved
 * 2140. (un)Fair Play
 * File:   FAIRONOT.cpp
 * Author: Andy Y.F. Huang
 * Created on April 25, 2013, 7:03 PM
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

namespace FAIRONOT {

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

#define SOURCE 2001
#define SINK 2002
MaxFlow<int, 2222, 8888 > maxflow;
int teams, matches;

void solve(int test_num) {
  maxflow.init();
  int mostpts = 0, total = 0;
  for (int i = 0, pts; i < teams; i++) {
    scanf("%d", &pts);
    maxflow.addedge(SOURCE, i, pts);
    mostpts = pts;
    total += pts;
  }
  total += 2 * matches;
  for (int e = 0, a, b; e < matches; e++) {
    scanf("%d %d", &a, &b);
    if (a != teams && b != teams) {
      maxflow.addedge(SOURCE, e + teams, 2);
      maxflow.addedge(e + teams, a - 1, 2);
      maxflow.addedge(e + teams, b - 1, 2);
    }
    else mostpts += 2;
  }
  for (int i = 0; i < teams - 1; i++)
    maxflow.addedge(i, SINK, mostpts - 1);
  int flow = maxflow.go(SOURCE, SINK);
  if (flow + mostpts == total)
    puts("YES");
  else puts("NO");
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (scanf("%d %d", &teams, &matches) != EOF)
    if (teams > 0)
      solve(1);
}
}

int main() {
  FAIRONOT::solve();
  return 0;
}

