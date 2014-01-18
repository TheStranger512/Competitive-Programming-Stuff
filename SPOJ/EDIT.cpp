/*
 * Solved
 * 10537. Edit Distance Again
 * File:   EDIT.cpp
 * Author: Andy Y.F. Huang
 * Created on January 26, 2013, 1:02 PM
 */

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace EDIT {
int dp[2][1111];
//[(0 - lower, 1 - upper), pos]
char str[1111];

void solve(int test_num) {
  int len = strlen(str);
  if (str[0] >= 'a') {
    dp[0][0] = 0;
    dp[1][0] = 1;
  }
  else {
    dp[1][0] = 0;
    dp[0][0] = 1;
  }
  for (int i = 1; i < len; i++) {
    if (str[i] >= 'a') {
      dp[0][i] = dp[1][i - 1];
      dp[1][i] = dp[0][i - 1] + 1; //change to upper
    }
    else {
      dp[1][i] = dp[0][i - 1];
      dp[0][i] = dp[1][i - 1] + 1; //change to lower
    }
  }
  printf("%d\n", min(dp[0][len - 1], dp[1][len - 1]));
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (scanf("%s", str) != EOF)
    solve(1);
}
}

int main() {
  EDIT::solve();
  return 0;
}

