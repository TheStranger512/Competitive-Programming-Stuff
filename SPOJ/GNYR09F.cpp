/* Solved
 * 5295. Adjacent Bit Counts
 * File:   GNYR09F.cpp
 * Author: Andy Y.F. Huang
 * Created on February 16, 2013, 12:21 PM
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
namespace GNYR09F {
int dp[111][111][2];//[len,adjcnt,lastbit]

void solve(int test_num) {
  int len, cnt;
  scanf("%d %d %d", &test_num, &len, &cnt);
  printf("%d %d\n", test_num, dp[len][cnt][0] + dp[len][cnt][1]);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  memset(dp, 0, sizeof (dp));
  dp[0][0][0] = 1;
  for (int i = 1; i <= 100; i++) {
    for (int k = 0; k < i; k++) {
      dp[i][k][1] += dp[i - 1][k][0];
      dp[i][k][0] += dp[i - 1][k][1] + dp[i - 1][k][0];
      dp[i][k + 1][1] += dp[i - 1][k][1];
    }
  }
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  GNYR09F::solve();
  return 0;
}

