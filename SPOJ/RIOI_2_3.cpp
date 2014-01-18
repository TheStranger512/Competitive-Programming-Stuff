/* Solved
 * 12612. Path of the righteous man
 * File:   RIOI_2_3.cpp
 * Author: Andy Y.F. Huang
 * Created on May 28, 2013, 9:54 PM
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
#include <limits>
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

namespace RIOI_2_3 {
const int DR[] = {0, -1, 0, 1};
const int DC[] = {1, 0, -1, 0};
bool vis[55][55];
int grid[55][55];
int mask;

void dfs(int r, int c) {
  if (vis[r][c] || grid[r][c] < 0 || (1 << grid[r][c] & ~mask)) return;
  vis[r][c] = true;
  for (int d = 0; d < 4; d++)
    dfs(r + DR[d], c + DC[d]);
}

void solve(int test_num) {
  memset(grid, -1, sizeof (grid));
  int size;
  scanf("%d", &size);
  for (int i = 1; i <= size; i++)
    for (int j = 1; j <= size; j++)
      scanf("%d", &grid[i][j]);
  int sr, sc, er, ec;
  scanf("%d %d %d %d", &sr, &sc, &er, &ec);
  sr++, sc++, er++, ec++;
  int res = 10;
  for (mask = 1023; mask > 0; mask--) {
    if (__builtin_popcount(mask) >= res) continue;
    memset(vis, false, sizeof (vis));
    dfs(sr, sc);
    if (vis[er][ec])
      res = __builtin_popcount(mask);
  }
  printf("%d\n", res);
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
  RIOI_2_3::solve();
  return 0;
}

