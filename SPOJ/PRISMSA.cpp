/* Solved
 * 8371. TRIANGULAR PRISM - calculus math
 * differentiate the surface area function in terms of side length
 * File:   PRISMSA.cpp
 * Author: Andy Y.F. Huang
 * Created on September 3, 2012, 4:43 PM
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
namespace PRISMSA {

void solve(int test_num) {
  int volume;
  scanf("%d", &volume);
  double side = pow(volume << 2, 1 / 3.0);
  printf("%.6lf\n", (3 * side * side * side / 2.0 + 12 * volume) / (side * sqrt(3)));
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
  PRISMSA::solve();
  return 0;
}

