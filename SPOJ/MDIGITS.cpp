/* Solved
 * 3928. Counting Digits
 * File:   MDIGITS.cpp
 * Author: Andy Y.F. Huang
 * Created on April 28, 2013, 3:08 PM
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

namespace MDIGITS {
#define LESS 1
#define NOTLESS 0
int dp[11][11][2]; //pos, count, less
int digits[11];
int A, B;

int go(int num, int dig) {
  int len = 0;
  for (int t = num; t > 0; t /= 10)
    digits[len++] = t % 10;
  reverse(digits, digits + len);
  memset(dp, 0, sizeof (dp));
  for (int d = 1; d < digits[0]; d++)
    dp[0][d == dig][LESS]++;
  for (int i = 0, cnt = 0; i < len; i++) {
    if (digits[i] == dig) cnt++;
    dp[i][cnt][NOTLESS]++;
  }
  for (int i = 1; i < len; i++) {
    for (int c = 0; c <= i; c++) //count of target digit
      for (int d = 0; d < 10; d++) { //digit to append
        int nc = c + (d == dig);
        dp[i][nc][LESS] += dp[i - 1][c][LESS];
        if (d < digits[i])
          dp[i][nc][LESS] += dp[i - 1][c][NOTLESS];
      }
    for (int d = 1; d < 10; d++)
      dp[i][d == dig][LESS]++;
  }
  int ans = 0;
  for (int c = 1; c <= len; c++)
    ans += c * dp[len - 1][c][LESS];
  return ans;
}

void solve(int test_num) {
  if (A > B) swap(A, B);
  for (int d = 0; d < 10; d++)
    printf("%d ", go(B + 1, d) - go(A, d));
  putchar('\n');
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (scanf("%d %d", &A, &B) != EOF)
    if (A + B > 0)
      solve(1);
}
}

int main() {
  MDIGITS::solve();
  return 0;
}

