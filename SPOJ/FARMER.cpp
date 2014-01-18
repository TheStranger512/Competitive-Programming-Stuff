/* Solved
 * 366. Farmer
 * File:   FARMER.cpp
 * Author: Andy Y.F. Huang
 * Created on August 28, 2012, 8:23 PM
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
namespace FARMER {
int field[2000], strip[2000];
bool dp[150001];

bool comp(const int& a, const int& b) {
  return b < a;
}

void solve(int test_num) {
  memset(dp, false, sizeof (dp));
  int limit, fieldcnt, stripcnt, bigfield = 0, high = 0;
  scanf("%d %d %d", &limit, &fieldcnt, &stripcnt);
  for (int i = 0; i < fieldcnt; i++) {
    scanf("%d", &field[i]);
    bigfield = max(bigfield, field[i]);
  }
  for (int i = 0; i < stripcnt; i++)
    scanf("%d", &strip[i]);
  dp[0] = true;
  //  sort(fi,fi+n);
  sort(strip, strip + stripcnt, comp);
  for (int i = 0; i < fieldcnt; i++)
    for (int j = limit; j >= 0; j--)
      if (dp[j] && j + field[i] <= limit)
        dp[j + field[i]] = true;
  int ans;
  for (int i = limit; i >= 0; i--) {
    if (dp[i]) {
      ans = high = i;
      break;
    }
  }
  for (int i = 0; high < limit; i++) {
    if (high + strip[i] <= limit) {
      ans += strip[i] - 1;
      high += strip[i];
    }
    else {
      int sum = limit - high;
      high += sum;
      ans += sum - 1;
    }
  }
  if (bigfield >= limit && limit - 1 > ans)
    printf("%d\n", limit - 1);
  else
    printf("%d\n", ans);
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
  FARMER::solve();
  return 0;
}

