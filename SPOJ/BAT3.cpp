/* Solved
 * 13643. BATMAN3
 * File:   BAT3.cpp
 * Author: Andy Y.F. Huang
 * Created on February 10, 2013, 12:40 AM
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
namespace BAT3 {
int dp[1111], high[1111];

void chmax(int& a, int b) {
  if (b > a) a = b;
}

void solve(int test_num) {
  int peaks, robin;
  scanf("%d %d", &peaks, &robin);
  for (int i = 0; i < peaks; i++)
    scanf("%d", high + i);
  memset(dp, 0xF0, sizeof (dp));
  for (int i = 0; i < peaks; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      if (high[j] > high[i])
        chmax(dp[i], dp[j] + 1);
      else if (j == robin)
        chmax(dp[i], dp[j] + 1);
    }
  }
  printf("%d\n", *max_element(dp, dp + peaks));
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
  BAT3::solve();
  return 0;
}

