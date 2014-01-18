/* Solved
 * 9103. Special Numbers
 * File:   NOVICE63.cpp
 * Author: Andy Y.F. Huang
 * Created on January 5, 2013, 1:33 AM
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
namespace NOVICE63 {
//# of nums with [len, ones]
long long dp[66][33], ans[66];

void init() {
  memset(dp, 0, sizeof (dp));
  dp[1][1] = 1;
  for (int i = 1; i < 60; i++) {
    for (int a = 0; a <= i; a++) {
      dp[i + 1][a + 1] += dp[i][a]; //append one
      dp[i + 1][a] += dp[i][a]; //append zero;
    }
  }
  ans[1] = 0;
  for (int i = 2; i <= 60; i++)
    ans[i] = ans[i - 1] + ((i & 1) ? 0 : dp[i][i >> 1]);
  ans[1] = 1;
  //plnarr(ans, ans + 60);
}

void solve(int test_num) {
  long long num;
  scanf("%lld", &num);
  for (int i = 60; i >= 0; i--)
    if(1LL << i & num)
      printf("%lld\n", ans[i]);
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
  NOVICE63::solve();
  return 0;
}

