/* Solved
 * 78. Marbles
 * File:   MARBLES.cpp
 * Author: Andy Y.F. Huang
 * Created on August 30, 2012, 11:57 PM
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
namespace MARBLES {
void solve(int test_num) {
  int n, k;
  scanf("%d %d", &n, &k);
  n--, k--;
  if (k > n / 2) k = n - k;
  long long ans = 1;
  for (int i = 0; i < k; i++) {
    ans *= n - i;
    ans /= (i + 1);
  }
  printf("%lld\n", ans);
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
  MARBLES::solve();
  return 0;
}

