/*
 * Solved
 * Polo the Penguin and the Test
 * File:   PPTEST.cpp
 * Author: Andy Y.F. Huang
 * Created on Oct 20, 2013, 12:14:51 PM
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

using namespace std;

namespace PPTEST {
int v[111], t[111], dp[111];

void solve(int test_num) {
  int N, W;
  cin >> N >> W;
  for (int i = 0, c, p; i < N; i++) {
    cin >> c >> p >> t[i];
    v[i] = c * p;
  }
  memset(dp, 0xC0, sizeof(dp));
  dp[0] = 0;
  for (int i = 0; i < N; i++) {
    for (int j = W; j >= t[i]; j--)
      dp[j] = max(dp[j], dp[j - t[i]] + v[i]);
  }
  cout << *max_element(dp, dp + W + 1) << endl;
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
  PPTEST::solve();
  return 0;
}
