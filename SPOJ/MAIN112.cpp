/* Solved
 * 9386. Re-Arrange II
 * File:   MAIN112.cpp
 * Author: Andy Y.F. Huang
 * Created on April 1, 2013, 4:40 PM
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

namespace MAIN112 {
#define two(x) (1<<(x))
#define bitcnt(x) __builtin_popcount(x)
int num[22], cost[22];
int dp[two(15)][15]; //last element, used

void checkmin(int& a, int b) {
  if (b < a) a = b;
}

void solve(int test_num) {
  int len;
  scanf("%d", &len);
  for (int i = 0; i < len; i++)
    scanf("%d", num + i);
  for (int i = 0; i < len; i++)
    scanf("%d", cost + i);
  memset(dp, 0x3F, sizeof (dp));
  for (int i = 0; i < len; i++)
    dp[two(i)][i] = 0;
  for (int mask = 1; mask < two(len); mask++)
    for (int ed = 0; ed < len; ed++)
      if (two(ed) & mask)
        for (int i = 0; i < len; i++)
          if (!(two(i) & mask))
            checkmin(dp[two(i) | mask][i], dp[mask][ed] + abs(num[i] - num[ed]) * cost[bitcnt(mask)]);
  int ans = 1 << 28;
  for (int i = 0; i < len; i++)
    ans = min(ans, dp[two(len) - 1][i]);
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
  MAIN112::solve();
  return 0;
}

