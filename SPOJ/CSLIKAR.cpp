/* Solved
 * 13076. Slikar
 * File:   CSLIKAR.cpp
 * Author: Andy Y.F. Huang
 * Created on December 28, 2012, 5:29 PM
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
namespace CSLIKAR {
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
char grid[55][55];
int dist[55][55];
pair<int, int> toflood[2555], oldflood[2555];

void solve(int test_num) {
  memset(grid, 'X', sizeof (grid));
  memset(dist, 0x3F, sizeof (dist));
  int rows, cols, oldlen = 0, len;
  scanf("%d %d", &rows, &cols);
  queue<pair<int, int> > q;
  for (int r = 1; r <= rows; r++) {
    scanf("%s", grid[r] + 1);
    grid[r][cols + 1] = 'X';
    for (int c = 1; c <= cols; c++) {
      if (grid[r][c] == 'S')
        q.push(make_pair(r, c)), grid[r][c] = '.', dist[r][c] = 0;
      if (grid[r][c] == '*')
        oldflood[oldlen++] = make_pair(r, c), grid[r][c] = 'X';
    }
  }
  int curdist = 0;
  for (; !q.empty(); q.pop()) {
    int r = q.front().first, c = q.front().second;
    if (dist[r][c] == curdist) {
      len = 0;
      for (int i = 0; i < oldlen; i++) {
        int row = oldflood[i].first, col = oldflood[i].second;
        for (int d = 0; d < 4; d++)
          if (grid[row + dy[d]][col + dx[d]] == '.') {
            toflood[len++] = make_pair(row + dy[d], col + dx[d]);
            grid[row + dy[d]][col + dx[d]] = 'X';
          }
      }
      memcpy(oldflood, toflood, sizeof (toflood));
      oldlen = len;
      curdist++;
    }
    if (grid[r][c] == 'D') {
      printf("%d\n", dist[r][c]);
      return;
    }
    for (int d = 0; d < 4; d++) {
      int nr = r + dy[d], nc = c + dx[d];
      if (grid[nr][nc] != 'X' && curdist < dist[nr][nc]) {
        q.push(make_pair(nr, nc));
        dist[nr][nc] = curdist;
      }
    }
  }
  puts("KAKTUS");
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests = 1;
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  CSLIKAR::solve();
  return 0;
}

