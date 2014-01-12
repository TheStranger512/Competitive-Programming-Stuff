/* Solved
 * 839. Optimal Marks
 * File:   OPTM.cpp
 * Author: Andy Y.F. Huang
 * Created on April 24, 2013, 11:18 PM
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

namespace OPTM {

template <class T, size_t MAXV, size_t MAXE> struct Graph {
  int last[MAXV], to[MAXE], pred[MAXE];
  T edge[MAXE];
  int cnt;

  void init() {
    memset(last, -1, sizeof (last));
    cnt = 0;
  }

  void addedge(int a, int b, const T & c) {
    to[cnt] = b;
    edge[cnt] = c;
    pred[cnt] = last[a];
    last[a] = cnt++;
  }

  class iterator {
    Graph* g;
    int e;
  public:
    int from, to;

    iterator() : g(NULL), e(-1), from(-1), to(-1) { }

    iterator(Graph* g, int v) : g(g), e(g->last[v]), from(v), to(g->to[e]) { }

    iterator& operator++() {
      e = g->pred[e];
      to = g->to[e];
      return *this;
    }

    bool end() {
      return e == -1;
    }

    T* operator->() {
      return &(g->edge[e]);
    }

    T& operator*() {
      return (g->edge[e]);
    }

  } ;

  iterator begin(int v) {
    return iterator(this, v);
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

  void getcut(int src, bool* vis) {
    static int queue[MAXV];
    int qf = 0, qb = 0;
    queue[qb++] = src;
    vis[src] = true;
    for (; qf < qb; qf++)
      for (int e = last[queue[qf]]; e > -1; e = next[e])
        if (!vis[to[e]] && flow[e] < cap[e])
          vis[queue[qb++] = to[e]] = true;
  }

} ;

#define SOURCE 510
#define SINK 511
#define INF (1 << 28)
Graph<int, 555, 6666 > gra;
Graph<int, 555, 6666 > ::iterator it;
MaxFlow<int, 555, 11111 > maxflow;
bool have[555], vis[555];
int mark[555];

void solve(int test_num) {
  memset(have, false, sizeof (have));
  memset(mark, 0, sizeof (mark));
  gra.init();
  int vertices, edges;
  scanf("%d %d", &vertices, &edges);
  for (int e = 0, a, b; e < edges; e++) {
    scanf("%d %d", &a, &b);
    gra.addedge(a, b, -1);
  }
  int havecnt;
  scanf("%d", &havecnt);
  for (int i = 0, v; i < havecnt; i++) {
    scanf("%d", &v);
    scanf("%d", mark + v);
    have[v] = true;
  }
  for (int bit = 0; bit < 31; bit++) {
    maxflow.init();
    //dbgln(bit);
    for (int v = 1; v <= vertices; v++) {
      //pln(1 << bit & mark[v]);
      for (it = gra.begin(v); !it.end(); ++it)
        maxflow.addedge(v, it.to, 1, false);
      if (have[v]) {
        if (1 << bit & mark[v]) maxflow.addedge(SOURCE, v, INF);
        else maxflow.addedge(v, SINK, INF);
      }
    }
    maxflow.go(SOURCE, SINK);
    memset(vis, false, sizeof (vis));
    maxflow.getcut(SOURCE, vis);
    //dbgln(flow);
    //plnarr(vis + 1, vis + 4);
    //pln();
    for (int v = 1; v <= vertices; v++)
      if (!have[v] && vis[v])
        mark[v] |= 1 << bit;
  }
  for (int v = 1; v <= vertices; v++)
    printf("%d\n", mark[v]);
  //  int res = 0;
  //  for (int v = 1; v <= vertices; v++)
  //    for (it = gra.begin(v); !it.end(); ++it)
  //      res += mark[v] ^ mark[it.to];
  //  pln(res);
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
  OPTM::solve();
  return 0;
}

