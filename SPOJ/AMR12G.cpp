/* Solved
 * 13046. The Glittering Caves of Aglarond
 * File:   AMR12G.cpp
 * Author: Andy Y.F. Huang
 * Created on December 21, 2012, 11:19 PM
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
namespace AMR12G {
int dp[55][111];
int cnt[55];
char str[55];

void solve(int test_num) {
  memset(dp, 0xF7, sizeof (dp));
  memset(cnt, 0, sizeof (cnt));
  int rows, cols, lim;
  scanf("%d %d %d", &rows, &cols, &lim);
  dp[0][0] = 0;
  for (int r = 1; r <= rows; r++) {
    scanf("%s", str);
    for (int c = 0; c < cols; c++)
      if (str[c] == '*')
        cnt[r]++;
    for (int i = 0; i <= lim; i++)  {
      for (int j = i; j <= lim; j += 2)
        dp[r][j] = max(dp[r][j], cnt[r] + dp[r - 1][i]);
      for (int j = i + 1; j <= lim; j += 2)
        dp[r][j] = max(dp[r][j], cols - cnt[r] + dp[r - 1][i]);
    }
  }
  printf("%d\n", dp[rows][lim]);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(1);
}
}

int main() {
  AMR12G::solve();
  return 0;
}

