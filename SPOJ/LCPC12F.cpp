/* Solved
 * 12407. Johnny The Gambler
 * File:   LCPC12F.cpp
 * Author: Andy Y.F. Huang
 * Created on October 8, 2012, 1:20 PM
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
namespace LCPC12F {
int cnt[11111];

void solve(int test_num) {
  memset(cnt, 0, sizeof (cnt));
  int tar, len, val;
  long long ans = 0;
  scanf("%d %d", &tar, &len);
  for (int i = 0; i < len; i++) {
    scanf("%d", &val);
    if (val <= tar)
      ans += cnt[tar - val];
    cnt[val]++;
  }
  printf("%d. %lld\n", test_num, ans);
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
  LCPC12F::solve();
  return 0;
}

