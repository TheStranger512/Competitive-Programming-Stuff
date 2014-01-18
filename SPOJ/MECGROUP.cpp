/* Solved
 * 10377. project groups
 * File:   MECGROUP.cpp
 * Author: Andy Y.F. Huang
 * Created on January 3, 2013, 3:36 PM
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
namespace MECGROUP {
int comb[33][33];

void solve(int test_num) {
  int boys, girls, size;
  scanf("%d %d %d", &boys, &girls, &size);
  long long ans = 0;
  for (int g = 1; g <= girls; g++)
    if (size - g >= 4 && size - g <= boys)
      ans += 1LL * comb[girls][g] * comb[boys][size - g];
  printf("%lld\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  comb[0][0] = 1;
  for (int i = 1; i <= 30; i++) {
    comb[i][0] = 1;
    for (int j = 1; j <= i; j++)
      comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
  }
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  MECGROUP::solve();
  return 0;
}

