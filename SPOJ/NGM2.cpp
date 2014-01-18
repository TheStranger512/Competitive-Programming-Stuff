/* Solved
 * 6285. Another Game With Numbers
 * File:   NGM2.cpp
 * Author: Andy Y.F. Huang
 * Created on March 28, 2013, 7:49 PM
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

namespace NGM2 {
typedef long long llong;
int num[22];

llong gcd(llong a, llong b) {
  return b == 0 ? a : gcd(b, a % b);
}

void solve(int test_num) {
  int upto, len;
  scanf("%d %d", &upto, &len);
  for (int i = 0; i < len; i++)
    scanf("%d", num + i);
  sort(num, num + len);
  int ans = 0;
  for (int mask = 1; mask < (1 << len); mask++) {
    llong lcm = 1;
    for (int bit = 0; bit < len; bit++)
      if (1 << bit & mask)
        lcm *= num[bit] / gcd(lcm, num[bit]);
    if (__builtin_popcount(mask) & 1) ans += upto / lcm;
    else ans -= upto / lcm;
  }
  printf("%d\n", upto - ans);
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
  NGM2::solve();
  return 0;
}

