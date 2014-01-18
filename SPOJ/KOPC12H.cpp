/* Solved
 * 10522. K12-OE Numbers
 * File:   KOPC12H.cpp
 * Author: Andy Y.F. Huang
 * Created on April 28, 2013, 9:14 PM
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

namespace KOPC12H {
#define pos(x) (x+75)
#define LESS 1
#define NOTLESS 0
int dp[10][150][2];
int digit[10];

int go(int upto) {
  int len = 0;
  for (int t = upto; t > 0; t /= 10)
    digit[len++] = t % 10;
  reverse(digit, digit + len);
  memset(dp, 0, sizeof (dp));
  for (int d = 0; d < digit[0]; d++)
    dp[0][(d & 1) ? pos(-d) : pos(d)][LESS]++;
  for (int i = 0, sum = 0; i < len; i++) {
    if (digit[i] & 1) sum -= digit[i];
    else sum += digit[i];
    dp[i][pos(sum)][NOTLESS]++;
  }
  for (int i = 1; i < len; i++) {
    for (int s = pos(-9 * i), ns; s <= pos(9 * i); s++) {
      if (dp[i - 1][s][LESS] + dp[i - 1][s][NOTLESS] == 0)
        continue;
      for (int d = 0; d < 10; d++) {
        ns = s + (d & 1 ? -d : d);
        dp[i][ns][LESS] += dp[i - 1][s][LESS];
        if (d < digit[i])
          dp[i][ns][LESS] += dp[i - 1][s][NOTLESS];
      }
    }
  }
  int res = 0;
  for (int s = 1; s < 75; s++)
    res += dp[len - 1][pos(s)][LESS];
  return res;
}

void solve(int test_num) {
  int A, B;
  scanf("%d %d", &A, &B);
  printf("%d\n", go(B + 1) - go(A));
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
  KOPC12H::solve();
  return 0;
}

