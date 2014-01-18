/* Solved
 * 8044. Fantastic Discovery - binary search
 * File:   IMMERSED.cpp
 * Author: Andy Y.F. Huang
 * Created on August 31, 2012, 12:26 AM
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
namespace IMMERSED {

void solve(int test_num) {
  long long cells;
  int c;
  scanf("%lld %d", &cells, &c);
  double high = 13, low = 1e-6;
  for (int i = 0; i < 25; i++) {
    double mid = (high + low) / 2.0;
    if (pow(mid, c * mid + 1) > cells)
      high = mid;
    else
      low = mid;
  }
  printf("%.7lf\n", low);
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
  IMMERSED::solve();
  return 0;
}

