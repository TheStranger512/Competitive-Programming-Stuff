/*
 * Solved
 * 13367. EVEN COUNT
 * File:   GEEKOUNT.cpp
 * Author: Andy Y.F. Huang
 * Created on February 14, 2013, 9:14 PM
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
namespace GEEKOUNT {
char str[11];
int dp[15][2][2]; //pos, sum mod 2, tight

int f() {
  memset(dp, 0, sizeof (dp));
  int len = strlen(str);
  for (int i = 0; i < len; i++)
    str[i] -= '0';
  for (int d = 1; d < str[0]; d++)
    dp[0][d % 2][0]++;
  dp[0][str[0] % 2][1] = 1;
  for (int i = 1; i < len; i++) {
    for (int d = 0; d < 10; d++) {
      for (int mod = 0; mod < 2; mod++) {
        dp[i][mod * d % 2][0] += dp[i - 1][mod][0];
        if (d == str[i])
          dp[i][mod * d % 2][1] += dp[i - 1][mod][1];
        else if (d < str[i])
          dp[i][mod * d % 2][0] += dp[i - 1][mod][1];
      }
      if (d > 0)
        dp[i][d % 2][0]++;
    }
  }
  return dp[len - 1][0][0];
}

void solve(int test_num) {
  int from, to;
  scanf("%d %d", &from, &to);
  sprintf(str, "%d", to + 1);
  int ans = f();
  sprintf(str, "%d", from);
  ans -= f();
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
  GEEKOUNT::solve();
  return 0;
}

