/*
 * Solved
 * 12474. MAXIMUM WOOD CUTTER
 * File:   MAXWOODS.cpp
 * Author: Andy Y.F. Huang
 * Created on January 28, 2013, 1:08 PM
 */

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace MAXWOODS {
int dp[222][222];
char grid[222][222];

void solve(int test_num) {
  memset(dp, 0xF0, sizeof (dp));
  int rows, cols;
  scanf("%d %d", &rows, &cols);
  for (int r = 1; r <= rows; r++)
    scanf("%s", grid[r] + 1);
  dp[1][0] = 0;
  for (int c = 1; c <= cols && grid[1][c] != '#'; c++)
    dp[1][c] = dp[1][c - 1] + (grid[1][c] == 'T');
  int ans = *max_element(dp[1], dp[1] + cols + 1);
  for (int r = 2; r <= rows; r++) {
    if (r & 1)
      for (int c = 1; c <= cols; c++) {
        if (grid[r][c] != '#')
          dp[r][c] = max(dp[r - 1][c], dp[r][c - 1]) + (grid[r][c] == 'T');
      }
    else
      for (int c = cols; c > 0; c--)
        if (grid[r][c] != '#')
          dp[r][c] = max(dp[r - 1][c], dp[r][c + 1]) + (grid[r][c] == 'T');
    ans = max(ans, *max_element(dp[r], dp[r] + cols + 1));
  }
  printf("%d\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  MAXWOODS::solve();
  return 0;
}

