/* Solved
 * 7975. Tri graphs
 * File:   ACPC10D.cpp
 * Author: Andy Y.F. Huang
 * Created on August 3, 2012, 10:23 PM
 */

#include <cstdio>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace ACPC10D {
const int k_max_len = 100010;
int dp[k_max_len][3];

inline int min(int a, int b) {
  return a < b ? a : b;
}

void solve(int test_num, int len) {
  const int inf = 1234567890;
  for (int i = 0; i < len; i++)
    for (int j = 0; j < 3; j++)
      scanf("%d", &dp[i][j]);
  dp[0][0] = inf;
  dp[0][2] += dp[0][1];
  for (int i = 1; i < len; i++) {
    dp[i][0] += min(dp[i - 1][0], dp[i - 1][1]);
    int temp = dp[i][0];
    for (int j = 0; j < 3; j++)
      temp = min(temp, dp[i - 1][j]);
    dp[i][1] += temp;
    dp[i][2] += min(dp[i][1], min(dp[i - 1][1], dp[i - 1][2]));
    //pln(dp[i][0], dp[i][1], dp[i][2]);
  }
  printf("%d. %d\n", test_num, dp[len - 1][1]);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int i = 1;
  while (true) {
    int len;
    scanf("%d", &len);
    if (!len)
      break;
    solve(i++, len);
  }
}
}

int main() {
  ACPC10D::solve();
  return 0;
}

