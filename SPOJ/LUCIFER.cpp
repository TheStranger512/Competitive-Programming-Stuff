/* Solved
 * 10968. LUCIFER Number
 * File:   LUCIFER.cpp
 * Author: Andy Y.F. Huang
 * Created on April 22, 2013, 12:22 AM
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

namespace LUCIFER {
#define pos(x) (x+50)
#define LESS 1
#define NOTLESS 0
const int primes[15] = {
                      2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
                      31, 37, 41, 43, 47};
int dp[11][121][2]; //pos, sum + 50, less
int digit[11];

int go(int upto) {
  //even pos digits - odd pos digits, counting ones place
  memset(dp, 0, sizeof (dp));
  int len = 0;
  if (upto == 0) return 0;
  for (int t = upto; t > 0; t /= 10)
    digit[len++] = t % 10;
  reverse(digit, digit + len);
  for (int d = 0; d < digit[0]; d++) {
    if (len & 1) dp[0][pos(-d)][LESS] = 1;
    else dp[0][pos(d)][LESS] = 1;
  }
  if (len & 1)
    dp[0][pos(-digit[0])][NOTLESS] = 1;
  else
    dp[0][pos(digit[0])][NOTLESS] = 1;
  for (int i = 1; i < len; i++) {
    for (int s = -50; s <= 50; s++) {
      for (int d = 0; d < 10; d++) {
        int npos = ((len - i) & 1) ? pos(s - d) : pos(s + d);
        dp[i][npos][LESS] += dp[i - 1][pos(s)][LESS];
        if (d == digit[i])
          dp[i][npos][NOTLESS] += dp[i - 1][pos(s)][NOTLESS];
        else if (d < digit[i])
          dp[i][npos][LESS] += dp[i - 1][pos(s)][NOTLESS];
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < 15; i++)
    ans += dp[len - 1][pos(primes[i])][LESS];
  return ans;
}

void solve(int test_num) {
  int from, to;
  scanf("%d %d", &from, &to);
  cout << go(to + 1) - go(from) << endl;
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
  LUCIFER::solve();
  return 0;
}

