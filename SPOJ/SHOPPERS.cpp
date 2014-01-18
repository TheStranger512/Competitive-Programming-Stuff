/* Solved
 * 7630. SHOPPERS
 * File:   SHOPPERS.cpp
 * Author: Andy Y.F. Huang
 * Created on November 22, 2012, 4:30 PM
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
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <iomanip>
#include <cassert>
#include <ctime>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace SHOPPERS {
int dp[22][1 << 14];
char can[22][22];

inline int bitcnt(int mask) {
  int ans = 0;
  for (int i = 0; i < 13; i++)
    if (1 << i & mask) ans++;
  return ans;
}

void solve(int test_num) {
  int ppl, items, need;
  scanf("%d %d %d", &ppl, &items, &need);
  for (int i = 1; i <= ppl; i++)
    scanf("%s", can[i]);
  memset(dp, 0, sizeof (dp));
  for (int i = 1; i <= ppl; i++) {
    for (int j = 0; j < items; j++) {
      if (can[i][j] == '0') continue;
      dp[i][1 << j] = 1;
      for (int mask = (1 << items) - 1; mask >= 0; mask--)
        if (!(1 << j & mask))
          dp[i][1 << j | mask] += dp[i - 1][mask];
    }
    for (int mask = (1 << items) - 1; mask >= 0; mask--)
      dp[i][mask] += dp[i - 1][mask];
    //plnarr(dp[i], dp[i] + (1 << items));
  }
  int ans = 0;
  for (int mask = (1 << items) - 1; mask >= 0; mask--)
    if (bitcnt(mask) == need)
      ans += dp[ppl][mask];
  printf("%d\n", ans);
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
  SHOPPERS::solve();
  return 0;
}

