/* Solved
 * 11157. The Great Escape
 * File:   GREAT_E.cpp
 * Author: Andy Y.F. Huang
 * Created on May 29, 2013, 8:51 PM
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

namespace GREAT_E {

template <class T, size_t MAX, class Comp = less<T> > struct Heap {
  T arr[MAX], *end;
  static Comp comp;

  void clear() {
    end = arr;
  }

  void push(T val) {
    *end++ = val;
    push_heap(arr, end, comp);
  }

  T top() const {
    return *arr;
  }

  void pop() {
    pop_heap(arr, end--, comp);
  }

  int size() {
    return end - arr;
  }

  bool empty() {
    return end == arr;
  }

} ;

#define INF (1 << 28)
typedef pair<int, int> Node;
Heap<Node, 400444, greater<Node> > q;
int last[111000], to[222000], next[222000], cost[222000], lim[222000];
int dist[111000];
int vertices, edges;

bool dijk(int st, int ed, int delay) {
  q.clear();
  for (int v = 0; v < vertices; v++)
    dist[v] = INF;
  q.push(Node(delay, st));
  dist[st] = delay;
  for (int at, e, cdist; !q.empty(); q.pop()) {
    at = q.top().second;
    cdist = q.top().first;
    if (at == ed) return true;
    if (cdist > dist[at]) continue;
    for (e = last[at]; ~e; e = next[e]) {
      if (cdist + cost[e] < min(lim[e], dist[to[e]])) {
        dist[to[e]] = cdist + cost[e];
        q.push(Node(dist[to[e]], to[e]));
      }
    }
  }
  return false;
}

void solve(int test_num) {
  char str[11];
  int most;
  scanf("%d %d %d", &vertices, &edges, &most);
  for (int i = 0; i < vertices; i++)
    last[i] = -1;
  for (int e = 0, a, b; e < edges; e++) {
    scanf("%d %d %d %s", &a, &b, cost + e, str);
    cost[e + edges] = cost[e];
    lim[e + edges] = lim[e] = str[0] == 'I' ? INF : atoi(str);
    to[e] = b;
    next[e] = last[a];
    last[a] = e;
    to[e + edges] = a;
    next[e + edges] = last[b];
    last[b] = e + edges;
  }
  int st, ed, ans = 0;
  scanf("%d %d", &st, &ed);
  for (int low = 1, high = most; low <= high; ) {
    int mid = (low + high) >> 1;
    if (dijk(st, ed, mid)) {
      ans = mid;
      low = mid + 1;
    }
    else high = mid - 1;
  }
  printf("Case #%d: ", test_num);
  if (ans == 0) puts("Primo can't escape");
  else printf("Primo can escape in %d minute(s)\n", ans);
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
  GREAT_E::solve();
  return 0;
}

