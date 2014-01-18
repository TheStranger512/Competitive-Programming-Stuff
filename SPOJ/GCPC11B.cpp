/* Solved
 * 9118. Genetic Fraud
 * File:   GCPC11B.cpp
 * Author: Andy Y.F. Huang
 * Created on January 19, 2013, 6:14 PM
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

namespace GCPC11B {
int table[1111];
char a[1111], b[1111];
int len;
int dp[2][1111];

void solve(int test_num) {
  scanf("%d %s %s", &len, a + 1, b + 1);
  int* cur = dp[1], *prev = dp[0];
  int ans = 0;
  memset(prev, 0, sizeof (dp[0]));
  for (int i = 1; i <= len; i++, swap(cur, prev)) {
    for (int j = 1; j <= len; j++)
      if (abs(a[i] - b[j]) <= 1)
        cur[j] = 1 + prev[j - 1];
      else
        cur[j] = 0;
    ans = max(ans, *max_element(cur, cur + len + 1));
  }
  if (ans >= (len + 1) / 2)
    puts("POSITIVE");
  else puts("NEGATIVE");
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
  GCPC11B::solve();
  return 0;
}

