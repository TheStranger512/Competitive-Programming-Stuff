/* Solved
 * 10070. Trick or Treat
 * File:   TRICKTRT.cpp
 * Author: Andy Y.F. Huang
 * Created on March 11, 2013, 11:02 PM
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

namespace TRICKTRT {
int len;
double x[55000], y[55000];

double dist(double X) {
  double res = 0;
  for (int i = 0; i < len; i++)
    res = max(res, (x[i] - X) * (x[i] - X) + y[i] * y[i]);
  return res;
}

void solve(int test_num) {
  double low = -2e5, high = 2e5;
  for (int i = 0; i < len; i++) {
    scanf("%lf %lf", x + i, y + i);
    low = min(low, x[i]);
    high = max(high, x[i]);
    if (y[i] < 0) y[i] = -y[i];
  }
  int iters = 0;
  for (double m1, m2, d1, d2; iters < 50; iters++) {
    m1 = (2 * low + high) / 3;
    m2 = (low + 2 * high) / 3;
    d1 = dist(m1);
    d2 = dist(m2);
    if (d1 > d2) low = m1;
    else high = m2;
  }
  printf("%.6lf %.6lf\n", low, sqrt(dist(low)));
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (true) {
    scanf("%d", &len);
    if (len == 0) break;
    solve(1);
  }
}
}

int main() {
  TRICKTRT::solve();
  return 0;
}

