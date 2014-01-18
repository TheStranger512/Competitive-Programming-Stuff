/* Solved
 * 3978. Distance Query
 * File:   DISQUERY.cpp
 * Author: Andy Y.F. Huang
 * Created on February 18, 2013, 12:49 PM
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

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace DISQUERY {
#define MAXLOG 17
int last[111000], to[222000], next[222000], cost[222000];
int par[MAXLOG][111000];
int low[MAXLOG][111000];
int high[MAXLOG][111000];
int timein[111000], timeout[111000];
int size, ctime;

void dfs(int at, int parent) {
  timein[at] = ++ctime;
  par[0][at] = parent;
  for (int id = last[at]; id != -1; id = next[id]) {
    if (to[id] != parent) {
      low[0][to[id]] = high[0][to[id]] = cost[id];
      dfs(to[id], at);
    }
  }
  timeout[at] = ++ctime;
}

bool isanc(int a, int b) {
  return timein[a] <= timein[b] && timeout[b] <= timeout[a];
}

int getlca(int a, int b) {
  if (isanc(a, b)) return a;
  for (int i = MAXLOG - 1; i >= 0; i--)
    if (!isanc(par[i][a], b))
      a = par[i][a];
  return par[0][a];
}

pair<int, int> go(int at, int anc) {
  //(low, high)
  pair<int, int> ans;
  int& a = ans.first, &b = ans.second;
  a = 1 << 30, b = 0;
  for (int i = MAXLOG - 1; i >= 0; i--) {
    if (!isanc(par[i][at], anc) || par[i][at] == anc) {
      a = min(a, low[i][at]);
      b = max(b, high[i][at]);
      at = par[i][at];
    }
  }
  return ans;
}

void solve(int test_num) {
  ctime = 0;
  memset(last, -1, sizeof (last));
  scanf("%d", &size);
  for (int e = 1, a, b; e < size; e++) {
    scanf("%d %d %d", &a, &b, &cost[e]);
    to[e] = b;
    next[e] = last[a];
    last[a] = e;
    cost[e + size] = cost[e];
    to[e + size] = a;
    next[e + size] = last[b];
    last[b] = e + size;
  }
  low[0][1] = 1 << 30;
  high[0][1] = 0;
  dfs(1, 1);
  for (int j = 1; j < MAXLOG; j++) {
    for (int i = 1; i <= size; i++) {
      par[j][i] = par[j - 1][par[j - 1][i]];
      low[j][i] = min(low[j - 1][i], low[j - 1][par[j - 1][i]]);
      high[j][i] = max(high[j - 1][i], high[j - 1][par[j - 1][i]]);
    }
  }
  int quests;
  scanf("%d", &quests);
  for (int q = 0, a, b; q < quests; q++) {
    scanf("%d %d", &a, &b);
    int lca = getlca(a, b);
    pair<int, int> ans = go(a, lca), ans2 = go(b, lca);
    printf("%d %d\n", min(ans.first, ans2.first), max(ans.second, ans2.second));
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
  DISQUERY::solve();
  return 0;
}

