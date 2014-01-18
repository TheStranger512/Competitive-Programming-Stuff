/* Solved
 * 8611. Non-Decreasing Digits
 * File:   NY10E.cpp
 * Author: Andy Y.F. Huang
 * Created on August 27, 2012, 8:24 PM
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
namespace NY10E {
const int k_max_len = 70;
long long dp[k_max_len][15] = {0};
long long ans[k_max_len] = {0};

void init() {
  for (int d = 0; d <= 9; d++)
    dp[1][d] = 1;
  ans[1] = 10;
  for (int len = 2; len < k_max_len; len++)
    for (int d = 0; d <= 9; ans[len] += dp[len][d], d++)
      for (int i = 0; i <= d; i++)
        dp[len][d] += dp[len - 1][i];
}

void solve(int test_num) {
  int n;
  scanf("%d %d", &test_num, &n);
  printf("%d %lld\n", test_num, ans[n]);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  init();
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  NY10E::solve();
  return 0;
}

