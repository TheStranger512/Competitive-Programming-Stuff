/* Solved
 * 3974. Another Tree Problem
 * File:   MTREE.cpp
 * Author: Andy Y.F. Huang
 * Created on May 22, 2013, 10:44 PM
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

namespace MTREE {
#define MOD 1000000007
typedef long long llong;
int last[111000], to[222000], next[222000], cost[222000];
int dp[111000]; //sum of lengths of paths ending at i
int res = 0;

void add(int& a, int b) {
  if ((a += b) >= MOD) a -= MOD;
}

void add_edge(int a, int b, int c) {
  static int e = 0;
  cost[e] = c;
  to[e] = b;
  next[e] = last[a];
  last[a] = e++;
}

void go(int at, int par) {
  int sum = 0;
  for (int e = last[at], t; e > -1; e = next[e]) {
    if (to[e] == par) continue;
    go(to[e], at);
    t = (llong) (dp[to[e]] + 1) * cost[e] % MOD;
    add(dp[at], t);
    add(res, (int) ((llong) t * sum % MOD));
    add(sum, t);
  }
  add(res, dp[at]);
}

void solve(int test_num) {
  memset(last, -1, sizeof (last));
  int size;
  scanf("%d", &size);
  for (int i = 1, a, b, c; i < size; i++) {
    scanf("%d %d %d", &a, &b, &c);
    add_edge(a, b, c);
    add_edge(b, a, c);
  }
  memset(dp, 0, sizeof (dp));
  go(1, -1);
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
  MTREE::solve();
  return 0;
}

