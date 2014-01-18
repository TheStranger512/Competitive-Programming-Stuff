/* Solved
 * 14697. Loop Expectation
 * File:   LOOPEXP.cpp
 * Author: Andy Y.F. Huang
 * Created on April 20, 2013, 7:30 PM
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

namespace LOOPEXP {
double ans[111111];

void solve(int test_num) {
  int n;
  scanf("%d", &n);
  printf("%.7lf\n", ans[n]);
 }

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  ans[1] = 1;
  for (int i = 2; i <= 100000; i++)
    ans[i] = ans[i - 1] + 1.0 / i;
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  LOOPEXP::solve();
  return 0;
}

