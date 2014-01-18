/* Solved
 * 6219. Edit distance - dp
 * File:   EDIST.cpp
 * Author: Andy Y.F. Huang
 * Created on August 15, 2012, 5:47 PM
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
namespace EDIST {
char s[2020], t[2010];
int m, n, dp[2020][2020];

void solve(int test_num) {
  m = n = 0;
  scanf("%s\r\n%s\r\n", s + 1, t + 1);
  m = strlen(s + 1), n = strlen(t + 1);
  dp[0][0] = 0; // nothing
  for (int i = 1; i <= m; i++)
    dp[i][0] = i; //delete all
  for (int j = 1; j <= n; j++)
    dp[0][j] = j; //insert all
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= m; i++) {
      if (s[i] == t[j])
        dp[i][j] = dp[i - 1][j - 1];
      else
        dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
    }
  }
  printf("%d\n", dp[m][n]);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d\r\n", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  EDIST::solve();
  return 0;
}

