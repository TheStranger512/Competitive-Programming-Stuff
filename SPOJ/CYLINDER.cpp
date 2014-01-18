/* Solved
 * 1681. Cylinder
 * File:   CYLINDER.cpp
 * Author: Andy Y.F. Huang
 * Created on April 23, 2013, 9:58 PM
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

namespace CYLINDER {
const double PI = acos(-1.0);
int width, height;

void solve(int test_num) {
  if (height > width) swap(height, width);
  double R = min(height / (2.0 * PI), width / 3.0);
  double ans = R * R * (width - 2 * R);
  R = min(height / 2.0, width / (2 + 2.0 * PI));
  ans = max(ans, R * R * height);
  ans *= PI;
  printf("%.3lf\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (scanf("%d %d", &width, &height) != EOF)
    if (height + width > 0)
      solve(1);
}
}

int main() {
  CYLINDER::solve();
  return 0;
}

