/* Solved
 * 64. Permutations
 * File:   PERMUT1.cpp
 * Author: Andy Y.F. Huang
 * Created on February 17, 2013, 12:52 AM
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
namespace PERMUT1 {
int dp[13][111];

void solve(int test_num) {
  int len, invs;
  scanf("%d %d", &len, &invs);
  printf("%d\n", dp[len][invs]);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  memset(dp, 0, sizeof (dp));
  dp[0][0] = 1;
  for (int i = 1; i <= 12; i++)
    for (int j = 0; j < 100; j++)
      for (int d = 1; d <= i; d++)
        dp[i][j + i - d] += dp[i - 1][j];
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  PERMUT1::solve();
  return 0;
}

