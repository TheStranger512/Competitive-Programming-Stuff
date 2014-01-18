/* Solved
 * 12260. Devlali Numbers
 * File:   HARSHAD.cpp
 * Author: Andy Y.F. Huang
 * Created on September 28, 2012, 4:04 PM
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
namespace HARSHAD {
const int k_lim = 1000000;
int ans[k_lim + 10] = {0};
bool good[k_lim + 10];

void init() {
  memset(good, true, sizeof (good));
  good[0] = good[1] = false;
  for (int i = 2; i <= 1000; i++)
    if (good[i])
      for (int j = i * i; j <= k_lim; j += i)
        good[j] = false;
  ans[0] = 0;
  for (int i = 1; i <= k_lim; i++) {
    int sum = i, temp = i;
    while (temp > 0) {
      sum += temp % 10;
      temp /= 10;
    }
    if (sum <= k_lim)
      good[sum] = false;
    if (good[i])
      ans[i]++;
    ans[i] += ans[i - 1];
  }
}

void solve(int test_num) {
  int a, b;
  scanf("%d %d", &a, &b);
  printf("%d\n", ans[b] - ans[a - 1]);
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
  HARSHAD::solve();
  return 0;
}

