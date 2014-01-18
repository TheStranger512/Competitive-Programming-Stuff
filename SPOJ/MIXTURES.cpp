/* Solved
 * 345. Mixtures
 * File:   MIXTURES.cpp
 * Author: Andy Y.F. Huang
 * Created on October 27, 2012, 11:39 PM
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
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <iomanip>
#include <cassert>
#include <ctime>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace MIXTURES {
int color[111], len;
int cnt[111] = {0};
int dp[111][111];
//dp[i][j] = min smoke after mixing i mixtures starting from j

inline void checkmin(int &a, int b) {
  if (b < a) a = b;
}

inline int sum(int from, int width) {
  return (cnt[from + width - 1] - cnt[from - 1]) % 100;
}

void solve(int test_num) {
  for (int i = 1; i <= len; i++)
    scanf("%d", &color[i]);
  memset(cnt, 0, sizeof (cnt));
  for (int i = 1; i <= len; i++)
    cnt[i] = color[i] + cnt[i - 1];
  memset(dp, 0x3F, sizeof (dp));
  memset(dp[0], 0, sizeof (dp[0]));
  memset(dp[1], 0, sizeof (dp[1]));
  for (int i = 1; i + 1 <= len; i++)
    dp[2][i] = color[i] * color[i + 1];
  for (int w = 3; w <= len; w++)
    for (int i = 1, j = i + w - 1; j <= len; i++, j++)
      for (int c = i; c < j; c++)  //current middle point
        checkmin(dp[w][i], dp[c - i + 1][i] + dp[j - c][c + 1] + sum(i, c - i + 1) * sum(c + 1, j - c));
  printf("%d\n", dp[len][1]);
}

void makecase() {
  srand(time(NULL));
  freopen("input.txt", "w", stdout);
  for (int t = 0; t < 10; t++) {
    int len = rand() % 100 + 1;
    printf("%d\n", len);
    for (int i = 0; i < len; i++)
      printf("%d ", rand() % 100);
    putchar('\n');
  }
}

void solve() {
  #ifdef AZN
  //makecase();
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (scanf("%d", &len) != EOF)
    solve(1);
}
}

int main() {
  MIXTURES::solve();
  return 0;
}

