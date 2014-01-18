/* Solved
 * 14956. Submerging Islands
 * File:   SUBMERGE.cpp
 * Author: Andy Y.F. Huang
 * Created on May 19, 2013, 12:48 AM
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

namespace SUBMERGE {
int vertices, edges;
int last[11000], to[222000], next[222000];
bool cut[11000];
int low[11000], pre[11000];

static int next_num() {
  static int X = 0;
  return X++;
}

void dfs(int at, int par) {
  low[at] = pre[at] = next_num();
  int size = 0;
  for (int e = last[at]; e > -1; e = next[e]) {
    if (to[e] == par) continue;
    if (pre[to[e]] != -1)
      low[at] = min(low[at], pre[to[e]]);
    else {
      size++;
      dfs(to[e], at);
      low[at] = min(low[at], low[to[e]]);
      if (par != -1 && pre[at] <= low[to[e]])
        cut[at] = true;
    }
  }
  if (par == -1 && size > 1) cut[at] = true;
}

void solve(int test_num) {
  memset(last, -1, sizeof (last));
  memset(cut, false, sizeof (cut));
  memset(pre, -1, sizeof (pre));
  for (int e = 0, a, b; e < edges + edges; e += 2) {
    scanf("%d %d", &a, &b);
    to[e] = b;
    next[e] = last[a];
    last[a] = e;
    to[e + 1] = a;
    next[e + 1] = last[b];
    last[b] = e + 1;
  }
  dfs(1, -1);
  printf("%d\n", count(cut, cut + vertices + 1, true));
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (scanf("%d %d", &vertices, &edges) != EOF)
    if (vertices + edges > 0)
      solve(1);
}
}

int main() {
  SUBMERGE::solve();
  return 0;
}

