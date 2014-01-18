/* Solved
 * 14863. Summation of Multiples
 * File:   SUM1.cpp
 * Author: Andy Y.F. Huang
 * Created on May 11, 2013, 8:01 PM
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

namespace SUM1 {

long long go(int mult, int upto) {
  int len = upto / mult;
  return 1LL * len * (2 * mult + (len - 1) * mult) / 2;
}

void solve(int test_num) {
  int upto;
  scanf("%d", &upto);
  upto--;
  cout << go(3, upto) + go(5, upto) - go(15, upto) << endl;
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
  SUM1::solve();
  return 0;
}

