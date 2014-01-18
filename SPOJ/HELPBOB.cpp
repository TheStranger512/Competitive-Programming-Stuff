/* Solved
 * 2856. Help Bob
 * File:   HELPBOB.cpp
 * Author: Andy Y.F. Huang
 * Created on August 24, 2012, 5:29 PM
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
namespace HELPBOB {
double dp[1 << 16];
int price[20], area[20], discounts[20][20], pizzas;

void solve(int test_num) {
  memset(discounts, 0, sizeof (discounts));
  for (int i = 0; i < pizzas; i++)  {
    int deg;
    scanf("%d %d %d", &price[i], &area[i], &deg);
    while (deg--) {
      int pizza;
      scanf("%d", &pizza);
      scanf("%d", &discounts[i][--pizza]);
      discounts[i][pizza] = 100 - discounts[i][pizza];
    }
  }
  for (int mask = (1 << pizzas) - 1; mask > 0; mask--)
    dp[mask] = 1e10;
  double ans = 1e10;
  dp[0] = 0;
  for (int mask = 1; mask < (1 << pizzas); mask++) {
    int totalarea = 0;
    for (int p = 0; p < pizzas; p++) {
      if (!(1 << p & mask))
        continue;
      totalarea += area[p];
      double toadd = price[p];
      for (int i = 0; i < pizzas; i++)
        if ((1 << i & mask) > 0 && discounts[i][p])
          toadd *= discounts[i][p] / 100.0;
      dp[mask] = min(dp[mask], dp[1 << p ^ mask] + toadd);
    }
    ans = min(ans, dp[mask] / totalarea);
  }
  printf("%.4f\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (true) {
    scanf("%d", &pizzas);
    if (pizzas == 0)
      break;
    solve(1);
  }
}
}

int main() {
  HELPBOB::solve();
  return 0;
}

