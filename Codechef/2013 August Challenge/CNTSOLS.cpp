/* Solved
 * August Challenge 2013
 * The Number Of Solutions
 * File:   CNTSOLS.cpp
 * Author: Andy Y.F. Huang
 * Created on August 2, 2013, 12:50 PM
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

namespace CNTSOLS {
#define MOD 1000000007
int dp[3][44], step[44], cnt[44];

int fpow(int base, int e, int mod) {
  int ans = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ans = ans * base % mod;
    base = base * base % mod;
  }
  return ans;
}

void add(int& a, long long b) {
  if ((a += b) >= MOD) a -= MOD;
}

void solve(int test_num) {
  int upper, d, M, N;
  cin >> upper >> d >> M >> N;
  upper++;
  memset(dp, 0, sizeof (dp));
  for (int rem = 0; rem < N; rem++) {
    step[rem] = fpow(rem, d, N);
    cnt[rem] = upper / N + (rem < upper % N);
    add(dp[0][step[rem] % N], cnt[rem]);
  }
  //plnarr(step, step + N);
  //plnarr(cnt, cnt + N);
  for (int i = 0; i < 2; i++)
    for (int rem = 0; rem < N; rem++)
      for (int j = 0; j < N; j++)
        add(dp[i + 1][(rem + step[j]) % N],  1LL * dp[i][rem] * cnt[j] % MOD);
  printf("%d\n", dp[2][M]);
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
  CNTSOLS::solve();
  return 0;
}

