/* Solved
 * 14871. STUDENTS
 * File:   AU7_5.cpp
 * Author: Andy Y.F. Huang
 * Created on May 27, 2013, 10:46 PM
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

namespace AU7_5 {
#define MOD 5000011
int dp[111000];

void solve(int test_num) {
  int len, girls;
  scanf("%d %d", &len, &girls);
  dp[0] = 1;
  for (int i = 1; i <= len; i++) {
    dp[i] = 0;
    dp[i] = dp[max(0, i - girls - 1)];
    dp[i] += dp[i - 1];
    if (dp[i] >= MOD) dp[i] -= MOD;
  }
  printf("%d\n", dp[len]);
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
  AU7_5::solve();
  return 0;
}

