/* Solved
 * 12893. Short Select
 * File:   DCEPCA04.cpp
 * Author: Andy Y.F. Huang
 * Created on December 22, 2012, 7:30 PM
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
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <iomanip>
#include <cassert>
#include <ctime>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace DCEPCA04 {
//# of ways to choose i problems with j AC
int dp[12][1111];
int cansolve[55];

void solve(int test_num) {
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 44; j++) {
      int temp;
      scanf("%d", &temp);
      cansolve[j] += temp;
    }
  }
  int lim;
  scanf("%d", &lim);
  if (lim > 1000) {
    puts("0");
    return;
  }
  dp[0][0] = 1;
  for (int p = 0; p < 44; p++) {
    for (int i = 9; i >= 0; i--) {
      for (int ac = 0; ac <= 1000; ac++) {
        dp[i + 1][ac + cansolve[p]] += dp[i][ac];
      }
    }
  }
  long long ans = 0;
  for (int i = lim; i <= 1000; i++)
    ans += dp[10][i];
  printf("%lld\n", ans);
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
  DCEPCA04::solve();
  return 0;
}

