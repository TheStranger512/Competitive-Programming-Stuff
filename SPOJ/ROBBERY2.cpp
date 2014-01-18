/* Solved
 * 6290. Robbery 2 - math
 * File:   ROBBERY2.cpp
 * Author: Andy Y.F. Huang
 * Created on August 8, 2012, 1:12 PM
 */

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <fstream>
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace ROBBERY2 {
typedef long long int64;

void solve(int test_num) {
  int64 coins, amount[110], len, mod;
  int ppl;
  scanf("%lld %d", &coins, &ppl);
  int64 high = 50000000, low = 1;
  while (low < high) {
    int64 mid = ((high + low) >> 1) + 1;
    int64 sum = (mid * (mid + 1)) >> 1;
    if (sum > coins)
      high = mid - 1;
    else
      low = mid;
  }
  coins -= (low * (low + 1)) >> 1;
  len = low / ppl, mod = low % ppl;
  for (int i = 1; i <= ppl; i++) {
    int64 n = len + (i <= mod);
    amount[i] = n * (2 * i + (n - 1) * ppl) / 2;
  }
  amount[mod + 1] += coins;
  for (int i = 1; i <= ppl; i++)
    printf("%lld ", amount[i]);
  putchar('\n');
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  ROBBERY2::solve();
  return 0;
}

