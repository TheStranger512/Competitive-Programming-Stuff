/* Solved
 * 15241. Luis Quest
 * File:   VPL2_AA.cpp
 * Author: Andy Y.F. Huang
 * Created on July 22, 2013, 12:05 AM
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

namespace VPL2_AA {

void solve(int test_num) {
  int p0, p1, t, p;
  cin >> p0 >> p1 >> t >> p;
  double r = log2(1.0 * p1 / p0) / t;
  printf("Scenario #%d: %.2lf\n", test_num, log2(1.0 * p / p0) / r);
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
  VPL2_AA::solve();
  return 0;
}

