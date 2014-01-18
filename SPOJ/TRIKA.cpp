/* Solved
 * 7217. Training for final
 * File:   TRIKA.cpp
 * Author: Andy Y.F. Huang
 * Created on August 12, 2012, 12:34 AM
 */

#include <cstdio>
#include <algorithm>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace TRIKA {

void solve(int test_num) {
  int rows, cols, sx, sy, dp[25][25] = {0};
  scanf("%d %d %d %d", &rows, &cols, &sy, &sx);
  for (int y = 0; y < rows; y++)
    for (int x = 0; x < cols; x++)
      scanf("%d", &dp[x][y]);
  sy--, sx--;
  for (int y = sy; y < rows; y++) {
    for (int x = sx; x < cols; x++) {
      if (x == sx && y == sy)
        continue;
      if (x == sx)
        dp[x][y] = dp[x][y - 1] - dp[x][y];
      else if (y == sy)
        dp[x][y] = dp[x - 1][y] - dp[x][y];
      else
        dp[x][y] = max(dp[x][y - 1], dp[x - 1][y]) - dp[x][y];
      //printf("%4d ", dp[x][y]);
    }
    //putchar('\n');
  }
  if (dp[cols - 1][rows - 1] >= 0)
    printf("Y %d\n", dp[cols - 1][rows - 1]);
  else
    puts("N");
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
  TRIKA::solve();
  return 0;
}

