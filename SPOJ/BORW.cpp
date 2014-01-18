/*
 * Solved
 * 7208. Black or White
 * File:   BORW.cpp
 * Author: Andy Y.F. Huang
 * Created on January 24, 2013, 9:41 PM
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
namespace BORW {
int len;
int seq[222];
int dp[222][222][222]; //len, inc end val is j, dec end val is i
int vals[222];

void solve(int test_num) {
  int vallen = 2;
  vals[0] = 0;
  vals[1] = 1 << 20;
  for (int i = 1; i <= len; i++) {
    scanf("%d", &seq[i]);
    vals[vallen++] = seq[i];
  }
  if (len <= 2) {
    puts("0");
    return;
  }
  sort(vals, vals + vallen);
  vallen = unique(vals, vals + vallen) - vals;
  for (int i = 1; i <= len; i++)
    for (int a = 0; a < vallen; a++)
      for (int b = 0; b < vallen; b++)
        dp[i][a][b] = -(1 << 15);
  dp[0][0][vallen - 1] = 0;
  for (int i = 1; i <= len; i++) {
    seq[i] = lower_bound(vals, vals + vallen, seq[i]) - vals;
    for (int a = 0; a < vallen; a++)
      for (int b = 0; b < vallen; b++) {
        if (a < seq[i])
          dp[i][seq[i]][b] = max(dp[i][seq[i]][b], dp[i - 1][a][b] + 1);
        if (seq[i] < b)
          dp[i][a][seq[i]] = max(dp[i][a][seq[i]], dp[i - 1][a][b] + 1);
        dp[i][a][b] = max(dp[i][a][b], dp[i - 1][a][b]);
      }
  }
  int ans = 0;
  for (int a = 0; a < vallen; a++)
    for (int b = 0; b < vallen; b++)
      ans = max(ans, dp[len][a][b]);
  printf("%d\n", len - ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (true) {
    scanf("%d", &len);
    if (len == -1) break;
    solve(1);
  }
}
}

int main() {
  BORW::solve();
  return 0;
}

