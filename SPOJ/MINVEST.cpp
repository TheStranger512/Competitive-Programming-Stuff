/* Solved
 * 3964. Investment Money'
 * irregular knapsack
 * File:   MINVEST.cpp
 * Author: Andy Y.F. Huang
 * Created on September 27, 2012, 9:16 PM
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
namespace MINVEST {
int dp[55555];

void solve(int test_num) {
  int init, years, bonds, cost[25], value[25];
  scanf("%d %d %d", &init, &years, &bonds);
  for (int i = 0; i < bonds; i++) {
    scanf("%d %d", &cost[i], &value[i]);
    cost[i] /= 1000; //input garantees cost[i] is a multiple of 1000
  }
  int cur = init;
  for (int y = 0; y < years; y++) {
    memset(dp, 0, sizeof (dp));
    int nval = 0, lim = cur / 1000;
    for (int b = 0; b < bonds; b++) {
      for (int v = 0; v + cost[b] <= lim; v++) {
        int temp = v + cost[b];
        dp[temp] = max(dp[temp], dp[v] + value[b]);
        nval = max(nval, dp[temp]);
      }
    }
    cur += nval;
    //pln(cur);
  }
  printf("%d\n", cur);
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
  MINVEST::solve();
  return 0;
}

