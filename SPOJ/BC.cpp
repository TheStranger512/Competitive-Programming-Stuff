/* Solved
 * 9935. Break the Chocolate
 * File:   BC.cpp
 * Author: Andy Y.F. Huang
 * Created on September 30, 2012, 12:30 PM
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
namespace BC {

void solve(int test_num) {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  long long vol = 1LL * a * b * c;
  int cuts = 0;
  while (a > 1 || b > 1 || c > 1) {
    int high = max(a, max(b, c));
    if (high == a)
      a = (a + 1) >> 1;
    else if (high == b)
      b = (b + 1) >> 1;
    else
      c = (c + 1) >> 1;
    cuts++;
  }
  printf("Case #%d: %lld %d\n", test_num, vol - 1, cuts);
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
  BC::solve();
  return 0;
}

