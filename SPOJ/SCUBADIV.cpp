/* Solved
 * 181. Scuba diver
 * File:   SCUBADIV.cpp
 * Author: Andy Y.F. Huang
 * Created on August 17, 2012, 3:30 PM
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
namespace SCUBADIV {
int dp[25][85];

void solve(int test_num) {
  memset(dp, 0x3F, sizeof (dp));
  int needo, needn, len;
  scanf("%d %d %d", &needo, &needn, &len);
  dp[0][0] = 0;
  for (int i = 0; i < len; i++) {
    int oxy, nit, cost;
    scanf("%d %d %d", &oxy, &nit, &cost);
    for (int o = needo; o >= 0; o--) {
      for (int n = needn; n >= 0; n--) {
        if (dp[o][n] >= 123456789)
          continue;
        int no = o + oxy, nn = n + nit;
        if (no > needo)
          no = needo;
        if (nn > needn)
          nn = needn;
        dp[no][nn] = min(dp[no][nn], dp[o][n] + cost);
      }
    }
  }
  printf("%d\n", dp[needo][needn]);
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
  SCUBADIV::solve();
  return 0;
}

