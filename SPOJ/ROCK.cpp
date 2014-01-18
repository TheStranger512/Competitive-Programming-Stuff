/* Solved
 * 154. Sweet and Sour Rock
 * File:   ROCK.cpp
 * Author: Andy Y.F. Huang
 * Created on October 13, 2012, 11:59 PM
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
namespace ROCK {
int dp[222], cnt[222] = {0};
char str[222];

void solve(int test_num) {
  memset(dp, 0, sizeof (dp));
  int len;
  scanf("%d %s", &len, str + 1);
  for (int i = 1; i <= len; i++)
    cnt[i] = (str[i] - '0') + cnt[i - 1];
  for (int i = 1; i <= len; i++) {
    dp[i] = max(dp[i], dp[i - 1]);
    for (int j = i; j <= len; j++)
      if (cnt[j] - cnt[i - 1] > (j - i + 1) / 2)
        dp[j + 1] = max(dp[j + 1], dp[i] + (j - i + 1));
  }
  printf("%d\n", *max_element(dp, dp + len + 3));
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
  ROCK::solve();
  return 0;
}

