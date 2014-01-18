/* Solved
 * 10466. Enough of analyzing, let’s play
 * File:   EALP1.cpp
 * Author: Andy Y.F. Huang
 * Created on October 17, 2012, 9:18 PM
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
namespace EALP1 {
int val[1111];

void solve(int test_num) {
  int len, ans = 0, xorsum = 0;;
  scanf("%d", &len);
  for (int i = 1; i <= len; i++) {
    scanf("%d", &val[i]);
    xorsum ^= val[i];
  }
  for (int i = 1; i <= len; i++) {
    xorsum ^= val[i];
    ans += xorsum < val[i];
    xorsum ^= val[i];
    //pln(xorsum[i - 1], xorsum[len] ^ xorsum[i]);
  }
  printf("Case %d: %d\n", test_num, ans);
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
  EALP1::solve();
  return 0;
}

