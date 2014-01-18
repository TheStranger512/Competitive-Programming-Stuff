/*
 * Solved
 * 13630. BATMAN1
 * File:   BAT1.cpp
 * Author: Andy Y.F. Huang
 * Created on February 17, 2013, 9:02 PM
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

namespace BAT1 {
int dp[1111], cost[22][22], value[22][22], open[22];
int best[1111];

void solve(int test_num) {
  int batches, len, budget;
  scanf("%d %d %d", &batches, &len, &budget);
  for (int i = 0; i < batches; i++)
    scanf("%d", open + i);
  for (int i = 0; i < batches; i++)
    for (int j = 0; j < len; j++)
      scanf("%d", &cost[i][j]);
  for (int i = 0; i < batches; i++)
    for (int j = 0; j < len; j++)
      scanf("%d", &value[i][j]);
  memset(best, 0xF0, sizeof (best));
  best[0] = 0;
  for (int i = 0; i < batches; i++) {
    memset(dp, 0xF0, sizeof (dp));
    dp[open[i]] = 0;
    for (int j = 0; j < len; j++)
      for (int k = cost[i][j]; k <= budget; k++)
        dp[k] = max(dp[k], dp[k - cost[i][j]] + value[i][j]);
    for (int k = 0; k <= budget; k++)
      best[k] = max(best[k], dp[k]);
  }
  memset(dp, 0xF0, sizeof (dp));
  dp[0] = 0;
  for (int i = 1; i <= budget; i++)
    for (int k = i; k <= budget; k++)
      dp[k] = max(dp[k], dp[k - i] + best[i]);
  int ans = *max_element(dp, dp + budget + 1);
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
  BAT1::solve();
  return 0;
}

