/* Solved
 * 8670. THE MAX LINES
 * File:   MAXLN.cpp
 * Author: Andy Y.F. Huang
 * Created on September 21, 2012, 8:20 PM
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
namespace MAXLN {

void solve(int test_num) {
  int radius;
  scanf("%d", &radius);
  printf("Case %d: %.2lf\n", test_num, 4LL * radius * radius + 0.25);
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
  MAXLN::solve();
  return 0;
}

