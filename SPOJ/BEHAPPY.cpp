/* Solved
 * 9805. Be Awesome As Barney Stinson
 * File:   BEHAPPY.cpp
 * Author: Andy Y.F. Huang
 * Created on August 28, 2012, 9:56 PM
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
namespace BEHAPPY {
int girls, gifts, dp[110][110];

void solve(int test_num) {
  memset(dp, 0, sizeof (dp));
  dp[0][0] = 1;
  for (int i = 1; i <= girls; i++) {
    int low, high;
    scanf("%d %d", &low, &high);
    for (int give = low; give <= high; give++)
      for (int j = 0; j + give <= gifts; j++)
        dp[i][j + give] += dp[i - 1][j];
  }
  printf("%d\n", dp[girls][gifts]);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (true) {
    scanf("%d %d\n", &girls, &gifts);
    if (girls == 0 && gifts == 0)
      break;
    solve(1);
  }
}
}

int main() {
  BEHAPPY::solve();
  return 0;
}

