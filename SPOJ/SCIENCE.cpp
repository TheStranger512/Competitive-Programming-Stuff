/* Solved
 * 14387. Science
 * File:   SCIENCE.cpp
 * Author: Andy Y.F. Huang
 * Created on May 27, 2013, 5:56 PM
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

namespace SCIENCE {

template <size_t MAXL, size_t MAXR> struct BipartiteMatcher {
  #define NIL MAXL
  static const int INF = 13371337;
  int matchleft[MAXL + 1], matchright[MAXR], leftcnt, rightcnt;
  bool adj[MAXL][MAXR];
  int dist[MAXL + 1], queue[MAXL];

  void init(int boys, int girls) {
    memset(adj, false, sizeof (adj));
    leftcnt = boys;
    rightcnt = girls;
  }

  bool bfs() {
    int qf = 0, qb = 0;
    for (int v = 0; v < leftcnt; v++)
      if (matchleft[v] == NIL)
        dist[queue[qb++] = v] = 0;
      else dist[v] = INF;
    for (dist[NIL] = INF; qf < qb; qf++)
      for (int at = queue[qf], to = 0; to < rightcnt; to++)
        if (adj[at][to] && dist[matchright[to]] == INF)
          dist[queue[qb++] = matchright[to]] = dist[at] + 1;
    return dist[NIL] != INF;
  }

  bool dfs(int at) {
    if (at == NIL) return true;
    for (int to = 0; to < rightcnt; to++)
      if (adj[at][to] && dist[matchright[to]] == dist[at] + 1 && dfs(matchright[to])) {
        matchleft[at] = to;
        matchright[to] = at;
        return true;
      }
    dist[at] = INF;
    return false;
  }

  int go() {
    fill(matchleft, matchleft + leftcnt, NIL);
    fill(matchright, matchright + rightcnt, NIL);
    int matches = 0;
    while (bfs())
      for (int v = 0; v < leftcnt; v++)
        if (matchleft[v] == NIL && dfs(v))
          matches++;
    return matches;
  }
} ;

template <class Flow, size_t MAXV, size_t MAXE> struct MaxFlow {
  Flow cap[MAXE << 1], flow[MAXE << 1], limit[MAXV];
  int last[MAXV], to[MAXE << 1], next[MAXE << 1];
  int prev[MAXV], cur[MAXV], height[MAXV], cnt[MAXV + 1];
  int edgecnt, vertices;

  void resetflow() {
    fill(flow, flow + edgecnt, 0);
  }

  void init() {
    memset(last, -1, sizeof (last));
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

BipartiteMatcher < 211, 211 > bpm;
MaxFlow<int, 444, 44444 > net;
char str[222];
int size;
int src, sink;

void solve(int test_num) {
  net.init();
  scanf("%d", &size);
  src = size + size, sink = src + 1;
  for (int i = 0; i < size; i++)
    net.addedge(src, i, 0);
  for (int j = 0; j < size; j++)
    net.addedge(j + size, sink, 0);
  for (int i = 0; i < size; i++) {
    scanf("%s", str);
    for (int j = 0; j < size; j++)
      if (str[j] == 'Y')
        net.addedge(i, j + size, 1);
  }
  int res = 0;
  for (int it = 1; it <= size; it++) {
    for (int e = 0; e < 4 * size; e += 2)
      net.cap[e]++;
    if (net.go(src, sink) == size)
      res++;
    else break;
  }
  if (res == 0) {
    puts("NO SCIENCE");
    return;
  }
  for (int e = 0; e < 4 * size; e += 2)
    net.cap[e] = res;
  net.resetflow();
  net.go(src, sink);
  bpm.init(size, size);
  for (int i = 0; i < size; i++)
    for (int e = net.last[i]; ~e; e = net.next[e])
      if (net.to[e] < src && net.flow[e] == 1)
        bpm.adj[i][net.to[e] - size] = true;
  printf("%d\n", res);
  for (int i = 0; i < res; i++) {
    bpm.go();
    for (int j = 0; j < size; j++) {
      printf("%d ", bpm.matchright[j] + 1);
      bpm.adj[bpm.matchright[j]][j] = false;
    }
    putchar('\n');
  }
}

void makecase() {
  freopen("input.txt", "w", stdout);
  printf("%d\n", 200);
  for (int i = 0; i < 200; i++, putchar('\n'))
    for (int j = 0; j < 200; j++)
      putchar('Y');
}

void solve() {
  #ifdef AZN
  //makecase();
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  solve(1);
}
}

int main() {
  SCIENCE::solve();
  return 0;
}


