/* Solved
 * 7668. Pebble Solver - dp
 * File:   PEBBLE.cpp
 * Author: Andy Y.F. Huang
 * Created on August 30, 2012, 1:38 PM
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
 * Unsolved
 * @author Andy Y.F. Huang
 */
namespace PEBBLE {
char str[10010];
//mininum number of moves to change first i chars (counting from back)
//to all ones or all zeroes
int dp[10010][2];

void solve(int test_num) {
  int len = strlen(str);
  dp[len - 1][0] = str[len - 1] != '0'; //base cases
  dp[len - 1][1] = str[len - 1] != '1';
  for (int i = len - 2; i >= 0; i--) {
    if (str[i] == '0')
      dp[i][0] = dp[i + 1][0], dp[i][1] = 1 + dp[i + 1][0];
    else if (str[i] == '1')
      dp[i][0] = 1 + dp[i + 1][1], dp[i][1] = dp[i + 1][1];
    else
      assert(false);
  }
  printf("Game #%d: %d\n", test_num, dp[0][0]);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  for (int i = 1; scanf("%s\r\n", str) != EOF; i++)
    solve(i);
}
}

int main() {
  PEBBLE::solve();
  return 0;
}

