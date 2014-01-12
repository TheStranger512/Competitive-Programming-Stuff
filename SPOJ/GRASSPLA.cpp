/* Solved
 * 12005. Grass Planting
 * File:   GRASSPLA.cpp
 * Author: Andy Y.F. Huang
 * Created on April 25, 2013, 10:17 PM
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

namespace GRASSPLA {

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

#define MAX 100100
#define lch(x) (x<<1)
#define rch(x) (x<<1|1)
#define mid ((l+r)>>1)
typedef Graph<bool, MAX, 2 * MAX> Graph_t;
typedef Graph_t::iterator Iter;
typedef long long llong;
Graph_t gra;
int par[17][MAX], top[MAX], size[MAX], pos[MAX], timein[MAX], timeout[MAX];
llong fenw[MAX];
int len, maxlog;

void update_fenw(int l, int r) {
  for (int i = l; i <= len; i += i&-i)
    fenw[i]++;
  for (int i = r + 1; i <= len; i += i&-i)
    fenw[i]--;
}

llong query_fenw(int pos) {
  llong res = 0;
  for (int i = pos; i > 0; i -= i&-i)
    res += fenw[i];
  return res;
}

static int next_time() {
  static int T = 0;
  return ++T;
}

static int next_pos() {
  static int P = 0;
  return ++P;
}

bool isanc(int a, int b) {
  return timein[a] <= timein[b] && timeout[b] <= timeout[a];
}

int getlca(int a, int b) {
  if (isanc(a, b)) return a;
  for (int i = maxlog; i >= 0; i--)
    if (!isanc(par[i][a], b))
      a = par[i][a];
  return par[0][a];
}

void update(int a, int b) {
  //b is ancestor of a
  while (top[a] != top[b]) {
    update_fenw(pos[top[a]], pos[a]);
    a = par[0][top[a]];
  }
  if (pos[b] <= pos[a])
    update_fenw(pos[b] + 1, pos[a]);
}

void dfs1(int at) {
  timein[at] = next_time();
  size[at] = 1;
  for (Iter e = gra.begin(at); !e.end(); ++e) {
    if (e.to != par[0][at]) {
      par[0][e.to] = at;
      dfs1(e.to);
      size[at] += size[e.to];
    }
  }
  timeout[at] = next_time();
}

void dfs2(int at, int ctop) {
  top[at] = ctop;
  pos[at] = next_pos();
  int heavy = -1;
  for (Iter e = gra.begin(at); !e.end(); ++e)
    if (e.to != par[0][at] && (heavy == -1 || size[e.to] > size[heavy]))
      heavy = e.to;
  if (heavy == -1) return;
  dfs2(heavy, ctop);
  for (Iter e = gra.begin(at); !e.end(); ++e)
    if (e.to != par[0][at] && e.to != heavy)
      dfs2(e.to, e.to);
}

void solve(int test_num) {
  memset(fenw, 0, sizeof (fenw));
  int quests;
  scanf("%d %d", &len, &quests);
  gra.init();
  for (int i = 1, a, b; i < len; i++) {
    scanf("%d %d", &a, &b);
    gra.addedge(a, b, 0);
    gra.addedge(b, a, 0);
  }
  par[0][1] = 1;
  maxlog = 0;
  while ((1 << (maxlog + 1)) <= len)
    maxlog++;
  dfs1(1);
  dfs2(1, 1);
  //plnarr(par[0] + 1, par[0] + len + 1);
  //plnarr(pos + 1, pos + len + 1);
  //plnarr(top + 1, top + len + 1);
  for (int j = 1; j <= maxlog; j++)
    for (int i = 1; i <= len; i++)
      par[j][i] = par[j - 1][par[j - 1][i]];
  for (int q = 0, a, b; q < quests; q++) {
    char type;
    scanf(" %c %d %d", &type, &a, &b);
    int lca = getlca(a, b);
    //pln(a, b, lca);
    if (type == 'P') {
      update(a, lca);
      update(b, lca);
    }
    else {
      printf("%lld\n", query_fenw(isanc(a, b) ? pos[b] : pos[a]));
    }
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  solve(1);
}
}

int main() {
  GRASSPLA::solve();
  return 0;
}

