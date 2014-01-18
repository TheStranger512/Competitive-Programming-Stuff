/* Solved
 * 38. Labyrinth
 * File:   LABYR1.cpp
 * Author: Andy Y.F. Huang
 * Created on August 9, 2012, 11:52 PM
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
namespace LABYR1 {
char grid[1010][1010];
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int depth[1010][1010], rows, cols, bestx, besty;

void dfs(int x, int y) {
  if (depth[x][y] > depth[bestx][besty]) {
    bestx = x;
    besty = y;
  }
  for (int d = 0; d < 4; d++) {
    int nx = x + dx[d], ny = y + dy[d], cdepth = depth[x][y];
    if (grid[nx][ny] == '.' && cdepth + 1 < depth[nx][ny]) {
      depth[nx][ny] = cdepth + 1;
      dfs(nx, ny);
    }
  }
}

void solve(int test_num) {
  memset(grid, '#', sizeof (grid));
  scanf("%d %d", &cols, &rows);
  for (int y = 1; y <= rows; y++)
    scanf("%s", grid[y] + 1);
  int sx = -1, sy = -1;
  for (int y = 1; y <= rows && sx == -1; y++) {
    for (int x = 1; x <= cols; x++) {
      if (grid[x][y] == '.') {
        sx = x;
        sy = y;
        break;
      }
    }
  }
  memset(depth, 0x3F, sizeof (depth));
  depth[bestx = sx][besty = sy] = 0;
  dfs(sx, sy);
  memset(depth, 0x3F, sizeof (depth));
  depth[bestx][besty] = 0;
  dfs(bestx, besty);
  printf("Maximum rope length is %d.\n", depth[bestx][besty]);
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
  LABYR1::solve();
  return 0;
}

