/* Solved
 * 9385. Strictly not a Prime
 * File:   MAIN111.cpp
 * Author: Andy Y.F. Huang
 * Created on September 22, 2012, 12:04 AM
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
namespace MAIN111 {
const int k_lim = 100000;
int ans[k_lim + 10] = {0};

void init() {
  static bool mark[k_lim + 10] = {false};
  mark[0] = mark[1] = true;
  for (int i = 2; i < 320; i++)
    if (!mark[i])
      for (int j = i * i; j <= k_lim; j += i)
        mark[j] = true;
  int digits[10];
  for (int i = 1; i <= k_lim; i++) {
    int len = 0, temp = i;
    bool good = true;
    while (temp > 0) {
      digits[len] = temp % 10;
      switch (digits[len++]) {
        case 2: case 3: case 5: case 7: good = false;
      }
      temp /= 10;
    }
    if (!good) continue;
    //try all subsequences of digits
    for (int mask = (1 << len) - 1; mask >= 0; mask--) {
      temp = 0;
      for (int bit = 0; bit < len; bit++)
        if (1 << bit & mask)
          temp = (temp << 1) + (temp << 3), temp += digits[bit];
      if (!mark[temp]) {
        good = false;
        break;
      }
    }
    if (good)
      ans[i] = 1;
  }
  for (int i = 1; i <= k_lim; i++)
    ans[i] += ans[i - 1];
}

void solve(int test_num) {
  int a, b;
  scanf("%d %d", &a, &b);
  if (a > b) swap(a, b);
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
  MAIN111::solve();
  return 0;
}

