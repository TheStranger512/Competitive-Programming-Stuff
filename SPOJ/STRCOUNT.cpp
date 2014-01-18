/* Solved
 * 9570. Counting binary strings
 * File:   STRCOUNT.cpp
 * Author: Andy Y.F. Huang
 * Created on August 28, 2012, 3:31 PM
 */

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <fstream>
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

namespace STRCOUNT {
#define MAX 63
typedef long long llong;
llong ans[66][66];
llong dp[66][66][66]; //bits, last ones, max ones

void solve(int test_num) {
  memset(dp, 0, sizeof (dp));
  dp[0][0][0] = 1;
  for (int i = 1; i <= MAX; i++) {
    for (int m = 0; m < i; m++) {
      for (int o = 0; o < i; o++) {
        dp[i][o + 1][max(m, o + 1)] += dp[i - 1][o][m];
        dp[i][0][m] += dp[i - 1][o][m];
      }
    }
    for (int m = 0; m <= i; m++)
      for (int o = 0; o <= i; o++)
        ans[i][m] += dp[i][o][m];
  }
  for (int i = 1; i <= MAX; i++, putchar('\n'))
    for (int j = 0; j <= i; j++)
      printf("%lld ", ans[i][j]);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve(1);
}
}

int main() {
  STRCOUNT::solve();
  return 0;
}

