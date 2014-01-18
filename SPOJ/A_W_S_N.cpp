/* Solved
 * 13738. Happy Valentine Day (Valentine Maze Game)
 * File:   A_W_S_N.cpp
 * Author: Andy Y.F. Huang
 * Created on March 12, 2013, 12:30 AM
 */

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

namespace A_W_S_N {
typedef pair<int, int> Node;
const int DX[] = {0, 1, 0, -1};
const int DY[] = {-1, 0, 1, 0};
char grid[111][111];
int cdist[111][111], stdist[111][111];
int cx[11], cy[11];
int dp[11][1 << 11];
int adj[11][11];
int toend[11];

void bfs(int dist[111][111], int sr, int sc) {
  memset(dist, 0x3F, sizeof (cdist));
  dist[sr][sc] = 0;
  queue<Node> q;
  q.push(Node(sr, sc));
  for (; !q.empty(); q.pop()) {
    int r = q.front().first, c = q.front().second;
    for (int d = 0, nr, nc; d < 4; d++) {
      nr = r + DY[d];
      nc = c + DX[d];
      if (grid[nr][nc] != '#' && dist[r][c] + 1 < dist[nr][nc]) {
        dist[nr][nc] = dist[r][c] + 1;
        q.push(Node(nr, nc));
      }
    }
  }
}

void checkmin(int&a, int b) {
  if (b < a) a = b;
}

void solve(int test_num) {
  int rows, cols;
  memset(grid, '#', sizeof (grid));
  scanf("%d %d", &rows, &cols);
  int sr = -1, sc = -1, er = -1, ec = -1;
  int cnt = 0;
  for (int r = 1; r <= rows; r++) {
    scanf("%s", grid[r] + 1);
    grid[r][cols + 1] = '#';
    for (int c = 1; c <= cols; c++) {
      if (grid[r][c] == 'T')
        sr = r, sc = c, grid[r][c] = '.';
      if (grid[r][c] == 'W')
        er = r, ec = c, grid[r][c] = '.';
      if (grid[r][c] == 'C') {
        cx[cnt] = r, cy[cnt] = c, grid[r][c] = '.';
        cnt++;
      }
    }
  }
  if (cnt == 0) {
    bfs(stdist, sr, sc);
    if (stdist[er][ec] < 1e6)
      printf("%d\n", stdist[er][ec]);
    else puts("Mission Failed!");
    return;
  }
  bfs(stdist, sr, sc);
  for (int i = 0; i < cnt; i++) {
    bfs(cdist, cx[i], cy[i]);
    toend[i] = cdist[er][ec];
    adj[i][i] = 0;
    for (int j = i + 1; j < cnt; j++)
      adj[i][j] = adj[j][i] = cdist[cx[j]][cy[j]];
  }
  memset(dp, 0x3F, sizeof (dp));
  int res = 1 << 30;
  for (int i = 0; i < cnt; i++)
    dp[i][1 << i] = stdist[cx[i]][cy[i]];
  for (int mask = 1; mask < (1 << cnt); mask++)
    for (int ed = 0; ed < cnt; ed++)
      if (dp[ed][mask] < 1e6)
        for (int by = 0; by < cnt; by++)
          if (!(1 << by & mask))
            checkmin(dp[by][1 << by | mask], dp[ed][mask] + adj[ed][by]);
  for (int i = 0; i < cnt; i++)
    res = min(res, dp[i][(1 << cnt) - 1] + toend[i]);
  if (res > 1e6) puts("Mission Failed!");
  else printf("%d\n", res);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  A_W_S_N::solve();
  return 0;
}

