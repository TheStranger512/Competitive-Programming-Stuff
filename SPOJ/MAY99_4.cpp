/*
 * Solved
 * 13399. Rachu
 * File:   MAY99_4.cpp
 * Author: Andy Y.F. Huang
 * Created on January 19, 2013, 12:49 PM
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
namespace MAY99_4 {
#define mod 10000007
int dp[111][111];

void solve(int test_num) {
  int muffins, friends;
  scanf("%d %d", &muffins, &friends);
  if (muffins < friends) {
    puts("-1");
    return;
  }
  muffins -= friends;
  memset(dp, 0, sizeof (dp));
  dp[0][0] = 1;
  for (int i = 0; i < friends; i++)
    for (int j = 0; j <= muffins; j++)
      for (int k = 0; j + k <= muffins; k++) {
        dp[i + 1][j + k] += dp[i][j];
        if (dp[i + 1][j + k] >= mod) dp[i + 1][j + k] -= mod;
      }
  printf("%d\n", dp[friends][muffins]);
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
  MAY99_4::solve();
  return 0;
}

