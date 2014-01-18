/* Solved
 * 51. Fake tournament
 * File:   TOUR.cpp
 * Author: Andy Y.F. Huang
 * Created on May 24, 2013, 9:35 PM
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

namespace TOUR {

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

typedef Graph<bool, 1111, 500555 > ::iterator Iter;
Graph<bool, 1111, 500555 > net, rev;
bool vis[1111], indeg[1111];
int comp[1111], size[1111];
int cur;
stack<int> s;

void dfs1(int at) {
  if (vis[at]) return;
  vis[at] = true;
  for (Iter e = net.begin(at); !e.end(); ++e)
    dfs1(e.to);
  s.push(at);
}

void dfs2(int at) {
  if (~comp[at])
    return;
  comp[at] = cur;
  size[cur]++;
  for (Iter e = rev.begin(at); !e.end(); ++e)
    dfs2(e.to);
}

void solve(int test_num) {
  net.init();
  rev.init();
  memset(vis, false, sizeof (vis));
  memset(indeg, false, sizeof (indeg));
  memset(comp, -1, sizeof (comp));
  memset(size, 0, sizeof (size));
  cur = 0;
  int ppl;
  scanf("%d", &ppl);
  for (int i = 1, deg, to; i <= ppl; i++) {
    scanf("%d", &deg);
    for (int j = 0; j < deg; j++) {
      scanf("%d", &to);
      net.addedge(to, i, false);
      rev.addedge(i, to, false);
    }
  }
  for (int i = 1; i <= ppl; i++)
    dfs1(i);
  for (; !s.empty(); s.pop()) {
    if (!~comp[s.top()]) {
      dfs2(s.top());
      cur++;
    }
  }
  //plnarr(comp, comp + ppl + 1);
  for (int i = 1; i <= ppl; i++)
    for (Iter e = net.begin(i); !e.end(); ++e)
      if (comp[e.from] != comp[e.to])
        indeg[comp[e.to]] = true;
  if (count(indeg, indeg + cur, false) > 1)
    puts("0");
  else
    for (int i = 0; i < cur; i++)
      if (!indeg[i])
        printf("%d\n", size[i]);
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
  TOUR::solve();
  return 0;
}

