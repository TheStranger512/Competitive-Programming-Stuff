/* Solved
 * 4035. NERED - dp + brute force
 * File:   MNERED.cpp
 * Author: Andy Y.F. Huang
 * Created on August 31, 2012, 1:04 AM
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
namespace MNERED {
int dp[110][110] = {0};

int count(int x1, int y1, int x2, int y2) {
  return dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1];
}

void solve(int test_num) {
  int size, cubes, ans = 1000000;
  scanf("%d %d", &size, &cubes);
  for (int i = 0; i < cubes; i++) {
    int y, x;
    scanf("%d %d", &y, &x);
    dp[x][y] = 1;
  }
  for (int y = 1; y <= size; y++)
    for (int x = 1; x <= size; x++)
      dp[x][y] += dp[x - 1][y] + dp[x][y - 1] - dp[x - 1][y - 1];
  for (int y1 = 1; y1 <= size; y1++)
    for (int x1 = 1; x1 <= size; x1++)
      for (int y2 = y1; y2 <= size; y2++)
        for (int x2 = x1; x2 <= size; x2++)
          if ((y2 - y1 + 1) * (x2 - x1 + 1) == cubes)
            ans = min(ans, cubes - count(x1, y1, x2, y2));
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
  MNERED::solve();
  return 0;
}

