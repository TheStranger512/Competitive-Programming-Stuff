/* Solved
 * 11103. PrimeFactorofLCM
 * File:   MAIN12B.cpp
 * Author: Andy Y.F. Huang
 * Created on April 22, 2013, 12:36 AM
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

namespace MAIN12B {
long long ans[11111];
int primes[88888], pcnt;

void solve(int test_num) {
  int len, anslen = 0;
  scanf("%d", &len);
  for (int i = 0; i < len; i++) {
    long long num;
    scanf("%lld", &num);
    for (int j = 0; j < pcnt && num > 1 && primes[j] <= num / primes[j]; j++) {
      bool ok = false;
      if (num % primes[j] == 0) {
        ok = true;
        while (num % primes[j] == 0)
          num /= primes[j];
      }
      if (ok) ans[anslen++] = primes[j];
    }
    if (num > 1) ans[anslen++] = num;
  }
  sort(ans, ans + anslen);
  anslen = unique(ans, ans + anslen) - ans;
  printf("Case #%d: %d\n", test_num, anslen);
  for (int i = 0; i < anslen; i++)
    printf("%lld\n", ans[i]);
}

void init() {
  static bool sieve[1 << 20];
  memset(sieve, false, sizeof (sieve));
  int i;
  pcnt = 0;
  for (i = 2; i <= 1000; i++)
    if (!sieve[i]) {
      primes[pcnt++] = i;
      for (int j = i * i; j <= 1000000; j += i)
        sieve[j] = true;
    }
  for (; i < 1000000; i++)
    if (!sieve[i])
      primes[pcnt++] = i;
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  init();
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  MAIN12B::solve();
  return 0;
}

