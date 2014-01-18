/*
 * Solved
 * 4457. Shopping II - max flow
 * File:   SHOP2.cpp
 * Author: Andy Y.F. Huang
 * Created on August 17, 2012, 9:32 PM
 */

#include <cstdio>
#include <algorithm>
#include <limits>
#include <cstring>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace SHOP2 {
const unsigned int buffer_size = 1 << 16;
char input_buffer[buffer_size];
unsigned int bytes_read = 0;
unsigned int input_index = 0;

inline char next_char() {
  if (input_index == bytes_read) {
    bytes_read = fread(input_buffer, sizeof (char) , buffer_size, stdin);
    input_buffer[bytes_read] = '\0'; //sentinel
    input_index = 0;
  }
  return input_buffer[input_index++];
}

inline int next_int() {
  char c;
  while (c < '0')
    c = next_char();
  int ans = 0;
  while (c >= '0') {
    ans = (ans << 1) + (ans << 3);
    ans += c - '0';
    c = next_char();
  }
  return ans;
}

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
    //Thanks WJMZBMR
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


MaxFlow<int, 4010, 450000> maxflow;

void solve(int test_num) {
  int items = next_int(), coupons = next_int(), total = 0;
  const int source = items + coupons, sink = source + 1, inf = 12345;
  maxflow.init();
  for (int i = 0; i < items; i++) {
    int price = next_int();
    maxflow.addedge(i, sink, price);
    total += price;
  }
  for (int i = 0; i < coupons; i++) {
    int value = next_int();
    maxflow.addedge(source, i + items, value);
  }
  for (int i = 0; i < coupons; i++) {
    int deg = next_int();
    while (deg-- > 0) {
      int item = next_int();
      maxflow.addedge(i + items, --item, inf);
    }
  }
  printf("%d\n", total - maxflow.calcflow(source, sink));
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests = next_int();
  for (int i = 1; i <= tests; i++)
    solve(1);
}
}

int main() {
  SHOP2::solve();
  return 0;
}

