/* Solved
 * IOI '09 - Plovdiv, Bulgaria - Mecho
 * File:   ioi0922.cpp
 * Author: Andy Y.F. Huang
 * Created on August 16, 2012, 2:42 PM
 */

#include <cstdio>
#include <queue>
#include <cstring>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace ioi0922 {

struct Point {
  int x, y;

  Point(int x, int y) : x(x), y(y) {
  }
} ;

const char dx[] = {0, 1, 0, -1};
const char dy[] = {1, 0, -1, 0};
char grid[850][850];
const int inf = 12345678;
int size, step, bee[850][850], dist[850][850], sx, sy, ex, ey;
queue<Point> q;

void swarm() {
  while (!q.empty()) {
    Point cur = q.front();
    q.pop();
    int cdist = bee[cur.x][cur.y];
    for (int d = 0; d < 4; d++) {
      int nx = cur.x + dx[d], ny = cur.y + dy[d];
      if (grid[nx][ny] == 'G' && cdist + step < bee[nx][ny]) {
        bee[nx][ny] = cdist + step;
        q.push(Point(nx, ny));
      }
    }
  }
}

void printbee() {
  for (int y = 1; y <= size; y++, putchar('\n'))
    for (int x = 1; x <= size; x++)
      printf("%3d ", bee[x][y] > inf ? -1 : bee[x][y]);
}

bool poss(int start) {
  memset(dist, 0x3F, sizeof (dist));
  dist[sx][sy] = start * step;
  if (bee[sx][sy] <= dist[sx][sy])
    return false;
  q.push(Point(sx, sy));
  while (!q.empty()) {
    Point cur = q.front();
    q.pop();
    if (cur.x == ex && cur.y == ey)
      return true;
    int x = cur.x, y = cur.y, ndist = dist[x][y] + 1;
    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d], ny = y + dy[d];
      if (grid[nx][ny] == 'G' && ndist < bee[nx][ny] && ndist < dist[nx][ny]) {
        dist[nx][ny] = ndist;
        q.push(Point(nx, ny));
      }
    }
  }
  return false;
}

void solve(int test_num) {
  memset(grid, 'T', sizeof (grid));
  memset(bee, 0x3F, sizeof (bee));
  scanf("%d %d", &size, &step);
  for (int y = 1; y <= size; y++) {
    for (int x = 1; x <= size; x++) {
      grid[x][y] = 0;
      while (grid[x][y] <= ' ')
        grid[x][y] = getchar_unlocked();
      if (grid[x][y] == 'M')
        sx = x, sy = y, grid[x][y] = 'G';
      else if (grid[x][y] == 'D')
        ex = x, ey = y;
      else if (grid[x][y] == 'H')
        q.push(Point(x, y)), bee[x][y] = 0;
    }
  }
  swarm();
  //printbee();
  grid[ex][ey] = 'G'; //simplifies search
  int low = 0, high = size * size;
  while (low < high) {
    int mid = ((low + high) >> 1) + ((low + high) & 1);
    if (poss(mid))
      low = mid;
    else
      high = mid - 1;
  }
  if (poss(low))
    printf("%d\n", low);
  else
    puts("-1");
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
  ioi0922::solve();
  return 0;
}

