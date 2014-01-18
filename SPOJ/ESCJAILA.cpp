/* Solved
 * 7422. Escape from Jail Again - bfs
 * File:   ESCJAILA.cpp
 * Author: Andy Y.F. Huang
 * Created on September 7, 2012, 10:13 PM
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
namespace ESCJAILA {

struct Node {
  int x, y, opened;

  Node(int x, int y, int opened) : x(x), y(y), opened(opened) { }
} ;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int rows, cols, dist[110][110][2];
char grid[110][110];

inline char nextchar() {
  char c = 0;
  while (c <= ' ') c = getchar_unlocked();
  return c;
}

void solve(int test_num) {
  memset(grid, '.', sizeof (grid));
  memset(dist, 0x3F, sizeof (dist));
  int sx, sy;
  for (int y = 1; y <= rows; y++) {
    for (int x = 1; x <= cols; x++) {
      grid[x][y] = nextchar();
      if (grid[x][y] == 'H')
        sx = x, sy = y;
    }
  }
  dist[sx][sy][0] = 0;
  queue<Node> q;
  q.push(Node(sx, sy, 0));
  while (!q.empty()) {
    int x = q.front().x, y = q.front().y, opened = q.front().opened;
    q.pop();
    if (x < 1 || x > cols || y < 1 || y > rows) {
      printf("%d\n", dist[x][y][opened]);
      return;
    }
    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d], ny = y + dy[d];
      if (grid[nx][ny] == 'W' || (grid[x][y] == 'D' && !opened))
        continue;
      int nopened = opened;
      if (grid[nx][ny] == 'O')
        nopened = 1;
      if (grid[nx][ny] == 'C')
        nopened = 0;
      if (dist[x][y][opened] + 1 < dist[nx][ny][nopened]) {
        dist[nx][ny][nopened] = dist[x][y][opened] + 1;
        q.push(Node(nx, ny, nopened));
      }
    }
  }
  puts("-1");
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (true) {
    scanf("%d %d", &rows, &cols);
    if (rows == -1 && cols == -1)
      break;
    solve(1);
  }
}
}

int main() {
  ESCJAILA::solve();
  return 0;
}

