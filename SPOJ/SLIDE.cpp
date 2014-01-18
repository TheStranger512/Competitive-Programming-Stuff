/* Solved
 * 15073. Team Slide Treasure Hunt Race
 * File:   SLIDE.cpp
 * Author: Andy Y.F. Huang
 * Created on May 30, 2013, 10:00 PM
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

namespace SLIDE {
int dp[12][12];
int prev[12][12];
int gold[12];

void chmax(int& a, int b) {
  if (b > a) a = b;
}

void solve(int test_num) {
  int rows, cols;
  scanf("%d %d", &rows, &cols);
  for (int i = 1; i <= cols; i++)
    scanf("%d", gold + i);
  memset(prev, 0xF0, sizeof (prev));
  prev[1][cols] = gold[1] + gold[cols];
  for (int r = 2; r <= rows; r++) {
    for (int c = 1; c <= cols; c++)
      scanf("%d", gold + c);
    memset(dp, 0xF0, sizeof (dp));
    for (int a = 1; a <= cols; a++)
      for (int b = a + 1; b <= cols; b++) {
        chmax(dp[a - 1][b - 1], prev[a][b] + gold[a - 1] + gold[b - 1]);
        chmax(dp[a - 1][b], prev[a][b] + gold[a - 1] + gold[b]);
        chmax(dp[a - 1][b + 1], prev[a][b] + gold[a - 1] + gold[b + 1]);
        if (b - 1 > a)
          chmax(dp[a][b - 1], prev[a][b] + gold[a] + gold[b - 1]);
        chmax(dp[a][b], prev[a][b] + gold[a] + gold[b]);
        chmax(dp[a][b + 1], prev[a][b] + gold[a] + gold[b + 1]);
        if (a + 1 < b - 1)
          chmax(dp[a + 1][b - 1], prev[a][b] + gold[a + 1] + gold[b - 1]);
        if (a + 1 < b)
          chmax(dp[a + 1][b], prev[a][b] + gold[a + 1] + gold[b]);
        chmax(dp[a + 1][b + 1], prev[a][b] + gold[a + 1] + gold[b + 1]);
      }
    memcpy(prev, dp, sizeof (prev));
  }
  printf("%d\n", dp[1][cols]);
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
  SLIDE::solve();
  return 0;
}

