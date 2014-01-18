/* Solved
 * 9952. 111 ... 1 Squared
 * File:   GUANGGUN.cpp
 * Author: Andy Y.F. Huang
 * Created on August 26, 2012, 1:30 PM
 */

#include <cstdio>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#endif

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace GUANGGUN {
typedef unsigned long long ull;

void solve(int test_num, ull n) {
  printf("%llu\n", n / 9 * 81LL + (n % 9) * (n % 9));
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  ull n;
  while (scanf("%llu\n", &n) != EOF)
    solve(1, n);
}
}

int main() {
  GUANGGUN::solve();
  return 0;
}

