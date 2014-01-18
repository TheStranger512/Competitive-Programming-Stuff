/* Solved
 * 8624. Nim-B Sum
 * File:   NY10B.cpp
 * Author: Andy Y.F. Huang
 * Created on September 22, 2012, 10:56 PM
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
#include <fstream>
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace NY10B {

void solve(int test_num) {
  int base, x, y, digits[30] = {0};
  scanf("%d %d %d %d", &test_num, &base, &x, &y);
  for (int i = 0; x > 0; i++) {
    digits[i] += x % base;
    x /= base;
  }
  for (int i = 0; y > 0; i++) {
    digits[i] += y % base;
    y /= base;
  }
  int ans = 0;
  for (int i = 25; i >= 0; i--) {
    ans *= base;
    ans += digits[i] % base;
  }
  printf("%d %d\n", test_num, ans);
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
  NY10B::solve();
  return 0;
}

