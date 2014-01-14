/* Solved
 * IOI '07 - Zagreb, Croatia
 * Training
 * File:   ioi0723.cpp
 * Author: Andy Y.F. Huang
 * Created on June 25, 2013, 2:46 PM
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

namespace ioi0723 {
int V, E, paved;
vector<int> g[1011];
vector<int> adj[1011];
vector<int> postord;
vector<int> edges[1011]; //edges with lca = x
int from[5055], to[5055], cost[5055];
int par[10][1011], depth[1011];
int f[1011][1111]; //max weight of edges with edges in MASK deleted
int addcost[5055]; //max weight of edges added on the path from from[e] to to[e]
int chmask[5055]; //children deleted using edge e

inline int size(const vector<int>& x) {
  return x.size();
}

int getchpos(int at, int ch) {
  int res = find(adj[at].begin(), adj[at].end(), ch) - adj[at].begin();
  //assert(res < size(adj[at]));
  return res;
}

int getdescpos(int at, int x) {
  for (int i = 9; i >= 0; i--)
    if (depth[par[i][x]] > depth[at])
      x = par[i][x];
  return getchpos(at, x);
}

int getcost(int at, int x) {
  if (x == at) return 0;
  int res = f[x][0];
  while (par[0][x] != at) {
    int pa = par[0][x];
    res += f[pa][1 << getchpos(pa, x)];
    x = pa;
  }
  return res;
}

int getlca(int a, int b) {
  if (depth[a] < depth[b]) swap(a, b);
  for (int i = 9; ~i; i--)
    if (depth[par[i][a]] >= depth[b])
      a = par[i][a];
  if (a == b) return a;
  for (int i = 9; ~i; i--)
    if (par[i][a] != par[i][b])
      a = par[i][a], b = par[i][b];
  return par[0][a];
}

void dfs(int at) {
  for (int i = 0; i < size(g[at]); i++) {
    int v = g[at][i];
    if (v != par[0][at]) {
      adj[at].push_back(v);
      par[0][v] = at;
      depth[v] = depth[at] + 1;
      dfs(v);
    }
  }
  postord.push_back(at);
}

void solve(int test_num) {
  scanf("%d %d", &V, &E);
  paved = 0;
  int total = 0;
  for (int e = 0, a, b, c; e < E; e++) {
    scanf("%d %d %d", &a, &b, &c);
    if (c == 0) {
      g[a].push_back(b);
      g[b].push_back(a);
    }
    else {
      from[paved] = a;
      to[paved] = b;
      cost[paved++] = c;
      total += c;
    }
  }
  par[0][1] = 1;
  depth[1] = 0;
  dfs(1);
  for (int j = 1; j < 10; j++)
    for (int i = 1; i <= V; i++)
      par[j][i] = par[j - 1][par[j - 1][i]];
  for (int e = 0; e < paved; e++) {
    int lca = getlca(from[e], to[e]);
    if ((depth[from[e]] + depth[to[e]] - 2 * depth[lca]) % 2 == 0) {
      //pln(from[e], to[e], lca);
      edges[lca].push_back(e);
    }
  }
  for (int i = 0; i < V; i++) {
    int at = postord[i];
    int deg = size(adj[at]);
    for (int j = 0; j < size(edges[at]); j++) {
      int e = edges[at][j];
      addcost[e] = getcost(at, from[e]) + getcost(at, to[e]) + cost[e];
      if (to[e] != at)
        chmask[e] = 1 << getdescpos(at, to[e]);
      if (from[e] != at)
        chmask[e] |= 1 << getdescpos(at, from[e]);
    }
    for (int mask = (1 << deg) - 1; ~mask; mask--) {
      f[at][mask] = 0;
      for (int b = 0; b < deg; b++)
        if (1 << b & ~mask)
          f[at][mask] += f[adj[at][b]][0];
      for (int j = 0; j < size(edges[at]); j++) {
        int e = edges[at][j];
        if ((chmask[e] & mask) == 0)
          f[at][mask] = max(f[at][mask], addcost[e] + f[at][chmask[e] | mask]);
      }
    }
  }
  //plnarr(adj + 1, adj + V + 1);
  //pln(f[3][0]);
  //plnarr(postord.begin(), postord.end());
  //plnarr(addcost, addcost + paved);
  //plnarr(chmask, chmask + paved);
  //pln(f[1][0]);
  printf("%d\n", total - f[1][0]);
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
  ioi0723::solve();
  return 0;
}

