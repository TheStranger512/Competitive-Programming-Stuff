/*
 * Solved
 * 10415. Dracula
 * File:   DRACULA.cpp
 * Author: Andy Y.F. Huang
 * Created on March 22, 2013, 10:12 PM
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

namespace DRACULA {
typedef long long llong;
llong dp[23][200][2]; //[pos, sum, less]
int digit[25];
llong temp[200], cnt[200];

void go(llong upto, llong *res) {
  memset(dp, 0, sizeof (dp));
  int len = 0;
  for (llong t = upto; t > 0; t /= 10)
    digit[len++] = t % 10;
  reverse(digit, digit + len);
  for (int d = 0; d < digit[0]; d++)
    dp[0][d][1]++;
  dp[0][digit[0]][0] = 1;
  for (int i = 1, lim = 9; i < len; i++, lim += 9) {
    for (int sum = 0; sum <= lim; sum++) {
      for (int d = 0; d < 10; d++) {
        dp[i][sum + d][1] += dp[i - 1][sum][1];
        if (d < digit[i])
          dp[i][sum + d][1] += dp[i - 1][sum][0];
        if (d == digit[i])
          dp[i][sum + d][0] += dp[i - 1][sum][0];
      }
    }
  }
  for (int i = 0; i < 155; i++)
    res[i] = dp[len - 1][i][1];
}

void solve(int test_num) {
  llong from, to, coins;
  scanf("%lld %lld %lld", &from, &to, &coins);
  to++;
  go(from, temp);
  go(to, cnt);
  //plnarr(x, x + 50);
  //plnarr(y, y + 50);
  for (int i = 0; i < 153; i++)
    cnt[i] -= temp[i];
  //plnarr(cnt, cnt + 50);
  llong ans = 0;
  for (int s = 1; s < 155 && coins > 0; s++) {
    llong amount = min(coins / s, cnt[s]);
    coins -= amount * s;
    ans += amount;
  }
  printf("%lld\n", ans);
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
  DRACULA::solve();
  return 0;
}

