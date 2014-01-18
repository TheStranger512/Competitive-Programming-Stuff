/* Solved
 * 3878. Rectangles Perimeter
 * File:   MMAXPER.cpp
 * Author: Andy Y.F. Huang
 * Created on September 28, 2012, 9:48 PM
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
namespace MMAXPER {
int shapes, len[1010], width[1010], dp[1010][2]; // 0-len is height, 1-width is height

void solve(int test_num) {
  scanf("%d", &shapes);
  for (int i = 0; i < shapes; i++)
    scanf("%d %d", &len[i], &width[i]);
  dp[0][0] = width[0];
  dp[0][1] = len[0];
  for (int s = 1; s < shapes; s++) {
    dp[s][0] = max(dp[s - 1][0] + width[s] + abs(len[s] - len[s - 1]),
                   dp[s - 1][1] + width[s] + abs(len[s] - width[s - 1]));
    dp[s][1] = max(dp[s - 1][0] + len[s] + abs(width[s] - len[s - 1]),
                   dp[s - 1][1] + len[s] + abs(width[s] - width[s - 1]));
  }
  printf("%d\n", max(dp[shapes - 1][0], dp[shapes - 1][1]));
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve(1);
}
}

int main() {
  MMAXPER::solve();
  return 0;
}

