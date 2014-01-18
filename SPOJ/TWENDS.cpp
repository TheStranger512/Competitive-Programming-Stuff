/* Solved
 * 1710. Two Ends
 * File:   TWENDS.cpp
 * Author: Andy Y.F. Huang
 * Created on October 23, 2012, 8:14 PM
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
namespace TWENDS {
int value[1111], len;
int dp[1111][1111];
//dp[i][j] max points of len i starting from j on second player's turn

void solve(int test_num) {
  memset(dp[0], 0, sizeof (dp[0]));
  int sum = 0;
  for (int i = 0; i < len; i++) {
    scanf("%d", &value[i]);
    sum += value[i];
    dp[1][i] = value[i];
  }
  for (int i = 2; i <= len; i++) {
    for (int j = 0; j + i <= len; j++) {
      //2nd player chooses left
      if (value[j + 1] >= value[j + i - 1])
        dp[i][j] = value[j] + dp[i - 2][j + 2];
      else
        dp[i][j] = value[j] + dp[i - 2][j + 1];
      //2nd player chooses right
      if (value[j] >= value[j + i - 2])
        dp[i][j] = max(dp[i][j], value[j + i - 1] + dp[i - 2][j + 1]);
      else
        dp[i][j] = max(dp[i][j], value[j + i - 1] + dp[i - 2][j]);
    }
  }
  printf("In game %d, the greedy strategy might lose by as many as %d points.\n"
         , test_num, dp[len][0] - (sum - dp[len][0]));
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  for (int i = 1; ; i++) {
    scanf("%d", &len);
    if (len == 0)
      break;
    solve(i);
  }
}
}

int main() {
  TWENDS::solve();
  return 0;
}

