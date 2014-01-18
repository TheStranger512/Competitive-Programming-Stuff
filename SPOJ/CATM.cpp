/* Solved
 * 1418. The Cats and the Mouse - bfs
 * File:   CATM.cpp
 * Author: Andy Y.F. Huang
 * Created on September 4, 2012, 8:27 PM
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
namespace CATM {
const char dx[] = {0, 1, 0, -1};
const char dy[] = {1, 0, -1, 0};
int catdist[110][110], mousedist[110][110], qx[40010], qy[40010];

void solve(int test_num, int rows, int cols) {
  memset(catdist, 0x3F, sizeof (catdist));
  memset(mousedist, 0x3F, sizeof (mousedist));
  int mousey, mousex, sx1, sy1, sx2, sy2;
  scanf("%d %d %d %d %d %d", &mousey, &mousex, &sy1, &sx1, &sy2, &sx2);
  if ((mousey == sy1 && mousex == sx1) || (mousex == sx2 && mousey == sy2)) {
    puts("NO");
    return;
  }
  int qf = 0, qb = 0;
  catdist[sx1][sy1] = catdist[sx2][sy2] = 0;
  qx[qb] = sx1, qy[qb++] = sy1;
  qx[qb] = sx2, qy[qb++] = sy2;
  while (qf < qb) {
    int x = qx[qf], y = qy[qf++];
    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d], ny = y + dy[d];
      if (nx < 1 || nx > cols || ny < 1 || ny > rows)
        continue;
      if (catdist[x][y] + 1 < catdist[nx][ny]) {
        catdist[nx][ny] = catdist[x][y] + 1;
        qx[qb] = nx, qy[qb++] = ny;
      }
    }
  }
  //  for (int y = 0; y <= rows + 1; y++)
  //    for (int x = 0; x <= cols + 1; x++)
  //      printf("%10d%c", catdist[x][y], x == cols + 1 ? '\n' : ' ');
  // puts("");
  qf = qb = 0;
  mousedist[mousex][mousey] = 0;
  qx[qb] = mousex, qy[qb++] = mousey;
  while (qf < qb) {
    int x = qx[qf], y = qy[qf++];
    if (x < 1 || x > cols || y < 1 || y > rows) {
      puts("YES");
      return;
    }
    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d], ny = y + dy[d];
      if (mousedist[x][y] + 1 < mousedist[nx][ny]
              && mousedist[x][y] + 1 < catdist[nx][ny]) {
        mousedist[nx][ny] = mousedist[x][y] + 1;
        qx[qb] = nx, qy[qb++] = ny;
      }
    }
  }
  //  for (int y = 0; y <= rows + 1; y++)
  //    for (int x = 0; x <= cols + 1; x++)
  //      printf("%10d%c", mousedist[x][y], x == cols + 1 ? '\n' : ' ');
  puts("NO");
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int rows, cols, tests;
  scanf("%d %d %d", &rows, &cols, &tests);
  for (int i = 1; i <= tests; i++)
    solve(1, rows, cols);
}
}

int main() {
  CATM::solve();
  return 0;
}

