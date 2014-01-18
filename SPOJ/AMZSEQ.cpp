/* Solved
 * 11931. AMZ Word
 * File:   AMZSEQ.cpp
 * Author: Andy Y.F. Huang
 * Created on January 6, 2013, 9:17 PM
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
namespace AMZSEQ {
#define lim 1000000000
int dp[3][5555];

void solve(int test_num) {
  dp[0][1] = dp[1][1] = dp[2][1] = 1;
  for (int i = 1; i < 24 ; i++) {
    dp[0][i + 1] += dp[0][i] + dp[1][i];
    dp[1][i + 1] += dp[0][i] + dp[1][i] + dp[2][i];
    dp[2][i + 1] += dp[1][i] + dp[2][i];
  }
  int n;
  scanf("%d", &n);
  printf("%d\n", dp[0][n] + dp[1][n] + dp[2][n]);
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
  AMZSEQ::solve();
  return 0;
}

