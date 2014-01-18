/* Solved
 * 12880. Sheep
 * 10 minutes to solve lol
 * work first time compiling :D
 * File:   KOZE.cpp
 * Author: Andy Y.F. Huang
 * Created on December 7, 2012, 6:53 PM
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
namespace KOZE {
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int sector[255][255];
char grid[255][255];
int sheep[1 << 18], wolves[1 << 18];

void dfs(int r, int c, int id) {
  sector[r][c] = id;
  if (grid[r][c] == 'k')
    sheep[id]++;
  else if (grid[r][c] == 'v')
    wolves[id]++;
  for (int d = 0; d < 4; d++) {
    int nr = r + dy[d], nc = c + dx[d];
    if (grid[nr][nc] != '#' && sector[nr][nc] == -1)
      dfs(nr, nc, id);
  }
}

void solve(int test_num) {
  memset(grid, '#', sizeof (grid));
  memset(sector, 0xFF, sizeof (sector));
  memset(sheep, 0, sizeof (sheep));
  memset(wolves, 0, sizeof (wolves));
  int rows, cols;
  scanf("%d %d", &rows, &cols);
  for (int r = 1; r <= rows; r++) {
    scanf("%s", grid[r] + 1);
    grid[r][cols + 1] = '#';
  }
  for (int r = 1; r <= rows; r++) {
    if (grid[r][1] != '#' && sector[r][1] == -1)
      dfs(r, 1, 0);
    if (grid[r][cols] != '#' && sector[r][cols] == -1)
      dfs(r, cols, 0);
  }
  for (int c = 1; c <= cols; c++) {
    if (grid[1][c] != '#' && sector[1][c] == -1)
      dfs(1, c, 0);
    if (grid[rows][c] != '#' && sector[rows][c] == -1)
      dfs(rows, c, 0);
  }
  int nextsec = 1;
  for (int r = 1; r <= rows; r++)
    for (int c = 1; c <= cols; c++)
      if (grid[r][c] != '#' && sector[r][c] == -1)
        dfs(r, c, nextsec++);
  int sheepcnt = sheep[0], wolfcnt = wolves[0];
  for (int i = 1; i < nextsec; i++)
    if (sheep[i] > wolves[i])
      sheepcnt += sheep[i];
    else
      wolfcnt += wolves[i];
  printf("%d %d\n", sheepcnt, wolfcnt);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve(1);
}
}

int main() {
  KOZE::solve();
  return 0;
}

