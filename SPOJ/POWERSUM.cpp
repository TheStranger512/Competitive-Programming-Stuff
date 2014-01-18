/* Solved
 * 12348. Sum of Subsets
 * File:   POWERSUM.cpp
 * Author: Andy Y.F. Huang
 * Created on October 8, 2012, 6:24 PM
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
namespace POWERSUM {
const int k_mod = 1000000007;

int fpow(int base, int expon) {
  long long ans = 1, temp = base;
  while (expon > 0) {
    if (expon & 1)
      ans = ans * temp % k_mod;
    temp = temp * temp % k_mod;
    expon >>= 1;
  }
  return (int) ans;
}

void solve(int test_num) {
  int sum = 0, len, val;
  scanf("%d", &len);
  for (int i = 0; i < len; i++) {
    scanf("%d", &val);
    sum += val;
    sum %= k_mod;
  }
  printf("%lld\n", 1LL * sum * fpow(2, len - 1) % k_mod);
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
  POWERSUM::solve();
  return 0;
}

