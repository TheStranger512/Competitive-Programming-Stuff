/* Solved
 * 3380. Tourist
 * File:   TOURIST.cpp
 * Author: Andy Y.F. Huang
 * Created on December 22, 2012, 7:54 PM
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
namespace TOURIST {
char grid[111][111];
//max visited attraction at diag (d) at row (i) and row (j)
int dp[220][111][111];

void checkmax(int& a, int b) {
  if (b > a) a = b;
}

void solve(int test_num) {
  memset(grid, '#', sizeof (grid));
  memset(dp, 0xF7, sizeof (dp));
  int width, height;
  scanf("%d %d", &width, &height);
  for (int r = 1; r <= height; r++) {
    scanf("%s", grid[r] + 1);
    grid[r][width + 1] = '#';
  }
  dp[2][1][1] = 0;
  for (int d = 2; d <= width + height; d++) {
    for (int i = d - 1; i > 0; i--) {
      int c1 = d - i;
      if (grid[i][c1] == '#') continue;
      for (int j = d - 1; j > 0; j--) {
        int c2 = d - j;
        if (grid[j][c2] == '#') continue;
        int sum = dp[d][i][j] + (grid[i][c1] == '*');
        if (j != i && grid[j][c2] == '*')
          sum++;
        if (grid[i + 1][c1] != '#') {
          if (grid[j + 1][c2] != '#')
            checkmax(dp[d + 1][i + 1][j + 1], sum);
          if (grid[j][c2 + 1] != '#')
            checkmax(dp[d + 1][i + 1][j], sum);
        }
        if (grid[i][c1 + 1] != '#') {
          if (grid[j + 1][c2] != '#')
            checkmax(dp[d + 1][i][j + 1], sum);
          if (grid[j][c2 + 1] != '#')
            checkmax(dp[d + 1][i][j], sum);
        }
      }
    }
  }
  printf("%d\n", dp[width + height][height][height] + (grid[height][width] == '*'));
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
  TOURIST::solve();
  return 0;
}

