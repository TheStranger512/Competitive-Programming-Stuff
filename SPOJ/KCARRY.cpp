/* Solved
 * 15453. Yet Another Electronic Device!!!
 * File:   KCARRY.cpp
 * Author: Andy Y.F. Huang
 * Created on July 29, 2013, 4:06 AM
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

namespace KCARRY {
#define MOD 1000000007
int dp[1011][1011][2]; //len, carries, have carry

void solve(int test_num) {
  int N, K;
  scanf("%d %d", &N, &K);
  printf("%d\n", (dp[N][K][0] + dp[N][K][1]) % MOD);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  dp[0][0][0] = 1;
  for (int i = 1; i <= 1000; i++) {
    dp[i][0][0] = 55LL * dp[i - 1][0][0] % MOD;
    for (int j = 1; j <= i; j++) {
      dp[i][j][0] = (55LL * dp[i - 1][j][0] + 45LL * dp[i - 1][j][1]) % MOD;
      dp[i][j][1] = (45LL * dp[i - 1][j - 1][0] + 55LL * dp[i - 1][j - 1][1]) % MOD;
    }
  }
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  KCARRY::solve();
  return 0;
}

