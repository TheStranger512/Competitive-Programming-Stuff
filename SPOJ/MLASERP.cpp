/* Solved
 * 3861. Laser Phones
 * File:   MLASERP.cpp
 * Author: Andy Y.F. Huang
 * Created on August 13, 2012, 8:16 PM
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
namespace MLASERP {

struct Point {
  int x, y;

  Point(int x, int y) : x(x), y(y) {
  }
} ;

const char dx[] = {0, 1, 0, -1};
const char dy[] = {1, 0, -1, 0};
char grid[110][110];
int dist[110][110];
queue<Point> q;

int bfs(int sx, int sy, int ex, int ey) {
  memset(dist, 0x3F, sizeof (dist));
  dist[sx][sy] = -1;
  q.push(Point(sx, sy));
  while (!q.empty()) {
    Point cur = q.front();
    q.pop();
    int cdist = dist[cur.x][cur.y];
    for (int d = 0; d < 4; d++) {
      int nx = cur.x + dx[d], ny = cur.y + dy[d];
      while (grid[nx][ny] != '*') {
        if (cdist + 1 < dist[nx][ny]) {
          dist[nx][ny] = cdist + 1;
          q.push(Point(nx, ny));
        }
        nx += dx[d], ny += dy[d];
      }
    }
  }
  return dist[ex][ey];
}

void solve(int test_num) {
  memset(grid, '*', sizeof (grid));
  int cols, rows, sx = -1, sy, ex, ey;
  scanf("%d %d", &cols, &rows);
  for (int y = 1; y <= rows; y++) {
    for (int x = 1; x <= cols; x++) {
      grid[x][y] = 0;
      while (grid[x][y] <= ' ')
        grid[x][y] = getchar_unlocked();
      if (grid[x][y] == 'C') {
        if (sx == -1)
          sx = x, sy = y;
        else
          ex = x, ey = y;
      }
    }
  }
  printf("%d\n", bfs(sx, sy, ex, ey));
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
  MLASERP::solve();
  return 0;
}

