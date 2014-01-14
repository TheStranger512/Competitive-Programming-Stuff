/* Solved
 * IOI 2009 - Raisins
 * File:   Raisins.cpp
 * Author: Andy Y.F. Huang
 * Created on November 19, 2012, 10:05 PM
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
namespace Raisins {
int rows, cols;
int sum[55][55], dp[55][55][55][55];

inline int getsum(int r1, int c1, int r2, int c2) {
  return sum[r2][c2] - sum[r1 - 1][c2] - sum[r2][c1 - 1] + sum[r1 - 1][c1 - 1];
}

inline void checkmin(int& a, int b) {
  if (b < a) a = b;
}

void solve(int test_num) {
  scanf("%d %d", &rows, &cols);
  for (int r = 1; r <= rows; r++)
    for (int c = 1; c <= cols; c++)
      scanf("%d", &sum[r][c]);
  for (int r = 1; r <= rows; r++)
    for (int c = 1; c <= cols; c++)
      sum[r][c] += sum[r - 1][c] + sum[r][c - 1] - sum[r - 1][c - 1];
  memset(dp, 0x3F, sizeof (dp));
  for (int h = 1; h <= rows; h++) {
    for (int w = 1; w <= cols; w++) {
      for (int r1 = 1; r1 + h - 1 <= rows; r1++) {
        for (int c1 = 1; c1 + w - 1 <= cols; c1++) {
          if (w * h == 1) {
            dp[h][w][r1][c1] = 0;
            continue;
          }
          int sum = getsum(r1, c1, r1 + h - 1, c1 + w - 1);
          for (int r = r1; r < r1 + h - 1; r++) { //horizontal cuts
            checkmin(dp[h][w][r1][c1], dp[r - r1 + 1][w][r1][c1] + dp[r1 + h - r - 1][w][r + 1][c1]);
          }
          for (int c = c1; c < c1 + w - 1; c++) {
            checkmin(dp[h][w][r1][c1], dp[h][c - c1 + 1][r1][c1] + dp[h][c1 + w - c - 1][r1][c + 1]);
          }
          dp[h][w][r1][c1] += sum;
          //pln(h, w, r1, c1, dp[h][w][r1][c1], sum);
        }
      }
    }
  }
  printf("%d\n", dp[rows][cols][1][1]);
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
  Raisins::solve();
  return 0;
}

