/* Solved
 * 1702. Cleaning Robot - bfs
 * File:   CLEANRBT.cpp
 * Author: Andy Y.F. Huang
 * Created on September 4, 2012, 5:25 PM
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
namespace CLEANRBT {

struct Point {
  int x, y;

  Point(int x, int y) : x(x), y(y) { }

  Point() : x(0), y(0) { }
} ;

const int inf = 123456789;
char grid[25][25];
const char dx[] = {0, 1, 0, -1};
const char dy[] = {1, 0, -1, 0};
int dist[25][25], shpath[15][15], fromstart[15];
Point dirty[15];
queue<Point> q;

int bfs(int sx, int sy, int ex, int ey) {
  while (!q.empty())
    q.pop();
  memset(dist, 0x3F, sizeof (dist));
  dist[sx][sy] = 0;
  q.push(Point(sx, sy));
  while (!q.empty()) {
    Point cur = q.front();
    q.pop();
    if (cur.x == ex && cur.y == ey)
      return dist[ex][ey];
    for (int d = 0; d < 4; d++) {
      int nx = cur.x + dx[d], ny = cur.y + dy[d];
      if (grid[nx][ny] != 'x' && dist[cur.x][cur.y] + 1 < dist[nx][ny]) {
        dist[nx][ny] = dist[cur.x][cur.y] + 1;
        q.push(Point(nx, ny));
      }
    }
  }
  return inf;
}

void solve(int test_num, int cols, int rows) {
  memset(grid, 'x', sizeof (grid));
  int sx, sy, len = 0, ans = inf, order[15];
  for (int i = 1; i <= rows; i++) {
    for (int j = 1; j <= cols; j++) {
      grid[j][i] = 0;
      while (grid[j][i] <= ' ')
        grid[j][i] = getchar_unlocked();
      if (grid[j][i] == 'o')
        sx = j, sy = i;
      if (grid[j][i] == '*')
        dirty[len].x = j, dirty[len++].y = i;
    }
  }
  for (int i = 0; i < len; i++) {
    order[i] = i;
    fromstart[i] = bfs(sx, sy, dirty[i].x, dirty[i].y);
    for (int j = i + 1; j < len; j++)
      shpath[i][j] = shpath[j][i] = bfs(dirty[i].x, dirty[i].y, dirty[j].x, dirty[j].y);
  }
  do {
    int path = fromstart[order[0]];
    for (int i = 0; i < len - 1; i++)
      path += shpath[order[i]][order[i + 1]];
    ans = min(ans, path);
  } while (next_permutation(order, order + len));
  if (ans >= inf)
    puts("-1");
  else
    printf("%d\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (true) {
    int cols, rows;
    scanf("%d %d\r\n", &cols, &rows);
    if (cols == 0 && rows == 0)
      break;
    solve(1, cols, rows);
  }
}
}

int main() {
  CLEANRBT::solve();
  return 0;
}

