/* Solved
 * 3979. Whirligig number
 * File:   MZVRK.cpp
 * Author: Andy Y.F. Huang
 * Created on June 1, 2013, 11:31 PM
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

namespace MZVRK {
#define LESS 1
#define NOTLESS 0
typedef long long llong;
llong dp[55][55][2];
//len, last bit from MSB, less
int digit[55];

llong go(llong upto) {
  //sum of whirlgig < upto
  //lowbit = len - lastbit - 1
  int len = 0;
  for (int t = upto; t > 0; t >>= 1)
    digit[len++] = t & 1;
  reverse(digit, digit + len);
  //plnarr(digit, digit + len);
  memset(dp, 0, sizeof (dp));
  for (int i = 0, last = 0; i < len; i++) {
    if (digit[i] == 1)
      last = i;
    dp[i][last][NOTLESS] = 1;
  }
  for (int i = 1; i < len; i++) {
    for (int la = 0; la < i; la++) {
      //add one bit
      dp[i][i][LESS] += dp[i - 1][la][LESS];
      //add zero bit
      dp[i][la][LESS] += dp[i - 1][la][LESS];
      if (digit[i] == 1)
        dp[i][la][LESS] += dp[i - 1][la][NOTLESS];
    }
    dp[i][i][LESS]++;
  }
  llong sum = 0;
  for (int i = 0; i < len; i++) {
    //pln(dp[len - 1][i][LESS]);
    sum += dp[len - 1][i][LESS] * (1LL << (len - i - 1));
  }
  return sum;
}

void solve(int test_num) {
  llong A, B;
  cin >> A >> B;
  cout << go(B + 1) - go(A) << endl;
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
  MZVRK::solve();
  return 0;
}

