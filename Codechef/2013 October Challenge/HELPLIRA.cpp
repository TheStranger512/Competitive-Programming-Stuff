/*
 * Codechef 2013 October Challenge
 * Helping Lira
 * File:   HELPLIRA.cpp
 * Author: Andy Y.F. Huang
 * Created on Oct 4, 2013, 3:43:03 PM
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

using namespace std;

namespace HELPLIRA {

void solve(int test_num) {
  int N;
  cin >> N;
  int low = 1 << 30, high = -low, a = -1, b = -1;
  for (int i = 1, x1, y1, x2, y2, x3, y3; i <= N; i++) {
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int area = abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1));
    if (area <= low)
      low = area, a = i;
    if (area >= high)
      high = area, b = i;
  }
  cout << a << ' ' << b << endl;
}

void solve() {
#ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
#endif
  solve(1);
}
}

int main() {
  HELPLIRA::solve();
  return 0;
}
