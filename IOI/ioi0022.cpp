/* Solved
 * IOI '00 - Beijing, China - Post Office
 * File:   ioi0022.cpp
 * Author: Andy Y.F. Huang
 * Created on August 10, 2012, 4:19 PM
 */

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#endif

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace ioi0022 {
const int k_max_villages = 310, k_max_offices = 35;
int pos[k_max_villages], dp[k_max_offices][k_max_villages];
int back[k_max_offices][k_max_villages];
int ans[k_max_offices], pre[k_max_villages][k_max_villages];

int sum(int left, int right) {
  int ans = 0, mid = (left + right) >> 1;
  for (int i = left; i <= right; i++)
    ans += abs(pos[i] - pos[mid]);
  return ans;
}

void solve(int test_num) {
  int villages, offices;
  scanf("%d %d", &villages, &offices);
  for (int i = 1; i <= villages; i++)
    scanf("%d", &pos[i]);
  memset(dp, 0x3F, sizeof (dp));
  for (int i = 1; i <= villages; i++)
    for (int j = i; j <= villages; j++)
      pre[i][j] = sum(i, j);
  for (int i = 1; i <= villages; i++) {
    dp[1][i] = pre[1][i];
    back[1][i] = 1;
  }
  for (int o = 2; o <= offices; o++) {
    for (int v = o; v <= villages; v++) {
      for (int i = o - 1; i < v; i++) {
        int temp = dp[o - 1][i] + pre[i + 1][v];
        if (temp < dp[o][v]) {
          dp[o][v] = temp;
          back[o][v] = i + 1;
        }
      }
    }
  }
//  for (int o = 1; o <= offices; o++) {
//    for (int v = 1; v <= villages; v++)
//      printf("%8d ", dp[o][v]);
//    putchar('\n');
//  }
  printf("%d\n", dp[offices][villages]);
  for (int o = offices, last = villages; o >= 1; o--) {
    ans[o] = pos[(back[o][last] + last) >> 1];
    last = back[o][last] - 1;
  }
  for (int i = 1; i <= offices; i++)
    printf("%d ", ans[i]);
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
  ioi0022::solve();
  return 0;
}

