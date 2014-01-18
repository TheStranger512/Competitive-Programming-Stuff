/* Solved
 * 14955. Dancing Cows
 * File:   DCOWS.cpp
 * Author: Andy Y.F. Huang
 * Created on May 29, 2013, 5:31 PM
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

namespace DCOWS {
int b[5555], c[5555];
long long dp[2][5555];

void solve(int test_num) {
  int bulls, cows;
  scanf("%d %d", &bulls, &cows);
  for (int i = 1; i <= bulls; i++)
    scanf("%d", b + i);
  for (int i = 1; i <= cows; i++)
    scanf("%d", c + i);
  sort(b + 1, b + bulls + 1);
  sort(c + 1, c + cows + 1);
  //plnarr(b, b + bulls);
  //plnarr(c, c + cows);
  memset(dp, 0, sizeof (dp));
  long long* cur = dp[1], *prev = dp[0];
  for (int bb = 1; bb <= bulls; bb++, swap(cur, prev)) {
    cur[0] = 1LL << 50;
    for (int cc = 1; cc <= cows; cc++)
      cur[cc] = min(cur[cc - 1], prev[cc - 1] + abs(b[bb] - c[cc]));
  }
  printf("%lld\n", prev[cows]);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  solve(1);
}
}

int main() {
  DCOWS::solve();
  return 0;
}

