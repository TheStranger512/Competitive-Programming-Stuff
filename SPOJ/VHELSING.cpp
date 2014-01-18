/* Solved
 * 10416. Van Helsings gun
 * File:   VHELSING.cpp
 * Author: Andy Y.F. Huang
 * Created on August 25, 2012, 3:21 PM
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
namespace VHELSING {
const double k_azn = 4.68629150101523972438;

void solve(int test_num) {
  int r;
  scanf("%d", &r);
  printf("%.4f\n", k_azn * r * r * r);
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
  VHELSING::solve();
  return 0;
}

