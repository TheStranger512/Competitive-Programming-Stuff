/* Solved
 * 9494. Just Add It
 * File:   ZSUM.cpp
 * Author: Andy Y.F. Huang
 * Created on January 3, 2013, 11:36 PM
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
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <iomanip>
#include <cassert>
#include <ctime>
#include <functional>
#include <complex>
#include <numeric>
#include <cctype>
#include <cstddef>
#include <utility>
#include <valarray>
#include <cstdlib>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace ZSUM {
#define mod 10000007
int n, k;

int fpow(int base, int expon) {
  long long ans = 1, temp = base;
  for (int e = expon; e > 0; e >>= 1) {
    if (e & 1) ans = ans * temp % mod;
    temp = temp * temp % mod;
  }
  return (int) ans;
}

void solve(int test_num) {
  printf("%d\n", (2 * fpow(n - 1, n - 1) + fpow(n, n) + fpow(n, k) + 2 * fpow(n - 1, k)) % mod);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (true) {
    scanf("%d %d", &n, &k);
    if (n == 0) break;
    solve(1);
  }
}
}

int main() {
  ZSUM::solve();
  return 0;
}

