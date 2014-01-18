/*
 * Solved
 * 9121. Magical Crafting
 * CYK algorithm
 * File:   GCPC11E.cpp
 * Author: Andy Y.F. Huang
 * Created on January 19, 2013, 5:07 PM
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
namespace GCPC11E {
int from[33], to1[33], to2[33], cost[33];
int dp[111][111][30]; //width, start pos, from letter
char str[111];

void checkmin(int& a, int b) {
  if (b < a) a = b;
}

void solve(int test_num) {
  int recipes, quests;
  scanf("%d %d ", &recipes, &quests);
  for (int r = 0; r < recipes; r++) {
    char a, b, c;
    scanf("%c %c %c %d ", &a, &b, &c, cost + r);
    from[r] = a - 'A';
    to1[r] = b - 'A';
    to2[r] = c - 'A';
  }
  printf("CASE #%d\n", test_num);
  for (int q = 0; q < quests; q++) {
    int len;
    scanf("%d %s", &len, str);
    memset(dp, 0x3F, sizeof (dp));
    for (int i = 0; i < len; i++)
      dp[1][i][str[i] - 'a'] = 1;
    for (int w = 2; w <= len; w++)
      for (int i = 0; i + w <= len; i++)
        for (int j = i + 1; j < i + w; j++)
          for (int r = 0; r < recipes; r++)
            checkmin(dp[w][i][from[r]], dp[j - i][i][to1[r]] + dp[i + w - j][j][to2[r]] + cost[r]);
    int ans = dp[len][0][0];
    if (ans >= (1 << 20))
      puts("IMPOSSIBLE");
    else printf("POSSIBLE WITH %d DIAMONDS\n", ans);
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  GCPC11E::solve();
  return 0;
}

