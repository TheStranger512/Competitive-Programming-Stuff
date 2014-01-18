/*
 * Solved
 * 13925. ZEROES IN RANGE V2
 * File:   RANGZER2.cpp
 * Author: Andy Y.F. Huang
 * Created on March 4, 2013, 10:19 PM
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
namespace RANGZER2 {
char str[15];
int dp[12][12][2]; //[pos, zeroes, less]

int go(int upto) {
  sprintf(str, "%d", upto);
  memset(dp, 0, sizeof (dp));
  int len = strlen(str);
  for (char d = '1'; d < str[0]; d++)
    dp[0][d == '0'][1]++;
  dp[0][str[0] == '0'][0]++;
  for (int i = 1; i < len; i++) {
    for (char d = '0'; d <= '9'; d++) {
      for (int z = 0; z < 10; z++) {
        dp[i][z + (d == '0')][1] += dp[i - 1][z][1];
        if (d < str[i])
          dp[i][z + (d == '0')][1] += dp[i - 1][z][0];
        else if (d == str[i])
          dp[i][z + (d == '0')][0] += dp[i - 1][z][0];
      }
      if (d > '0')
        dp[i][0][1]++;
    }
  }
  int ans = 0;
  for (int z = 1; z < 10; z++)
    ans += z * dp[len - 1][z][1];
  return ans;
}

void solve(int test_num) {
  int from, to;
  scanf("%d %d", &from, &to);
  printf("%d\n", go(to + 1) - go(from));
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
  RANGZER2::solve();
  return 0;
}

