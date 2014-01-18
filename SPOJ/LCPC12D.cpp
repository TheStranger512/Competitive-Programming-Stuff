/* Solved
 * 12399. Johnny Hates Climbing
 * File:   LCPC12D.cpp
 * Author: Andy Y.F. Huang
 * Created on October 8, 2012, 1:56 PM
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
 * Unsolved
 * @author Andy Y.F. Huang
 */
namespace LCPC12D {
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int rows, cols, ex, ey;
int height[22][22];
bool can[11][11];
queue<pair<int, int> > q;

bool poss(int limit) {
  memset(can, false, sizeof (can));
  for (int y = 1; y <= rows; y++) {
    can[1][y] = can[cols][y] = true;
    q.push(make_pair(1, y));
    q.push(make_pair(cols, y));
  }
  for (int x = 1; x <= cols; x++) {
    can[x][1] = can[x][rows] = true;
    q.push(make_pair(x, 1));
    q.push(make_pair(x, rows));
  }
  while (!q.empty()) {
    int x = q.front().first, y = q.front().second;
    q.pop();
    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d], ny = y + dy[d];
      if (height[nx][ny] <= height[x][y] &&
              height[x][y] - height[nx][ny] <= limit && !can[nx][ny]) {
        can[nx][ny] = true;
        q.push(make_pair(nx, ny));
      }
    }
  }
  return can[ex][ey];
}

void solve(int test_num) {
  memset(height, 0x3F, sizeof (height));
  scanf("%d %d %d %d", &rows, &cols, &ey, &ex);
  for (int y = 1; y <= rows; y++)
    for (int x = 1; x <= cols; x++)
      scanf("%d", &height[x][y]);
  int ans = 1 << 20;
  for (int low = 0, high = 1000; low <= high; ) {
    int mid = (low + high) >> 1;
    if (poss(mid)) {
      ans = min(ans, mid);
      high = mid - 1;
    }
    else
      low = mid + 1;
  }
  printf("%d. ", test_num);
  if (ans > 1000)
    puts("IMPOSSIBLE");
  else
    printf("%d \n", ans);
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
  LCPC12D::solve();
  return 0;
}

