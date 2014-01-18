/* Solved
 * 14961. Maximum Girth
 * File:   MAXGRITH.cpp
 * Author: Andy Y.F. Huang
 * Created on May 19, 2013, 1:10 AM
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

namespace MAXGRITH {

void solve(int test_num) {
  long long len;
  scanf("%lld", &len);
//  if (len == 1) puts("1");
//  else if (len == 3) puts("3");
  printf("%lld\n", len == 1 ? 1 : (2 * len + 2) / 3 % 1000000007);
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
  MAXGRITH::solve();
  return 0;
}

