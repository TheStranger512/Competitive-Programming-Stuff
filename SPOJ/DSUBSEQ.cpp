/* Solved
 * 2416. Distinct Subsequences
 * File:   DSUBSEQ.cpp
 * Author: Andy Y.F. Huang
 * Created on February 2, 2013, 12:10 PM
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
namespace DSUBSEQ {
#define mod 1000000007
char str[111000];
int dp[111000];
int last[27];

void solve(int test_num) {
  scanf("%s", str + 1);
  int len = strlen(str + 1);
  dp[0] = 1;
  memset(last, 0, sizeof (last));
  for (int i = 1; i <= len; i++) {
    dp[i] = dp[i - 1] << 1;
    if (last[str[i] - 'a'])
      dp[i] -= dp[last[str[i] - 'a'] - 1];
    dp[i] = (dp[i] + mod) % mod;
    last[str[i] - 'a'] = i;
  }
  printf("%d\n", dp[len]);
}

void solve(int test_num) { }

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
  DSUBSEQ::solve();
  return 0;
}

