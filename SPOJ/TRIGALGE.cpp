/* Solved
 * 10712. Easy Calculation
 * File:   TRIGALGE.cpp
 * Author: Andy Y.F. Huang
 * Created on January 2, 2013, 1:15 PM
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
namespace TRIGALGE {

void solve(int test_num) {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  double low = -1e10, high = 1e10;
  while (abs(high - low) > 1e-6) {
    double mid = (low + high) / 2.0;
    if (a * mid + b * sin(mid) - c < 0)
      low = mid;
    else
      high = mid;
  }
  printf("%.6lf\n", low);
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
  TRIGALGE::solve();
  return 0;
}

