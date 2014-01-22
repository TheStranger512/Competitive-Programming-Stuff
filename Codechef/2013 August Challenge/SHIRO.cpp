/*
 * Solved
 * August Challenge 2013
 * Save The Princess
 * File:   SHIRO.cpp
 * Author: Andy Y.F. Huang
 * Created on August 2, 2013, 11:18 AM
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

namespace SHIRO {
double dp[101][20001], pr[101];
int am[101];

void solve(int test_num) {
  memset(dp, 0, sizeof (dp));
  dp[0][10000] = 1;
  int N;
  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> am[i];
  for (int i = 0; i < N; i++) {
    cin >> pr[i];
    pr[i] /= 100;
    for (int j = -100 * i + 10000; j <= 100 * i + 10000; j++)
      if (dp[i][j] > 0) {
        dp[i + 1][j + am[i]] += pr[i] * dp[i][j];
        dp[i + 1][j - am[i]] += (1.0 - pr[i]) * dp[i][j];
      }
    //plnarr(dp[i + 1] + 9990, dp[i + 1] +  10015);
  }
  double res = 0.0;
  for (int j = 0; j <= 10000; j++)
    res += dp[N][j + 10000];
  printf("%.7lf\n", res);
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
  SHIRO::solve();
  return 0;
}

