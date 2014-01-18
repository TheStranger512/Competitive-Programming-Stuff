/* Solved
 * 4200. Hamster flight
 * File:   HAMSTER1.cpp
 * Author: Andy Y.F. Huang
 * Created on August 17, 2012, 10:02 PM
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
namespace HAMSTER1 {
const double k_pi = acos(-1.0), k_accel = 10.0;

double val(int velocity, int k1, int k2, double angle) {
  double vy = velocity * sin(angle);
  double maxh = vy * vy  / (k_accel * 2.0);
  double dist = velocity * cos(angle) * vy * 2.0 / k_accel;
  return k1 * dist + k2 * maxh;
}

void solve(int test_num) {
  int velocity, k1, k2;
  scanf("%d %d %d", &velocity, &k1, &k2);
  double left = 0.0, right = k_pi / 2.0;
  for (int iters = 0; iters < 100; iters++) {
    double a = (2 * left + right) / 3.0;
    double b = (left + 2 * right) / 3.0;
    if (val(velocity, k1, k2, a) < val(velocity, k1, k2, b))
      left = a;
    else
      right = b;
  }
  printf("%.3f %.3f\n", left, val(velocity, k1, k2, left));
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
  HAMSTER1::solve();
  return 0;
}

