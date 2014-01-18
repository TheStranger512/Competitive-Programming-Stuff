/* Solved
 * 10711. VUK - bfs
 * File:   NAGAY1.cpp
 * Author: Andy Y.F. Huang
 * Created on September 8, 2012, 11:27 PM
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
namespace NAGAY1 {

struct Point {
  int x, y;

  Point(int x, int y) : x(x), y(y) { }
} ;

char grid[550][550];
int dist[550][550], ans[550][550];
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

inline char nextchar() {
  char c = 0;
  while (c <= ' ')
    c = getchar_unlocked();
  return c;
}

void solve(int test_num) {
  memset(dist, 0x3F, sizeof (dist));
  memset(ans, 0, sizeof (ans));
  queue<Point> q;
  int rows, cols, sx, sy, ex, ey;
  scanf("%d %d", &rows, &cols);
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      grid[x][y] = nextchar();
      if (grid[x][y] == 'V')
        sx = x, sy = y;
      if (grid[x][y] == 'J')
        ex = x, ey = y;
      if (grid[x][y] == '+')
        dist[x][y] = 0, q.push(Point(x, y));
    }
  }
  while (!q.empty()) {
    int x = q.front().x, y = q.front().y;
    q.pop();
    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d], ny = y + dy[d];
      if (nx < 0 || nx >= cols || ny < 0 || ny >= rows)
        continue;
      if (dist[x][y] + 1 < dist[nx][ny])
        dist[nx][ny] = dist[x][y] + 1, q.push(Point(nx, ny));
    }
  }
  q.push(Point(sx, sy));
  ans[sx][sy] = dist[sx][sy];
  while (!q.empty()) {
    int x = q.front().x, y = q.front().y;
    q.pop();
    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d], ny = y + dy[d];
      if (nx < 0 || nx >= cols || ny < 0 || ny >= rows)
        continue;
      int nmax = min(dist[nx][ny], ans[x][y]);
      if (nmax > ans[nx][ny])
        ans[nx][ny] = nmax, q.push(Point(nx, ny));
    }
  }
  printf("%d\n", ans[ex][ey]);
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
  NAGAY1::solve();
  return 0;
}

