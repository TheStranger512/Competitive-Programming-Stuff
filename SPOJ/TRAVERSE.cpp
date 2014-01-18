/* Solved
 * 8598. Traverse through the board
 * File:   TRAVERSE.cpp
 * Author: Andy Y.F. Huang
 * Created on December 22, 2012, 11:04 PM
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
namespace TRAVERSE {
char grid[15][15];
int dp[15][15];

void solve(int test_num) {
  memset(dp, 0, sizeof (dp));
  int size;
  scanf("%d", &size);
  for (int r = 1; r <= size; r++)
    scanf("%s", grid[r] + 1);
  dp[1][1] = 1;
  for (int r = 1; r <= size; r++) {
    for (int c = 1; c <= size; c++) {
      int d = grid[r][c] - '0';
      if (!d) continue;
      if (r + d <= size)
        dp[r + d][c] += dp[r][c];
      if (c + d <= size)
        dp[r][c + d] += dp[r][c];
    }
  }
  printf("%d", dp[size][size]);
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
  TRAVERSE::solve();
  return 0;
}

