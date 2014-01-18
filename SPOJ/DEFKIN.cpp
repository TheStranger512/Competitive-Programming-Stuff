/* Solved
 * 7804. Defense of a Kingdom
 * File:   DEFKIN.cpp
 * Author: Andy Y.F. Huang
 * Created on April 28, 2013, 3:24 PM
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

namespace DEFKIN {
typedef pair<int, int> Point;
Point pts[44444];

bool cmpy(const Point& a, const Point& b) {
  return a.second < b.second;
}

void solve(int test_num) {
  int width, height, len;
  scanf("%d %d %d", &width, &height, &len);
  for (int i = 0; i < len; i++)
    scanf("%d %d", &pts[i].first, &pts[i].second);
  pts[len++] = Point(0, 0);
  pts[len++] = Point(0, height + 1);
  pts[len++] = Point(width + 1, 0);
  pts[len++] = Point(width + 1, height + 1);
  int adjx = 0, adjy = 0;
  sort(pts, pts + len);
  for (int i = 1; i < len; i++)
    adjx = max(adjx, pts[i].first - pts[i - 1].first - 1);
  sort(pts, pts + len, cmpy);
  for (int i = 1; i < len; i++)
    adjy = max(adjy, pts[i].second - pts[i - 1].second - 1);
  printf("%d\n", adjy * adjx);
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
  DEFKIN::solve();
  return 0;
}

