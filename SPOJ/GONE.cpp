/* Solved
 * 10790. G-One Numbers
 * File:   GONE.cpp
 * Author: Andy Y.F. Huang
 * Created on April 1, 2013, 4:07 PM
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

namespace GONE {
#define LESS 1
#define NOTLESS 0
const int primes[22] = {
                      2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
                      31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79
};
int dp[11][80][2];
int digit[11];

int go(int upto) {
  if (upto == 0) return 0;
  int len = 0;
  for (int t = upto; t > 0; t /= 10)
    digit[len++] = t % 10;
  reverse(digit, digit + len);
  memset(dp, 0, sizeof (dp));
  for (int d = 0; d < digit[0]; d++)
    dp[0][d][LESS] = 1;
  dp[0][digit[0]][NOTLESS] = 1;
  for (int i = 1; i < len; i++) {
    for (int s = 0; s < 70; s++) {
      for (int d = 0; d < 10; d++) {
        dp[i][s + d][LESS] += dp[i - 1][s][LESS];
        if (d == digit[i])
          dp[i][s + d][NOTLESS] += dp[i - 1][s][NOTLESS];
        else if (d < digit[i])
          dp[i][s + d][LESS] += dp[i - 1][s][NOTLESS];
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < 22; i++)
    ans += dp[len - 1][primes[i]][LESS];
  return ans;
}

void solve(int test_num) {
  int from, to;
  cin >> from >> to;
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
  GONE::solve();
  return 0;
}

