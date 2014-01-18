/* Solved
 * 12887. Ant Colony Optimization
 * File:   DCEPCA02.cpp
 * Author: Andy Y.F. Huang
 * Created on December 7, 2012, 10:51 PM
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
namespace DCEPCA02 {

struct Node {
  int type, x, y;

  Node(int type, int x, int y) : type(type), x(x), y(y) { }
} ;

const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int rows, cols;
int dist[2][555][555];
int sx, sy, ex, ey;
char str[55];
bool poss[2][4];

int getdir(char c) {
  //pln(c);
  if (c == 'U') return 2;
  if (c == 'R') return 1;
  if (c == 'D') return 0;
  else return 3;
}

void solve(int test_num) {
  memset(dist, 0x3F, sizeof (dist));
  memset(poss, false, sizeof (poss));
  scanf("%d %d %d %d %d %d %s", &cols, &rows, &sx, &sy, &ex, &ey, str);
  poss[0][getdir(str[0])] = poss[0][getdir(str[1])] = true;
  poss[1][getdir(str[2])] = poss[1][getdir(str[3])] = true;
  dist[0][sy][sx] = dist[1][sy][sx] = 0;
  queue<Node> q;
  q.push(Node(0, sx, sy));
  q.push(Node(1, sx, sy));
  while (!q.empty()) {
    int type = q.front().type, x = q.front().x, y = q.front().y;
    q.pop();
    int cdist = dist[type][y][x];
    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d], ny = y + dy[d];
      if (nx < 0 || nx >= cols || ny < 0 || ny >= rows)
        continue;
      int ntype = poss[type][d] ? type : (type ^ 1);
      if (cdist + 1 < dist[ntype][ny][nx]) {
        dist[ntype][ny][nx] = cdist + 1;
        q.push(Node(ntype, nx, ny));
      }
    }
  }
  int dist1 = dist[0][ey][ex], dist2 = dist[1][ey][ex];
  //pln(dist1, dist2);
  if (dist1 > (1 << 20) || dist2 > (1 << 20))
    puts("-1");
  else
    printf("%d\n", dist1 + dist2);
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
  DCEPCA02::solve();
  return 0;
}

