/* Solved
 * 3387. Changing Maze
 * File:   CHMAZE.cpp
 * Author: Andy Y.F. Huang
 * Created on August 14, 2012, 10:08 PM
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
namespace CHMAZE {

struct Node {
  int x, y, d, parity;

  Node(int x, int y, int d, int parity) : x(x), y(y), d(d), parity(parity) {
  }
} ;

const char dx[] = {0, 1, 0, -1, 0};
const char dy[] = {1, 0, -1, 0, 0};
int rows, cols, depth, dist[25][25][15][2];
char grid[25][25][15];
queue<Node> q;

void solve(int test_num) {
  memset(grid, '1', sizeof (grid));
  memset(dist, 0x3F, sizeof (dist));
  while (!q.empty())
    q.pop();
  for (int d = 0; d < depth; d++) {
    for (int y = 1; y <= rows; y++) {
      for (int x = 1; x <= cols; x++) {
        grid[x][y][d] = 0;
        while (grid[x][y][d] < '0')
          grid[x][y][d] = getchar_unlocked();
      }
    }
  }
  dist[1][1][0][0] = 0;
  q.push(Node(1, 1, 0, 0));
  while (!q.empty()) {
    Node cur = q.front();
    //pln(cur.x, cur.y, cur.d);
    q.pop();
    int ndist = dist[cur.x][cur.y][cur.d][cur.parity] + 1;
    int ndepth = ndist % depth;
    int nparity = cur.parity ^ 1;
    if (cur.x == cols && cur.y == rows) {
      printf("Case %d: Luke and Leia can escape in %d steps.\n", test_num, ndist - 1);
      return;
    }
    for (int d = 0; d < 5; d++) {
      int nx = cur.x + dx[d], ny = cur.y + dy[d];
      if (grid[nx][ny][ndepth] == '0' && ndist < dist[nx][ny][ndepth][nparity]) {
        dist[nx][ny][ndepth][nparity] = ndist;
        q.push(Node(nx, ny, ndepth, nparity));
      }
    }
  }
  printf("Case %d: Luke and Leia cannot escape.\n", test_num);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int i = 1;
  while (true) {
    scanf("%d %d %d", &rows, &cols, &depth);
    if (rows == 0)
      break;
    solve(i++);
  }
}
}

int main() {
  CHMAZE::solve();
  return 0;
}

