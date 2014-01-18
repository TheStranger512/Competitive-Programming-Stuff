/* Solved
 * 10439. Walking Robot
 * File:   WALKROBO.cpp
 * Author: Andy Y.F. Huang
 * Created on December 31, 2012, 3:42 PM
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
#include <functional>
#include <complex>
#include <numeric>
#include <cctype>
#include <cstddef>
#include <utility>
#include <valarray>
#include <cstdlib>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace WALKROBO {

struct Node {
  int x, y, mask;

  Node(int y, int x, int mask) : x(x), y(y), mask(mask) { }
} ;

int dist[15][15][1 << 12];
int grid[15][15];
int mx[12], my[12];
int rows, cols, movecnt, known;

void solve(int test_num) {
  memset(dist, 0x3F, sizeof (dist));
  for (int i = 0; i < movecnt; i++) {
    scanf("%d %d", &mx[i], &my[i]);
    my[i] = -my[i];
  }
  int startmask = 0;
  for (int i = 0; i < known; i++) {
    int move;
    scanf("%d", &move);
    startmask |= 1 << (--move);
  }
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      scanf("%d", &grid[r][c]);
      grid[r][c]--;
    }
  }
  printf("Case #%d: ", test_num);
  queue<Node> q;
  dist[rows - 1][0][startmask] = 0;
  for (q.push(Node(rows - 1, 0, startmask)); !q.empty(); q.pop()) {
    int x = q.front().x, y = q.front().y, mask = q.front().mask;
    int cdist = dist[y][x][mask];
    if (y == 0 && x == cols - 1) {
      printf("%d\n", cdist);
      return;
    }
    if (grid[y][x] >= 0) {
      int nmask = 1 << grid[y][x] | mask;
      if (cdist + 1 < dist[y][x][nmask]) {
        dist[y][x][nmask] = cdist + 1;
        q.push(Node(y, x, nmask));
      }
    }
    for (int d = 0; d < movecnt; d++) {
      if (!(1 << d & mask)) continue;
      int ny = y + my[d], nx = x + mx[d];
      if (ny < 0 || ny >= rows || nx < 0 || nx >= cols)
        continue;
      if (cdist + 1 < dist[ny][nx][mask]) {
        dist[ny][nx][mask] = cdist + 1;
        q.push(Node(ny, nx, mask));
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
  for (int i = 1; ; i++) {
    scanf("%d %d %d %d", &rows, &cols, &movecnt, &known);
    if (rows == 0) break;
    solve(i);
  }
}
}

int main() {
  WALKROBO::solve();
  return 0;
}

