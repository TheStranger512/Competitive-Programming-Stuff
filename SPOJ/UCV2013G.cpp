/* Solved
 * 15435. Schedules
 * File:   UCV2013G.cpp
 * Author: Andy Y.F. Huang
 * Created on July 24, 2013, 4:25 PM
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

namespace UCV2013G {
#define INF 0x3f3f3f3f
int a[222], b[222];
int left, right, lim;
bool can[222][222];
int dp[222][222];
int take[222][222];

int read() {
  int h, m, s;
  scanf("%d:%d:%d", &h, &m, &s);
  return h * 3600 + m * 60 + s;
}

void solve(int test_num) {
  //assert(left + right <= 400);
  for (int i = 1; i <= left; i++)
    a[i] = read();
  for (int i = 1; i <= right; i++)
    b[i] = read();
  sort(a, a + left);
  sort(b, b + right);
  for (int i = 1; i <= left; i++)
    for (int j = 1; j <= right; j++)
      can[i][j] = abs(a[i] - b[j]) <= lim;
  memset(dp, 0, sizeof (dp));
  memset(take, 0, sizeof (take));
  for (int i = 1; i <= left; i++) {
    for (int j = 1; j <= right; j++) {
      dp[i][j] = dp[i - 1][j];
      take[i][j] = take[i - 1][j];
      if (dp[i][j - 1] > dp[i][j]) {
        dp[i][j] = dp[i][j - 1];
        take[i][j] = INF;
      }
      if (dp[i][j - 1] == dp[i][j])
        take[i][j] = min(take[i][j], take[i][j - 1]);
      if (can[i][j]) {
        int ntake = take[i - 1][j - 1] + abs(a[i] - b[j]);
        int matches = dp[i - 1][j - 1] + 1;
        if (matches > dp[i][j]) {
          dp[i][j] = matches;
          take[i][j] = INF;
        }
        if (matches == dp[i][j])
          take[i][j] = min(take[i][j], ntake);
      }
    }
  }
  if (dp[left][right] == 0)
    puts("No matches");
  else
    printf("%d %.1lf\n", dp[left][right], 1.0 * take[left][right] / dp[left][right]);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (scanf("%d %d %d", &left, &right, &lim) != EOF)
    if (left + right + lim > 0)
      solve(1);
}
}

int main() {
  UCV2013G::solve();
  return 0;
}

