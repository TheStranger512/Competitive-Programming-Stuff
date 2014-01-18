/* Solved
 * 15433. Greedy Walking
 * File:   UCV2013E.cpp
 * Author: Andy Y.F. Huang
 * Created on July 24, 2013, 12:41 AM
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

namespace UCV2013E {
#define MOD 1000000007
typedef long long llong;
llong fact[555], invfact[555];
int diff[55];
int N;

int fpow(llong x, int e) {
  llong res = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) res = res * x % MOD;
    x = x * x % MOD;
  }
  return res;
}

void solve(int test_num) {
  if (N == 0) return;
  for (int i = 0; i < N; i++)
    scanf("%d", diff + i);
  int sum = 0;
  for (int i = 0, x; i < N; i++) {
    scanf("%d", &x);
    diff[i] = abs(diff[i] - x);
    sum += diff[i];
  }
  llong res = fact[sum];
  for (int i = 0; i < N; i++)
    res = res * invfact[diff[i]] % MOD;
  printf("%d\n", (int) res);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  fact[0] = invfact[0] = 1;
  for (int i = 1; i <= 500; i++) {
    fact[i] = fact[i - 1] * i % MOD;
    invfact[i] = fpow(fact[i], MOD - 2);
  }
  while (scanf("%d", &N) != EOF)
    solve(1);
}
}

int main() {
  UCV2013E::solve();
  return 0;
}

