/* Solved
 * 10394. Buying Apples!
 * File:   ABA12C.cpp
 * Author: Andy Y.F. Huang
 * Created on August 3, 2012, 9:47 PM
 */

#include <cstdio>
#include <cstring>
#include <algorithm>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace ABA12C {
const int k_max_n = 110;
int dp[k_max_n][k_max_n], costs[k_max_n];

void solve(int test_num) {
  memset(dp, 0x3F, sizeof (dp));
  int items, target, ans = 1234567890;
  scanf("%d %d", &items, &target);
  for (int i = 1; i <= target; i++)
    scanf("%d", &costs[i]);
  dp[0][0] = 0;
  for (int i = 1; i <= target; i++) {
    for (int j = 1; j <= i; j++) {
      for (int k = 1; k <= min(items, i); k++) {
        if (costs[k] == -1)
          continue;
        dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + costs[k]);
      }
    }
  }
  for (int i = 1; i <= items; i++)
    ans = min(ans, dp[target][i]);
  printf("%d\n", ans > 1000000 ? -1 : ans);
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
  ABA12C::solve();
  return 0;
}

