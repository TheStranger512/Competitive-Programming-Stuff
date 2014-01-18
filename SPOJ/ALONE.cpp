/*
 * Solved
 * 13469. FOREVER ALONE
 * File:   ALONE.cpp
 * Author: Andy Y.F. Huang
 * Created on February 18, 2013, 4:40 PM
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
namespace ALONE {
#define MAX (1LL << 45)
typedef long long llong;
int dp[40][10][2][2]; //[pos, last digit, 1st occurence of last digit, less]
char str[111];

int go(llong upto) {
  sprintf(str + 1, "%lld", upto);
  int len = strlen(str + 1);
  memset(dp, 0, sizeof (dp));
  str[1] -= '0';
  for (int d = 1; d < str[1]; d++)
    dp[1][d][1][0] = 1;
  dp[1][str[1]][1][1] = 1;
  for (int i = 2; i <= len; i++) {
    str[i] -= '0';
    for (int d = 0; d < 10; d++) {
      //start new number
      if (d > 0)
        dp[i][d][1][0] = 1;
      //continue digit run
      dp[i][d][0][0] += dp[i - 1][d][1][0] + dp[i - 1][d][0][0];
      if (d < str[i])
        dp[i][d][0][0] += dp[i - 1][d][1][1] + dp[i - 1][d][0][1];
      else if (d == str[i])
        dp[i][d][0][1] += dp[i - 1][d][1][1] + dp[i - 1][d][0][1];
      //start new digit run
      for (int dd = 0; dd < 10; dd++) {
        if (d == dd) continue;
        dp[i][d][1][0] += dp[i - 1][dd][0][0];
        if (d < str[i])
          dp[i][d][1][0] += dp[i - 1][dd][0][1];
        else if (d == str[i])
          dp[i][d][1][1] += dp[i - 1][dd][0][1];
      }
    }
  }
  int ans = 0;
  for (int d = 0; d < 10; d++)
    ans += dp[len][d][0][0];
  return ans;
}

void solve(int test_num) {
  int rank;
  scanf("%d", &rank);
  llong ans = MAX;
  for (llong low = 0, high = MAX; low <= high; ) {
    llong mid = (low + high) >> 1;
    if (go(mid) >= rank) {
      ans = min(ans, mid);
      high = mid - 1;
    }
    else low = mid + 1;
  }
  printf("%lld\n", ans - 1);
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
  ALONE::solve();
  return 0;
}

