/* Solved
 * 15425. MAKEME2
 * File:   MKME2.cpp
 * Author: Andy Y.F. Huang
 * Created on July 21, 2013, 11:33 PM
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

namespace MKME2 {
int dp[111000];

void solve(int test_num) {
  memset(dp, 0x3F, sizeof (dp));
  int st, ed;
  cin >> st >> ed;
  dp[st] = 0;
  for (int i = st; i < ed; i++) {
    if (dp[i] > ed) continue;
    for (int j = 2; j * j <= i; j++)  {
      if (i % j == 0) {
        if (i + j <= ed)
          dp[i + j] = min(dp[i + j], dp[i] + 1);
        if (i + i / j <= ed)
          dp[i + i / j] = min(dp[i + i / j], dp[i] + 1);
      }
    }
  }
  if (dp[ed] > ed) puts("-1");
  else printf("%d\n", dp[ed]);
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
  MKME2::solve();
  return 0;
}

