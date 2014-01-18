/* Solved
 * 10420. Hardware upgrade
 * File:   IOPC1200.cpp
 * Author: Andy Y.F. Huang
 * Created on May 30, 2013, 11:53 PM
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

namespace IOPC1200 {
#define MOD 1000000007
typedef long long llong;
int last[11111], to[22222], next[22222];
llong hash[11111], fact[11111];
llong vals[11111];
llong res;

void go(int at, int par) {
  hash[at] = 13371337;
  for (int e = last[at]; ~e; e = next[e])
    if (to[e] != par) {
      go(to[e], at);
      hash[at] += MOD;
    }
  int deg = 0;
  for (int e = last[at]; ~e; e = next[e])
    if (to[e] != par)
      vals[deg++] = hash[to[e]];
  sort(vals, vals + deg);
  //pln(at);
  //plnarr(vals, vals + deg);
  for (int d = 0; d < deg; d++)
    hash[at] = (hash[at] << 10) - (hash[at] ^ vals[d]);
  for (int d = 0, j; d < deg; ) {
    j = d;
    while (j < deg && vals[d] == vals[j])
      j++;
    res = res * fact[j - d] % MOD;
    d = j;
  }
}

void solve(int test_num) {
  memset(last, -1, sizeof (last));
  int size;
  scanf("%d", &size);
  for (int i = 0, a, b; i < size - 1; i++) {
    scanf("%d %d", &a, &b);
    to[i << 1] = b;
    next[i << 1] = last[a];
    last[a] = i << 1;
    to[i << 1 | 1] = a;
    next[i << 1 | 1] = last[b];
    last[b] = i << 1 | 1;
  }
  res = 1;
  go(0, -1);
  //plnarr(hash, hash + size);
  printf("%d\n", (int) res);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  fact[0] = 1;
  for (int i = 1; i <= 10000; i++)
    fact[i] = i * fact[i - 1] % MOD;
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  IOPC1200::solve();
  return 0;
}

