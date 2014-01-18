/*
 * Solved
 * 9387. Special String
 * File:   MAIN113.cpp
 * Author: Andy Y.F. Huang
 * Created on January 13, 2013, 12:36 AM
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
namespace MAIN113 {
//# of strings [len, last char, 2nd last char, special]
long long dp[33][3][3][2];

void solve(int test_num) {
  int len;
  scanf("%d", &len);
  long long ans = 1;
  for (int i = 0; i < len; i++)
    ans *= 3;
  for (int a = 0; a < 3; a++)
    for (int b = 0; b < 3; b++)
      ans -= dp[len][a][b][1];
  printf("%lld\n", ans);
}

void init() {
  memset(dp, 0, sizeof (dp));
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      dp[2][i][j][0] = 1;
  for (int i = 2; i < 30; i++) {
    for (int a = 0; a < 3; a++) {
      for (int b = 0; b < 3; b++) {
        for (int c = 0; c < 3; c++) {
          dp[i + 1][c][a][1] += dp[i][a][b][1];
          if (a != b && b != c && c != a)
            dp[i + 1][c][a][1] += dp[i][a][b][0];
          else
            dp[i + 1][c][a][0] += dp[i][a][b][0];
        }
      }
    }
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  init();
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  MAIN113::solve();
  return 0;
}

