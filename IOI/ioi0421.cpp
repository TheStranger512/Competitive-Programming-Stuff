/* Solved
 * IOI '04 - Athens, Greece - Phidas - dp
 * File:   ioi0421.cpp
 * Author: Andy Y.F. Huang
 * Created on September 17, 2012, 11:57 PM
 */

#include <cstdio>
#include <cmath>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#endif

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace ioi0421 {
const int k_maxsize = 601;
int dp[k_maxsize][k_maxsize];
//dp[w][h] = least wasted space of w x h rectangle

inline int min(int a, int b) {
  return a < b ? a : b;
}

void solve(int test_num) {
  int width, height, diff;
  scanf("%d %d %d", &width, &height, &diff);
  for (int w = 0; w <= width; w++)
    for (int h = 0; h <= height; h++)
      dp[w][h] = w * h; //all space wasted
  for (int i = 0; i < diff; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    dp[x][y] = 0; //can use rectangle fully
  }
  for (int x = 1; x <= width; x++) {
    int limx = x >> 1;
    for (int y = 1; y <= height; y++) {
      int limy = y >> 1;
      for (int c = 1; c <= limx; c++)
        dp[x][y] = min(dp[x][y], dp[c][y] + dp[x - c][y]);
      for (int c = 1; c <= limy; c++)
        dp[x][y] = min(dp[x][y], dp[x][c] + dp[x][y - c]);
    }
  }
  printf("%d\n", dp[width][height]);
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
  ioi0421::solve();
  return 0;
}

