/* Solved
 * IOI '05 - Nowy Sacz, Poland
 * Garden
 * File:   ioi0511.cpp
 * Author: Andy Y.F. Huang
 * Created on November 17, 2012, 5:07 PM
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
namespace ioi0511 {
int need;
int dp[266][266];
int left[266], right[266];

inline int getsum(int r1, int c1, int r2, int c2) {
  if (r1 > r2 || c1 > c2) return 0;
  return dp[r2][c2] - dp[r1 - 1][c2] - dp[r2][c1 - 1] + dp[r1 - 1][c1 - 1];
}

inline int getperi(int r1, int c1, int r2, int c2) {
  return 2 * (r2 - r1 + 1) + 2 * (c2 - c1 + 1);
}

int go(int rows, int cols) {
  memset(left, 0x3F, sizeof (left));
  memset(right, 0x3F, sizeof (right));
  for (int y1 = 1; y1 <= rows; y1++) {
    for (int y2 = y1; y2 <= rows; y2++) {
      int x1 = 1, x2 = 1;
      while (x2 <= cols) {
        int sum = getsum(y1, x1, y2, x2);
        if (sum == need) {
          right[x1] = min(right[x1], getperi(y1, x1, y2, x2));
          left[x2] = min(left[x2], getperi(y1, x1, y2, x2));
        }
        if (sum < need)
          x2++;
        else
          x1++;
      }
    }
  }
  for (int c = 1; c <= cols; c++)
    left[c] = min(left[c], left[c - 1]);
  for (int c = cols; c >= 1; c--)
    right[c] = min(right[c], right[c + 1]);
  int ans = 1 << 30;
  for (int sep = 1; sep < cols; sep++)
    ans = min(ans, left[sep] + right[sep + 1]);
  return ans;
}

void solve(int test_num) {
  memset(dp, 0, sizeof (dp));
  int len, width, roses;
  scanf("%d %d %d %d", &len, &width, &roses, &need);
  for (int i = 0; i < roses; i++) {
    int row, col;
    scanf("%d %d", &row, &col);
    dp[row][col]++;
  }
  for (int r = 1; r <= len; r++)
    for (int c = 1; c <= width; c++)
      dp[r][c] += dp[r][c - 1] + dp[r - 1][c] - dp[r - 1][c - 1];
  int ans = go(len, width);
  const int high = max(len, width);
  for (int r = 1; r <= high; r++)
    for (int c = r; c <= high; c++)
      swap(dp[r][c], dp[c][r]);
  ans = min(ans, go(width, len));
  if (ans > 1e6)
    puts("NO");
  else
    printf("%d\n", ans);
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
  ioi0511::solve();
  return 0;
}

