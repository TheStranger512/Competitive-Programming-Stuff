/* Solved
 * 13789. Loving Power
 * File:   LOVINGPW.cpp
 * Author: Andy Y.F. Huang
 * Created on February 18, 2013, 2:43 PM
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
namespace LOVINGPW {
#define mod 1000000007
int str[55];
int dp[55][55][2]; //[len, one bits, tight]

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}

void slow(long long n) {
  int ans = 0;
  for (int i = 0; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (!((j ^ i) & ((j ^ i) - 1)))
        ans++;
  //pln(ans);
}

void solve(int test_num) {
  long long n;
  scanf("%lld", &n);
  //slow(n);
  n++;
  int len = 0;
  for (; n > 0; n >>= 1)
    str[++len] = n & 1;
  reverse(str + 1, str + len + 1);
  memset(dp, 0, sizeof (dp));
  dp[0][0][1] = 1;
  for (int i = 1; i <= len; i++) {
    for (int o = 0; o < i; o++) {
      add(dp[i][o + 1][0], dp[i - 1][o][0]);
      add(dp[i][o][0], dp[i - 1][o][0]);
      if (str[i] == 1) {
        add(dp[i][o][0], dp[i - 1][o][1]);
        add(dp[i][o + 1][1], dp[i - 1][o][1]);
      }
      else add(dp[i][o][1], dp[i - 1][o][1]);
    }
  }
  int ans = 0;
  for (int o = 1; o <= len; o++) {
    ans += (1LL * dp[len][o][0] * o) % mod;
    if (ans >= mod) ans -= mod;
  }
  printf("%d\n", ans);
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
  LOVINGPW::solve();
  return 0;
}

