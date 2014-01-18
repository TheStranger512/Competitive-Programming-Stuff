/* Solved
 * 2053. Key Task
 * File:   CERC07K.cpp
 * Author: Andy Y.F. Huang
 * Created on August 24, 2012, 1:22 PM
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
namespace CERC07K {

struct Node {
  int x, y, keys;

  Node(int x, int y, int keys) : x(x), y(y), keys(keys) {
  }
} ;

char grid[110][110];
int dist[110][110][1 << 4];
queue<Node> q;
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };

void solve(int test_num, int rows, int cols) {
  memset(grid, '#', sizeof (grid));
  memset(dist, 0x3F, sizeof (dist));
  int sx = -1, sy = -1;
  for (int y = 1; y <= rows; y++) {
    for (int x = 1; x <= cols; x++) {
      grid[x][y] = 0;
      while (grid[x][y] <= ' ')
        grid[x][y] = getchar_unlocked();
      if (grid[x][y] == '*') {
        sx = x;
        sy = y;
      }
      else if (grid[x][y] == 'b')
        grid[x][y] = 0;
      else if (grid[x][y] == 'y')
        grid[x][y] = 1;
      else if (grid[x][y] == 'r')
        grid[x][y] = 2;
      else if (grid[x][y] == 'g')
        grid[x][y] = 3;
      else if (grid[x][y] == 'B')
        grid[x][y] = 4;
      else if (grid[x][y] == 'Y')
        grid[x][y] = 5;
      else if (grid[x][y] == 'R')
        grid[x][y] = 6;
      else if (grid[x][y] == 'G')
        grid[x][y] = 7;
    }
  }
  dist[sx][sy][0] = 0;
  q.push(Node(sx, sy, 0));
  while (!q.empty()) {
    int x = q.front().x, y = q.front().y, keys = q.front().keys;
    q.pop();
    // pln(x, y, keys);
    if (grid[x][y] == 'X') {
      printf("Escape possible in %d steps.\n", dist[x][y][keys]);
      return;
    }
    int nkeys = keys;
    if (grid[x][y] <= 3)
      nkeys |= (1 << (grid[x][y]));
    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d], ny = y + dy[d];
      if (grid[nx][ny] == '#')
        continue;
      if (4 <= grid[nx][ny] && grid[nx][ny] <= 7
              && ((1 << (grid[nx][ny] - 4)) & nkeys) == 0)
        continue;
      if (dist[x][y][keys] + 1 < dist[nx][ny][nkeys]) {
        dist[nx][ny][nkeys] = dist[x][y][keys] + 1;
        q.push(Node(nx, ny, nkeys));
      }
    }
  }
  puts("The poor student is trapped!");
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (true) {
    int rows, cols;
    scanf("%d %d", &rows, &cols);
    if (rows == 0)
      break;
    solve(1, rows, cols);
  }
}
}

int main() {
  CERC07K::solve();
  return 0;
}

