/* Solved
 * 6828. Lineup
 * File:   LINEUP.cpp
 * Author: Andy Y.F. Huang
 * Created on October 13, 2012, 10:12 PM
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
namespace LINEUP {
//dp[i][mask] = max score of first i positions, using the players in mask
int dp[12][1 << 12], skill[22][22];

inline void checkmax(int& a, int b) {
  if (b > a) a = b;
}

void solve(int test_num) {
  memset(dp, 0, sizeof (dp));
  for (int i = 0; i < 11; i++) {
    for (int j = 0; j < 11; j++)
      scanf("%d", &skill[i][j]);
    checkmax(dp[0][1 << i], skill[i][0]);
  }
  for (int pos = 0; pos < 10; pos++) {
    for (int mask = 2047; mask >= 0; mask--) {
      if (!dp[pos][mask])
        continue;
      for (int pl = 0; pl < 11; pl++) {
        if (!skill[pl][pos + 1] || (1 << pl & mask))
          continue;
        checkmax(dp[pos + 1][1 << pl | mask], dp[pos][mask] + skill[pl][pos + 1]);
      }
    }
  }
  printf("%d\n", dp[10][2047]);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  LINEUP::solve();
  return 0;
}

