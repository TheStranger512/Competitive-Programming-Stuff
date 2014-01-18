/*
 * Solved
 * 3930. Group Partition
 * File:   MPART.cpp
 * Author: Andy Y.F. Huang
 * Created on January 20, 2013, 9:32 PM
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
#include <limits>
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
namespace MPART {

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

  Flow calcflow(int source, int sink) {
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
        if (cap[e] - flow[e] > 0 && height[to[e]] + 1 == height[at]) break;
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
          if (cap[e] - flow[e] > 0 && height[to[e]] + 1 < height[at])
            height[at] = height[to[e]] + 1, cur[at] = e;
        cnt[height[at]]++;
        if (at != source) at = to[prev[at] ^ 1];
      }
    }
    return maxflow;
  }
} ;

MaxFlow<int, 1555, 555555 > maxflow;
int friends, groups;
char buf[5555];
const char *delim = " \r\n\t";

void solve(int test_num) {
  const int src = 1501, sink = 1502;
  maxflow.init();
  for (int g = 0; g < groups; g++)
    maxflow.addedge(g, sink, 0);
  for (int n = 0; n < friends; n++) {
    gets(buf);
    char* ptr = strtok(buf, delim);
    ptr = strtok(NULL, delim);
    while (ptr != NULL) {
      int group = atoi(ptr);
      maxflow.addedge(n + groups, group, 1);
      ptr = strtok(NULL, delim);
    }
  }
  for (int f = 0; f < friends; f++)
    maxflow.addedge(src, f + groups, 1);
  int ans = friends;
  for (int low = friends / groups, high = friends; low <= high; ) {
    int mid = (low + high) >> 1;
    maxflow.resetflow();
    for (int e = 0; e < 2 * groups; e += 2)
      maxflow.cap[e] = mid;
    if (maxflow.calcflow(src, sink) == friends) {
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
  while (true) {
    scanf("%d %d ", &friends, &groups);
    if (friends == 0 && groups == 0)
      break;
    solve(1);
  }
}
}

int main() {
  MPART::solve();
  return 0;
}

