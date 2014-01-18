/* Solved
 * 5091. Feline Olympics - Mouseball
 * dp
 * File:   MBALL.cpp
 * Author: Andy Y.F. Huang
 * Created on September 8, 2012, 12:06 AM
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
namespace MBALL {
int types[5] = {2, 3, 6, 7, 8};
long long dp[100100] = {0};

void init() {
  dp[0] = 1;
  for (int j = 0; j < 5; j++)
    for (int i = 0; i <= 100000; i++)
      dp[i + types[j]] += dp[i];
}

void solve(int test_num) {
  int score;
  scanf("%d", &score);
  printf("%lld\n", dp[score]);
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
  MBALL::solve();
  return 0;
}

