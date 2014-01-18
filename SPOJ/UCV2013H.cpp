/* Solved
 * 15436. Slick
 * File:   UCV2013H.cpp
 * Author: Andy Y.F. Huang
 * Created on July 29, 2013, 3:23 AM
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

namespace UCV2013H {
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int R, C;
int grid[222][222];
map<int, int> res;

int dfs(int r, int c) {
  if (grid[r][c] == 0) return 0;
  grid[r][c] = 0;
  int res = 1;
  for (int d = 0; d < 4; d++)
    res += dfs(r + dy[d], c + dx[d]);
  return res;
}

void solve(int test_num) {
  if (R + C == 0) return;
  memset(grid, 0, sizeof (grid));
  for (int r = 1; r <= R; r++)
    for (int c = 1; c <= C; c++)
      scanf("%d", grid[r] + c);
  res.clear();
  int cnt = 0;
  for (int r = 1; r <= R; r++)
    for (int c = 1; c <= C; c++)
      if (grid[r][c] == 1) {
        res[dfs(r, c)]++;
        cnt++;
      }
  printf("%d\n", cnt);
  for (map<int, int>::iterator it = res.begin(); it != res.end(); ++it)
    printf("%d %d\n", it->first, it->second);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (cin >> R >> C)
    solve(1);
}
}

int main() {
  UCV2013H::solve();
  return 0;
}

