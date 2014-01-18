/*
 * Solved
 * 63. Square Brackets
 * File:   SQRBR.cpp
 * Author: Andy Y.F. Huang
 * Created on January 22, 2013, 6:34 PM
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
namespace SQRBR {
int dp[55][55]; //pos, #open left
bool open[55];

void solve(int test_num) {
  memset(open, false, sizeof (open));
  memset(dp, 0, sizeof (dp));
  int len, opencnt;
  scanf("%d %d", &len, &opencnt);
  len <<= 1;
  for (int c = 0; c < opencnt; c++) {
    int pos;
    scanf("%d", &pos);
    open[pos] = true;
  }
  dp[0][0] = 1;
  for (int i = 1; i <= len; i++) {
    for (int j = 1; j <= i; j++) {
      dp[i][j] = dp[i - 1][j - 1];
      if (!open[i])
        dp[i][j - 1] += dp[i - 1][j];
    }
  }
  printf("%d\n", dp[len][0]);
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
  SQRBR::solve();
  return 0;
}

