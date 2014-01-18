/* Solved
 * 6172. OAE
 * File:   OAE.cpp
 * Author: Andy Y.F. Huang
 * Created on August 27, 2012, 8:17 PM
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
namespace OAE {
const int mod = 314159;
int even[1000010], odd[1000010];

void init() {
  even[1] = 9;
  odd[1] = 1;
  for (int i = 2; i <= 1000000; i++) {
    even[i] = 9 * even[i - 1] + odd[i - 1];
    even[i] %= mod;
    odd[i] = 9 * odd[i - 1] + even[i - 1];
    odd[i] %= mod;
  }
}

void solve(int test_num) {
  int n;
  scanf("%d", &n);
  printf("%d\n", even[n]);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  init();
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  OAE::solve();
  return 0;
}

