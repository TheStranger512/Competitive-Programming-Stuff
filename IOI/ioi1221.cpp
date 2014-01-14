/* Solved
 * PEG
 * IOI '12 - Sirmione/Montichiari, Italy
 * Ideal City
 * File:   ioi1221.cpp
 * Author: Andy Y.F. Huang
 * Created on Aug 12, 2013, 10:02:10 PM
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

using namespace std;

namespace ioi1221 {
const int mod = 1000000000;
typedef pair<int, int> PairInt;
typedef long long ll;
PairInt pts[100111], edges[100111];
int head[100111], to[200111], pred[200111], size[100111];
int up[100111], id[100111], wei[100111];
int N, V, E, ans;

void add_edge(int a, int b) {
  to[E] = b;
  pred[E] = head[a];
  head[a] = E++;
  to[E] = a;
  pred[E] = head[b];
  head[b] = E++;
}

int find_city(PairInt p) {
  int pos = lower_bound(pts, pts + N, p) - pts;
  if (pos < N && pts[pos] == p)
    return pos;
  return -1;
}

void add(int& a, ll x) {
  x %= mod;
  if ((a += x) >= mod)
    a -= mod;
}

void dfs(int at, int par) {
  size[at] = wei[at];
  up[at] = 0;
  for (int e = head[at], v; ~e; e = pred[e]) {
    if (to[e] == par)
      continue;
    v = to[e];
    dfs(v, at);
    add(ans, (ll) (up[v] + size[v]) * size[at]);
    add(ans, (ll) (up[at]) * size[v]);
    //pln(at, v, (up[v] + size[v]) * (up[at] + wei[at]));
    size[at] += size[v];
    add(up[at], up[v] + size[v]);
  }
}

int go() {
  int M = 0;
  sort(pts, pts + N);
  V = E = ans = 0;
  for (int i = 0, j, pos; i < N; i = j, V++) {
    j = i + 1;
    while (j < N && pts[i].first == pts[j].first && pts[j - 1].second + 1 == pts[j].second)
      j++;
    wei[V] = j - i;
    for (; i < j; i++) {
      id[i] = V;
      PairInt adj(pts[i].first - 1, pts[i].second);
      pos = find_city(adj);
      if (~pos)
        edges[M++] = PairInt(id[i], id[pos]);
    }
  }
  M = unique(edges, edges + M) - edges;
  memset(head, -1, sizeof(head));
  for (int e = 0; e < M; e++)
    add_edge(edges[e].first, edges[e].second);

//  plnarr(edges, edges + M);
//  plnarr(to, to + E);
//  plnarr(head, head + V);
//  plnarr(pred, pred + E);
  dfs(0, -1);
  //plnarr(up, up + V);
//  plnarr(size, size + V);
//  dbgln(ans);
  return ans;
}

void solve(int test_num) {
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%d %d", &pts[i].first, &pts[i].second);
  int res = go();
  for (int i = 0; i < N; i++)
    swap(pts[i].first, pts[i].second);
  res += go();
  if (res >= mod)
    res -= mod;
  printf("%d\n", res);
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
  ioi1221::solve();
  return 0;
}
