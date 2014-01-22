/* Solved
 * Codechef 2013 October Challenge
 * Kamehameha
 * File:   KMHAMHA.cpp
 * Author: Andy Y.F. Huang
 * Created on Oct 4, 2013, 3:51:54 PM
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

namespace KMHAMHA {
vector<int> adj[1111];
int x[1111], y[1111], xx[1111], yy[1111];
int mr[1111];
bool vis[1111];

bool rec(int at) {
  if (at < 0)
    return true;
  for (int& to : adj[at]) {
    if (!vis[to]) {
      vis[to] = true;
      if (rec(mr[to])) {
        mr[to] = at;
        return true;
      }
    }
  }
  return false;
}

void solve(int test_num) {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> x[i] >> y[i];
    xx[i] = x[i];
    yy[i] = y[i];
    adj[i].clear();
  }
  sort(xx, xx + N);
  sort(yy, yy + N);
  const int X = unique(xx, xx + N) - xx;
  const int Y = unique(yy, yy + N) - yy;
  const int V = max(X, Y);
  for (int i = 0; i < N; i++) {
    x[i] = lower_bound(xx, xx + X, x[i]) - xx;
    y[i] = upper_bound(yy, yy + Y, y[i]) - yy;
    adj[x[i]].push_back(y[i]);
  }
  int res = 0;
  memset(mr, -1, sizeof(mr));
  for (int i = 0; i < V; i++) {
    memset(vis, false, sizeof(vis));
    res += rec(i);
  }
  cout << res << endl;
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
  KMHAMHA::solve();
  return 0;
}
