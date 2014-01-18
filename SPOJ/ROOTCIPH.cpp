/* Solved
 * 6297. Decipher
 * File:   ROOTCIPH.cpp
 * Author: Andy Y.F. Huang
 * Created on August 15, 2012, 4:07 PM
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
namespace ROOTCIPH {

void solve(int test_num) {
  long long a, b, c;
  scanf("%lld %lld %lld", &a, &b, &c);
  printf("%lld\n", a * a - 2 * b);
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
  ROOTCIPH::solve();
  return 0;
}

