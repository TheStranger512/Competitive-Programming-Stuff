/* Solved
 * 11472. Amazing Maze
 * File:   DCEPC701.cpp
 * Author: Andy Y.F. Huang
 * Created on August 28, 2012, 3:06 PM
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
namespace DCEPC701 {

struct Node {
  int x, y, cdist;

  Node(int x, int y, int dist) : x(x), y(y), cdist(dist) { }

  bool operator<(const Node & n) const {
    return cdist > n.cdist;
  }
} ;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int inf = 123456;
char grid[210][210];
int wait[210][210], dist[210][210];
priority_queue<Node> q;

inline char nextchar() {
  char c = 0;
  while (c <= ' ') c = getchar_unlocked();
  return c;
}

void solve(int test_num) {
  while (!q.empty())
    q.pop();
  memset(wait, 0x3F, sizeof (wait));
  memset(dist, 0x3F, sizeof (dist));
  int rows, cols, sx, sy, ex, ey;
  scanf("%d %d", &rows, &cols);
  for (int y = 1; y <= rows; y++)
    for (int x = 1; x <= cols; x++)
      grid[x][y] = nextchar();
  for (int y = 1; y <= rows; y++)
    for (int x = 1; x <= cols; x++)
      scanf("%d", &wait[x][y]);
  scanf("%d %d %d %d", &sy, &sx, &ey, &ex);
  dist[++sx][++sy] = 0;
  ex++, ey++;
  q.push(Node(sx, sy, 0));
  while (!q.empty()) {
    int x = q.top().x, y = q.top().y, cdist = q.top().cdist;
    q.pop();
    if (x == ex && y == ey) {
      printf("%d\n", cdist);
      return;
    }
    if (cdist > dist[x][y])
      continue;
    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d], ny = y + dy[d];
      if (wait[nx][ny] >= inf)
        continue;
      if (wait[nx][ny] == 0 && cdist + 1 < dist[nx][ny])
        q.push(Node(nx, ny, dist[nx][ny] = cdist + 1));
      else if (wait[nx][ny] != 0) {
        int ndist = max(cdist + 1, wait[nx][ny]);
        if (ndist < dist[nx][ny])
          q.push(Node(nx, ny, dist[nx][ny] = ndist));
      }
    }
  }
  assert(false);
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
  DCEPC701::solve();
  return 0;
}

