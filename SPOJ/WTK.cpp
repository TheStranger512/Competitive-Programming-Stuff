/* Solved
 * 10285. Why this kolaveri di
 * File:   WTK.cpp
 * Author: Andy Y.F. Huang
 * Created on March 29, 2013, 12:55 PM
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

namespace WTK {

void solve(int test_num) {
  int len;
  scanf("%d", &len);
  int rem = 0;
  for (int i = 2; i <= len; i++)
    rem = (rem + len - i + 1) % i;
  printf("%d\n", rem + 1);
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
  WTK::solve();
  return 0;
}

