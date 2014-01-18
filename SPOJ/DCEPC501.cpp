/* Solved
 * 11404. Save Thy Toys
 * File:   DCEPC501.cpp
 * Author: Andy Y.F. Huang
 * Created on October 13, 2012, 9:38 PM
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

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace DCEPC501 {
//dp[i] = max can get if I start picking at i
//ans for problem will be dp[len]
long long dp[111111];
int price[111111];

void solve(int test_num) {
  memset(dp, 0, sizeof (dp));
  int len;
  scanf("%d", &len);
  for (int i = 0; i < len; i++)
    scanf("%d", &price[i]);
  for (int i = len; i < len + 10; i++)
    price[i] = 0;
  for (int i = 0; i < len; i++) {
    if (i & 1) //cant start picking from odd indexed elements
      continue;
    dp[i + 2] = max(dp[i + 2], dp[i] + price[i]);
    dp[i + 4] = max(dp[i + 4], dp[i] + price[i] + price[i + 1]);
    dp[i + 6] = max(dp[i + 6], dp[i] + price[i] + price[i + 1] + price[i + 2]);
  }
  //plnarr(dp, dp + len + 6);
  long long ans = 0;
  for (int i = len; i < len + 6; i++)
    ans = max(ans, dp[i]);
  printf("%lld\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  DCEPC501::solve();
  return 0;
}

