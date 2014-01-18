/* Solved
 * 15061. World Cup 2010
 * File:   GCJ102B.cpp
 * Author: Andy Y.F. Huang
 * Created on May 29, 2013, 6:44 PM
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

namespace GCJ102B {
int dp[2222][15];
//min cost at subtree rooted at i such that there must be j more buys above
int cost[2222];
int most[1111];

void chmin(int& a, int b) {
  if (b < a) a = b;
}

void solve(int test_num) {
  int rounds, len;
  scanf("%d", &rounds);
  len = 1 << rounds;
  for (int i = len - 1; i >= 0; i--)
    scanf("%d", most + i);
  for (int i = len - 1; i > 0; i--)
    scanf("%d", cost + i);
  memset(dp, 0x3F, sizeof (dp));
  for (int i = 0; i < len; i++)
    dp[i + len][rounds - most[i]] = 0;
  for (int i = len - 1; i > 0; i--) {
    int* l = dp[i << 1], *r = dp[i << 1 | 1];
    for (int a = 0; a <= rounds; a++)
      for (int b = 0; b <= rounds; b++) {
        //dont buy this round
        chmin(dp[i][max(a, b)], l[a] + r[b]);
        //buy this round
        if (a + b > 0)
          chmin(dp[i][max(a, b) - 1], l[a] + r[b] + cost[i]);
      }
  }
  //plnarr(dp, len + len, rounds + 1);
  //pln();
  printf("Case #%d: %d\n", test_num, dp[1][0]);
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
  GCJ102B::solve();
  return 0;
}

