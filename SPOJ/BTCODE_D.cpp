/* Solved
 * 8422. Maximum Profit
 * File:   BTCODE_D.cpp
 * Author: Andy Y.F. Huang
 * Created on February 16, 2013, 1:08 PM
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

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace BTCODE_D {
int waits[111][111], custs[111][111];
int money[111][111];

void solve(int test_num) {
  int rests, len;
  scanf("%d %d", &rests, &len);
  for (int i = 0; i < rests; i++)
    for (int j = 0; j < len; j++)
      scanf("%d", &waits[i][j]);
  for (int i = 0; i < rests; i++)
    for (int j = 0; j < len; j++)
      scanf("%d", &custs[i][j]);
  for (int i = 0; i < rests; i++)
    for (int j = 0; j < len; j++)
      scanf("%d", &money[i][j]);
  long long ans = 0;
  for (int r = 0; r < rests; r++) {
    long long most = 0;
    for (int i = 0; i < len; i++)
      most = max(most, 1LL * min(waits[r][i], custs[r][i]) * money[r][i]);
    ans += most;
  }
  printf("%lld\n", ans);
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
  BTCODE_D::solve();
  return 0;
}

