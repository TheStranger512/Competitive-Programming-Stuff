/* Solved
 * 7150. Palindrome 2000
 * File:   IOIPALIN.cpp
 * Author: Andy Y.F. Huang
 * Created on August 12, 2012, 12:26 AM
 */

#include <cstdio>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#endif

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace IOIPALIN {
const int k_max_len = 5050;
int dp[k_max_len] = {0}, prev[k_max_len] = {0};
char str[k_max_len];

inline int max(int a, int b) {
  return a >= b ? a : b;
}

void solve(int test_num) {
  int len;
  scanf("%d\r\n", &len);
  gets(str + 1);
  for (int i = 1; i <= len; i++) {
    for (int j = 1; j <= len; j++) {
      if (str[i] == str[len - j + 1])
        dp[j] = 1 + prev[j - 1];
      else
        dp[j] = max(dp[j - 1], prev[j]);
      prev[j - 1] = dp[j - 1];
    }
    prev[len] = dp[len];
  }
  printf("%d\n", len - dp[len]);
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
  IOIPALIN::solve();
  return 0;
}

