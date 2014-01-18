/* Solved
 * 14932. Lowest Common Ancestor
 * File:   LCA.cpp
 * Author: Andy Y.F. Huang
 * Created on May 19, 2013, 12:37 AM
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

namespace LCA {
int dep[1111];
int par[10][1111];
vector<int> adj[1111];

void dfs(int at) {
  for (int i = 0; i < (int) adj[at].size(); i++)
    if (adj[at][i] != par[0][at]) {
      par[0][adj[at][i]] = at;
      dep[adj[at][i]] = dep[at] + 1;
      dfs(adj[at][i]);
    }
}

int lca(int a, int b) {
  if (dep[a] < dep[b])
    swap(a, b);
  for (int i = 9; i >= 0; i--)
    if (dep[par[i][a]] >= dep[b])
      a = par[i][a];
  if (a == b) return a;
  for (int i = 9; i >= 0; i--)
    if (par[i][a] != par[i][b])
      a = par[i][a], b = par[i][b];
  return par[0][a];
}

void solve(int test_num) {
  int len;
  cin >> len;
  for (int i = 1; i <= len; i++) {
    adj[i].clear();
    int deg;
    cin >> deg;
    adj[i].resize(deg);
    for (int d = 0; d < deg; d++)
      cin >> adj[i][d];
  }
  par[0][1] = 1;
  dep[1] = 0;
  dfs(1);
  for (int j = 1; j < 10; j++)
    for (int i = 1; i <= len; i++)
      par[j][i] = par[j - 1][par[j - 1][i]];
  int quests;
  cin >> quests;
  cout << "Case " << test_num << ':' << endl;
  for (int q = 0, a, b; q < quests; q++) {
    cin >> a >> b;
    cout << lca(a, b) << endl;
  }
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
  LCA::solve();
  return 0;
}

