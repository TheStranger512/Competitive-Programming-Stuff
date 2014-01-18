/* Solved
 * Intersection Point
 * File:   HS12INSP.cpp
 * Author: Andy Y.F. Huang
 * Created on October 12, 2012, 12:10 AM
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
namespace HS12INSP {

inline double sqr(double x) {
  return x * x;
}

inline double dist(double x1, double y1, double x2, double y2) {
  return sqr(x1 - x2) + sqr(y1 - y2);
}

void solve(int test_num) {
  double x, y, radius, x1, y1, x2, y2;
  scanf("%lf %lf %lf %lf %lf %lf %lf", &x, &y, &radius, &x1, &y1, &x2, &y2);
  radius *= radius;
  if (dist(x2, y2, x, y) <= radius) {
    swap(x1, x2);
    swap(y1, y2);
  }
  double left = 0, right = 1, mid;
  const double dx = x2 - x1, dy = y2 - y1;
  for (int iters = 0; iters < 100; iters++) {
    mid = (left + right) / 2;
    if (dist(x1 + mid * dx, y1 + mid * dy, x, y) <= radius)
      left = mid;
    else
      right = mid;
  }
  printf("%.2lf %.2lf\n", x1 + left * dx, y1 + left * dy);
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
  HS12INSP::solve();
  return 0;
}

