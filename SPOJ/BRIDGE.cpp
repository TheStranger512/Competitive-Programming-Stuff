/* Solved
 * 6168. Building Bridges
 * File:   BRIDGE.cpp
 * Author: Andy Y.F. Huang
 * Created on April 27, 2013, 10:28 PM
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

namespace BRIDGE {
pair<int, int> pos[1111];
int dp[1111];

void solve(int test_num) {
  memset(dp, 0, sizeof (dp));
  int len;
  scanf("%d", &len);
  for (int i = 0; i < len; i++)
    scanf("%d", &pos[i].first);
  for (int i = 0; i < len; i++)
    scanf("%d", &pos[i].second);
  sort(pos, pos + len);
  for (int i = 0; i < len; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++)
      if (pos[j].first <= pos[i].first && pos[j].second <= pos[i].second)
        dp[i] = max(dp[i], 1 + dp[j]);
  }
  printf("%d\n", *max_element(dp, dp + len));
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
  BRIDGE::solve();
  return 0;
}

