/* Solved
 * 2716. Maximal Quadrilateral Area
 * File:   QUADAREA.cpp
 * Author: Andy Y.F. Huang
 * Created on December 24, 2012, 5:39 PM
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

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace QUADAREA {

void solve(int test_num) {
  double a, b, c, d;
  scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
  double s = 0.5 * (a + b + c + d);
  printf("%.2lf\n", sqrt((s - a) * (s - b) * (s - c) * (s - d)));
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
  QUADAREA::solve();
  return 0;
}

