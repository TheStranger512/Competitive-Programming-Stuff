/* Solved
 * 6042. Another Box Problem
 * File:   QCJ2.cpp
 * Author: Andy Y.F. Huang
 * Created on December 9, 2012, 1:39 PM
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
namespace QCJ2 {
#define mod 761238923
int n;
int dp[111][111];

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}

void solve(int test_num) {
  printf("%d\n", dp[n][n]);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  dp[0][0] = 1;
  for (int i = 1; i <= 100; i++)
    for (int k = 0; k <= i; k++)
      for (int j = 0; j <= k; j++)
        add(dp[i][k], dp[i - 1][j]);
  while (true) {
    scanf("%d", &n);
    if (!n) break;
    solve(1);
  }
}
}

int main() {
  QCJ2::solve();
  return 0;
}

