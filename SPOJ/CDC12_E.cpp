/* Solved
 * 12560. External Falling Objects
 * File:   CDC12_E.cpp
 * Author: Andy Y.F. Huang
 * Created on November 30, 2012, 12:23 AM
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
namespace CDC12_E {

struct Node {
  int r, c, dist;

  Node(int r, int c, int dist) : r(r), c(c), dist(dist) { }

  bool operator<(const Node & n) const {
    return dist > n.dist;
  }
} ;

int dist[1111][1111];
char grid[1111][1111];
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

void solve(int test_num) {
  int height, width, lim;
  scanf("%d %d %d", &height, &width, &lim);
  memset(dist, 0x3F, sizeof (dist));
  priority_queue<Node> q;
  for (int h = 0; h < height; h++)
    scanf("%s", grid[h]);
  for (int r = 0; r < height; r++) {
    for (int c = 0; c < width; c++) {
      if (grid[r][c] == 'R') {
        dist[r][c] = 0;
        q.push(Node(r, c, 0));
        break;
      }
    }
  }
  printf("Scenario #%d: ", test_num);
  while (!q.empty()) {
    int r = q.top().r, c = q.top().c, cdist = q.top().dist;
    q.pop();
    if (grid[r][c] == 'D' && cdist < lim) {
      printf("%d\n", cdist);
      return;
    }
    for (int d = 0; d < 4; d++) {
      int nr = r + dy[d], nc = c + dx[d];
      if (nr < 0 || nr >= height || nc < 0 || nc >= width)
        continue;
      int ndist = cdist + 1;
      if (isdigit(grid[nr][nc]))
        ndist += grid[nr][nc] - '0';
      if (ndist < dist[nr][nc]) {
        q.push(Node(nr, nc, ndist));
        dist[nr][nc] = ndist;
      }
    }
  }
  puts("Ronny will be destroyed");
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
  CDC12_E::solve();
  return 0;
}

