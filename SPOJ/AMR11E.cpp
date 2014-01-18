/* Solved
 * 10232. Distinct Primes
 * File:   AMR11E.cpp
 * Author: Andy Y.F. Huang
 * Created on August 8, 2012, 1:59 PM
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
namespace AMR11E {
int ans[1010];

void init() {
  int len = 1;
  for (int i = 30; len <= 1000; i++) {
    int factors = 0, num = i;
    for (int j = 2; j <= num; j++) {
      factors += (num % j == 0);
      while (num % j == 0)
        num /= j;
    }
    if (factors >= 3)
      ans[len++] = i;
  }
}

void solve(int test_num) {
  int n;
  scanf("%d", &n);
  printf("%d\n", ans[n]);
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
  AMR11E::solve();
  return 0;
}

