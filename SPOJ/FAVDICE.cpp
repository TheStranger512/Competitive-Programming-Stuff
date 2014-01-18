/* Solved
 * 1026. Favorite Dice
 * File:   FAVDICE.cpp
 * Author: Andy Y.F. Huang
 * Created on April 3, 2013, 6:59 PM
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

namespace FAVDICE {

void solve(int test_num) {
  int n;
  scanf("%d", &n);
  double ans = 0.0;
  for (int i = 0; i < n; i++)
    ans += 1.0 * n / (n - i);
  printf("%.2lf\n", ans);
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
  FAVDICE::solve();
  return 0;
}

