/* Solved
 * 12866. Nlogonian Tickets
 * File:   NTICKETS.cpp
 * Author: Andy Y.F. Huang
 * Created on June 21, 2013, 11:56 PM
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

namespace NTICKETS {
#define MAX 100111
int depth[MAX], par[17][MAX], high[17][MAX];
int last[MAX], to[2 * MAX], next[2 * MAX], cost[2 * MAX];
int maxlog, N;

int getlca(int a, int b) {
  if (depth[a] < depth[b]) swap(a, b);
  for (int i = maxlog - 1; ~i; i--)
    if (depth[par[i][a]] >= depth[b])
      a = par[i][a];
  if (a == b) return a;
  for (int i = maxlog - 1; ~i; i--)
    if (par[i][a] != par[i][b])
      a = par[i][a], b = par[i][b];
  return par[0][a];
}

int gethigh(int a, int b) {
  //b is ancestor of a
  int res = -1337;
  for (int i = maxlog - 1; ~i; i--)
    if (depth[par[i][a]] >= depth[b]) {
      res = max(res, high[i][a]);
      a = par[i][a];
    }
  return res;
}

void dfs(int at) {
  for (int e = last[at]; ~e; e = next[e]) {
    if (to[e] != par[0][at]) {
      par[0][to[e]] = at;
      depth[to[e]] = depth[at] + 1;
      high[0][to[e]] = cost[e];
      dfs(to[e]);
    }
  }
}

void solve(int test_num) {
  for (int i = 1; i <= N; i++)
    last[i] = -1;
  for (int i = 1, a, b; i < N; i++) {
    scanf("%d %d %d", &a, &b, cost + i);
    cost[i + N] = cost[i];
    to[i] = b;
    next[i] = last[a];
    last[a] = i;
    to[i + N] = a;
    next[i + N] = last[b];
    last[b] = i + N;
  }
  par[0][1] = 1;
  depth[1] = 0;
  high[0][1] = -1337;
  dfs(1);
  maxlog = 0;
  while (1 << maxlog <= N)
    maxlog++;
  for (int j = 1; j < maxlog; j++)
    for (int i = 1; i <= N; i++) {
      par[j][i] = par[j - 1][par[j - 1][i]];
      high[j][i] = max(high[j - 1][i], high[j - 1][par[j - 1][i]]);
    }
  //plnarr(high, maxlog, N + 1);
  int Q;
  scanf("%d", &Q);
  for (int q = 0, a, b, lca; q < Q; q++) {
    scanf("%d %d", &a, &b);
    lca = getlca(a, b);
    printf("%d\n", max(gethigh(a, lca), gethigh(b, lca)));
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (scanf("%d", &N) != EOF)
    if (N > 0)
      solve(1);
}
}

int main() {
  NTICKETS::solve();
  return 0;
}

