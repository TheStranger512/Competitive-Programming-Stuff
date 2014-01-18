/* Solved
 * 13444. Counting Lucky Numbers
 * File:   CNT_LUCK.cpp
 * Author: Andy Y.F. Huang
 * Created on February 18, 2013, 5:56 PM
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
namespace CNT_LUCK {
typedef long long llong;
typedef unsigned long long ullong;
llong dp[66][66][2]; //[pos, ones, tight]
int num[66];

llong go(ullong upto) {
  int len = 0;
  for (ullong e = upto; e > 0; e >>= 1)
    num[len++] = (int) (e & 1);
  reverse(num, num + len);
  if (len == 0) num[len++] = 0;
  memset(dp, 0, sizeof (dp));
  dp[0][1][1] = dp[0][0][0] = 1;
  for (int i = 1; i < len; i++) {
    for (int o = 0; o <= i; o++) {
      dp[i][o + 1][0] += dp[i - 1][o][0];
      dp[i][o][0] += dp[i - 1][o][0];
      if (num[i] == 1) {
        dp[i][o + 1][1] += dp[i - 1][o][1];
        dp[i][o][0] += dp[i - 1][o][1];
      }
      else dp[i][o][1] += dp[i - 1][o][1];
    }
  }
  llong ans = dp[len - 1][4][0] + dp[len - 1][7][0] + dp[len - 1][44][0] + dp[len - 1][47][0];
  return ans;
}

void solve(int test_num) {
  ullong a, b;
  scanf("%llu %llu", &a, &b);
  printf("%lld\n", go(b + 1) - go(a));
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  //pln((1LLu << 64) - 1);
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  CNT_LUCK::solve();
  return 0;
}

