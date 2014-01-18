/* Solved
 * 50. Invitation Cards
 * File:   INCARDS.cpp
 * Author: Andy Y.F. Huang
 * Created on May 24, 2013, 9:02 PM
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

namespace INCARDS {

template <class T, size_t MAXV, size_t MAXE> struct Graph {
  int last[MAXV], to[MAXE], pred[MAXE];
  T edge[MAXE];
  int cnt;

  void init(int size) {
    memset(last, -1, 4 * (size + 1));
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

    iterator(Graph* g, int v) : g(g), e(g->last[v]), from(v), to(e < 0 ? -1 : g->to[e]) { }

    iterator& operator++() {
      e = g->pred[e];
      to = e < 0 ? -1 : g->to[e];
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

  bool empty() {
    return end == arr;
  }

};

typedef Graph<int, 1000100, 1000100 > Grapt_t;
Grapt_t net, rev;
Grapt_t::iterator it;
int dist[1000100];
int vertices, edges;
Heap<pair<int, int>, 2000100> q;

int go(Grapt_t& g) {
  memset(dist, 0x3F, 4 * (vertices + 1));
  dist[1] = 0;
  q.clear();
  q.push(make_pair(0, 1));
  for (int at, cdist; !q.empty(); q.pop()) {
    at = q.top().second;
    cdist = -q.top().first;
    if (cdist < dist[at]) continue;
    for (it = g.begin(at); !it.end(); ++it) {
      if (cdist + *it < dist[it.to]) {
        dist[it.to] = cdist + *it;
        q.push(make_pair(-dist[it.to], it.to));
      }
    }
  }
  return accumulate(dist + 1, dist + vertices + 1, 0LL);
}

void solve(int test_num) {
  scanf("%d %d", &vertices, &edges);
  net.init(vertices);
  rev.init(vertices);
  for (int e = 0, a, b, c; e < edges; e++) {
    scanf("%d %d %d", &a, &b, &c);
    net.addedge(a, b, c);
    rev.addedge(b, a, c);
  }
  long long res = go(net);
  res += go(rev);
  printf("%lld\n", res);
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
  INCARDS::solve();
  return 0;
}

