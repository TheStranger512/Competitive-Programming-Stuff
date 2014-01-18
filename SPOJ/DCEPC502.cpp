/* Solved
 * 11405. Just Like the Good Old Days
 * File:   DCEPC502.cpp
 * Author: Andy Y.F. Huang
 * Created on May 29, 2013, 6:09 PM
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

namespace DCEPC502 {
const int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
const int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};
char grid[11][11];
int id[11][11];
bool adj[11][11];

void solve(int test_num) {
  int rows, cols, vertices = 0;
  scanf("%d %d", &rows, &cols);
  for (int r = 0; r < rows; r++)
    scanf("%s", grid[r]);
  memset(id, -1, sizeof (id));
  for (int r = 0; r < rows; r++)
    for (int c = 0; c < cols; c++)
      if (grid[r][c] == '.')
        id[r][c] = vertices++;
  memset(adj, false, sizeof (adj));
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      if (!~id[r][c])
        continue;
      adj[id[r][c]][id[r][c]] = true;
      for (int d = 0, nr, nc; d < 8; d++) {
        nr = r + dy[d];
        nc = c + dx[d];
        if (nr < 0 || nr >= rows || nc < 0 || nc >= cols)
          continue;
        if (~id[nr][nc])
          adj[id[r][c]][id[nr][nc]] = true;
      }
    }
  }
  //plnarr(adj, vertices, vertices);
  int res = 0;
  for (int mask = (1 << vertices) - 1; mask >= 0; mask--) {
    int black = 0, white = vertices;
    for (int i = 0; i < vertices; i++) {
      if (1 << i & mask)
        black++;
      for (int j = 0; j < vertices; j++) {
        if (adj[i][j] && (1 << j & mask)) {
          white--;
          break;
        }
      }
    }
    res = max(res, 2 * min(white, black) + (black != white));
  }
  printf("%d\n", res);
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
  DCEPC502::solve();
  return 0;
}

