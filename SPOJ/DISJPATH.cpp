/* Solved
 * 3579. Disjoint Paths
 * File:   DISJPATH.cpp
 * Author: Andy Y.F. Huang
 * Created on January 2, 2013, 1:55 AM
 */

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <iomanip>
#include <cassert>
#include <ctime>
#include <functional>
#include <complex>
#include <numeric>
#include <cctype>
#include <cstddef>
#include <utility>
#include <valarray>
#include <cstdlib>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace DISJPATH {

template <class T> struct MaxFlow {
  #define MAXV 1111
  #define MAXE 55555
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

MaxFlow<int> maxflow;
int needed, vertices;
char buf[11111];
int prev[1111];
int path[555], q[1111];
bool mark[1111];

void solve(int test_num) {
  const int sink = 2;
  maxflow.init();
  for (int v = 3; v <= vertices; v++)
    maxflow.addedge(v, v + vertices, 1);
  for (int v = 1; v <= vertices; v++) {
    scanf("%[^\r\n]\r\n", buf);
    for (char* ptr = strtok(buf, " \r\t\n"); ptr != NULL; ptr = strtok(NULL, " \r\t\n")) {
      int to = atoi(ptr);
      if (to < v) continue;
      maxflow.addedge(v + vertices, to, 1);
      maxflow.addedge(to + vertices, v, 1);
    }
  }
  printf("Case %d:\n", test_num);
  if (maxflow.dinics(1 + vertices, sink) < needed)
    puts("Impossible");
  else {
    const int *last = maxflow.last, *next = maxflow.next, *to = maxflow.to;
    const int *cap = maxflow.cap, *flow = maxflow.flow;
    memset(mark, false, sizeof (mark));
    for (int i = 0; i < needed; i++) {
      int qf = 0, qb = 0, pathlen = 0;
      q[qb++] = 1 + vertices;
      mark[sink] = false;
      memset(prev, 0xFF, sizeof (prev));
      prev[1 + vertices] = -2;
      for (; qf < qb && prev[sink] == -1; qf++)
        for (int cur = q[qf], id = last[cur]; id != -1; id = next[id])
          if (prev[to[id]] == -1 && !mark[to[id]] && cap[id] - flow[id] == 0) {
            if ((cur <= vertices && to[id] == cur + vertices) || (cur > vertices))
              prev[q[qb++] = to[id]] = cur;
          }
      for (int cur = sink; cur > 0; cur = prev[cur])
        if (cur <= vertices)
          mark[path[pathlen++] = cur] = true;
      printf("%d", 1);
      for (int i = pathlen - 1; i >= 0; i--)
        printf(" %d", path[i]);
      putchar('\n');
    }
  }
  puts("");
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  for (int i = 1; ; i++) {
    scanf("%d %d\r\n", &needed, &vertices);
    if (needed == 0) break;
    solve(i);
  }
}
}

int main() {
  DISJPATH::solve();
  return 0;
}


