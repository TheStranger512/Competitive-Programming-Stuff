/* Solved
 * 8363. COSTLY CHESS - dijkstras
 * File:   CCHESS.cpp
 * Author: Andy Y.F. Huang
 * Created on September 6, 2012, 11:39 PM
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
namespace CCHESS {

struct Node {
  int x, y, cdist;

  Node(int x, int y, int cdist) : x(x), y(y), cdist(cdist) { }

  bool operator<(const Node & n) const {
    return cdist > n.cdist;
  }
} ;

const int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
const int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};
int dist[9][9], sx, sy, ex, ey;
priority_queue<Node> q;

void solve(int test_num) {
  while (!q.empty())
    q.pop();
  memset(dist, 0x3F, sizeof (dist));
  dist[sx][sy] = 0;
  q.push(Node(sx, sy, 0));
  while (!q.empty()) {
    int x = q.top().x, y = q.top().y, cdist = q.top().cdist;
    q.pop();
    if (cdist > dist[x][y])
      continue;
    if (x == ex && y == ey) {
      printf("%d\n", dist[x][y]);
      return;
    }
    for (int d = 0; d < 8; d++) {
      int nx = x + dx[d], ny = y + dy[d];
      if (nx < 0 || nx > 7 || ny < 0 || ny > 7)
        continue;
      int ndist = cdist + x * nx + y * ny;
      if (ndist < dist[nx][ny]) {
        dist[nx][ny] = ndist;
        q.push(Node(nx, ny, ndist));
      }
    }
  }
  printf("%d\n", -1);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (scanf("%d %d %d %d", &sx, &sy, &ex, &ey) != EOF)
    solve(1);
}
}

int main() {
  CCHESS::solve();
  return 0;
}

