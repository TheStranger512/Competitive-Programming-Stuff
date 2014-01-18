/* Solved
 * 6043. The Game
 * File:   QCJ3.cpp
 * Author: Andy Y.F. Huang
 * Created on December 31, 2012, 9:48 PM
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
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <iomanip>
#include <cassert>
#include <ctime>
#include <functional>
#include <complex>
#include <numeric>
#include <cctype>
#include <cstddef>
#include <utility>
#include <valarray>
#include <cstdlib>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace QCJ3 {

void solve(int test_num) {
  int len, xorsum = 0;
  scanf("%d", &len);
  for (int i = 1; i <= len; i++) {
    int cnt;
    scanf("%d", &cnt);
    if (cnt & 1)
      xorsum ^= i;
  }
  if (xorsum == 0) puts("Hanks Wins");
  else puts("Tom Wins");
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
  QCJ3::solve();
  return 0;
}

