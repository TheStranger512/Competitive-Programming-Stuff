/* Solved
 * 14930. Princess Farida
 * File:   FARIDA.cpp
 * Author: Andy Y.F. Huang
 * Created on May 19, 2013, 12:57 AM
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

namespace FARIDA {
int val[1111];
long long dp[1111];

void solve(int test_num) {
  int len;
  scanf("%d", &len);
  for (int i = 0; i < len; i++) {
    scanf("%d", val + i);
    dp[i] = 0;
  }
  for (int i = 0; i < len; i++) {
    if (i >= 2)
      dp[i] = max(dp[i], dp[i - 2] + val[i]);
    else dp[i] = max(dp[i], (long long) val[i]);
    dp[i + 1] = dp[i];
  }
  printf("Case %d: %lld\n", test_num, dp[len - 1]);
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
  FARIDA::solve();
  return 0;
}

