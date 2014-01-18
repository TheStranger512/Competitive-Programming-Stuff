/* Solved
 * 1021. Aibohphobia
 * File:   AIBOHP.cpp
 * Author: Andy Y.F. Huang
 * Created on August 8, 2012, 1:01 PM
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
namespace AIBOHP {
const int k_max_len = 6010;
int dp[k_max_len], prev[k_max_len];
char str[k_max_len];

void solve(int test_num) {
  memset(prev, 0, sizeof (prev));
  gets(str + 1);
  int len = strlen(str + 1);
  for (int i = 1; i <= len; i++) {
    for (int j = 1; j <= len; j++) {
      if (str[i] == str[len - j + 1])
        dp[j] = 1 + prev[j - 1];
      else
        dp[j] = max(dp[j - 1], prev[j]);
      prev[j - 1] = dp[j - 1];
    }
    prev[len] = dp[len];
  }
  printf("%d\n", len - dp[len]);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d\r\n", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  AIBOHP::solve();
  return 0;
}

