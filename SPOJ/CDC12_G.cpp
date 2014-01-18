/* Solved
 * 12562. Glory War
 * File:   CDC12_G.cpp
 * Author: Andy Y.F. Huang
 * Created on December 8, 2012, 10:38 AM
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
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <iomanip>
#include <cassert>
#include <ctime>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace CDC12_G {

struct Node {
  int x, y, z;

  Node(int x, int y, int z) : x(x), y(y), z(z) { }
} ;

const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
const int dz[] = {0, 1, -1};
char grid[25][25][25];
int shpath[11][11], order[11], fromst[11];
int tx[11], ty[11], tz[11];
int dist[25][25][25];

int bfs(int sx, int sy, int sz) {
  memset(dist, 0x3F, sizeof (dist));
  dist[sz][sx][sy] = 0;
  queue<Node> q;
  q.push(Node(sx, sy, sz));
  while (!q.empty()) {
    int x = q.front().x, y = q.front().y, z = q.front().z;
    q.pop();
    for (int d = 0; d < 3; d++) {
      int nz = z + dz[d];
      for (int dd = 0; dd < 4; dd++) {
        int nx = x + dx[dd], ny = y + dy[dd];
        if (grid[nz][nx][ny] != '#' && dist[z][x][y] + 1 < dist[nz][nx][ny]) {
          dist[nz][nx][ny] = dist[z][x][y] + 1;
          q.push(Node(nx, ny, nz));
        }
      }
    }
  }
  return -1;
}

void solve(int test_num) {
  memset(grid, '#', sizeof (grid));
  memset(shpath, 0x3F, sizeof (shpath));
  int height, size, tars = 0;
  scanf("%d %d", &size, &height);
  for (int h = 1; h <= height; h++) {
    for (int r = 1; r <= size; r++) {
      scanf("%s", grid[h][r] + 1);
      grid[h][r][size + 1] = '#';
      for (int c = 1; c <= size; c++)
        if (grid[h][r][c] == '*')
          tx[tars] = r, ty[tars] = c, tz[tars++] = h;
    }
  }
  for (int i = 0; i < tars; i++) {
    bfs(tx[i], ty[i], tz[i]);
    for (int j = i; j < tars; j++)
      shpath[i][j] = shpath[j][i] = dist[tz[j]][tx[j]][ty[j]];
    fromst[i] = dist[1][1][1];
    order[i] = i;
  }
  printf("Scenario #%d: ", test_num);
  int ans = 1 << 30;
  do {
    int total = fromst[order[0]];
    for (int i = 0; i < tars - 1 && total <= (1 << 20); i++)
      total += shpath[order[i]][order[i + 1]];
    ans = min(ans, total);
  } while (next_permutation(order, order + tars));
  printf("%d\n", ans >= (1 << 20) ? -1 : ans);
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
  CDC12_G::solve();
  return 0;
}

