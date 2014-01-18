/* Solved
 * 4343. Empty Boxes - weird formula
 * File:   EBOXES.cpp
 * Author: Andy Y.F. Huang
 * Created on August 30, 2012, 1:28 PM
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
namespace EBOXES {

void solve(int test_num) {
  int n, k, t, f;
  scanf("%d %d %d %d", &n, &k, &t, &f);
  printf("%d\n", (f - n) / (k - 1) + f);
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
  EBOXES::solve();
  return 0;
}

