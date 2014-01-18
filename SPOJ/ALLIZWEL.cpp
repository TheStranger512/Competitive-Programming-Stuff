/* Solved
 * 10283. ALL IZZ WELL
 * File:   ALLIZWEL.cpp
 * Author: Andy Y.F. Huang
 * Created on August 6, 2012, 1:03 AM
 */

#include <cstdio>
#include <cstring>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace ALLIZWEL {
char grid[110][110];
const char* k_str = "ALLIZZWELL";
const char dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
const char dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
const int k_len = 10;
bool moi[110][110];
int rows, cols;

bool oob(int x, int y) {
  return x < 0 || x >= cols || y < 0 || y >= rows;
}

bool dfs(int x, int y, int pos) {
  if (pos == k_len - 1)
    return true;
  moi[x][y] = true;
  for (int dir = 0; dir < 8; dir++) {
    int nx = x + dx[dir], ny = y + dy[dir];
    if (!oob(nx, ny) && !moi[nx][ny] && grid[nx][ny] == k_str[pos + 1])
      if (dfs(nx, ny, pos + 1))
        return true;
  }
  return moi[x][y] = false;
}

void solve(int test_num) {
  scanf("%d %d", &cols, &rows);
  for (int x = 0; x < cols; x++)
    scanf("%s", grid[x]);
  for (int y = 0; y < rows; y++)
    for (int x = 0; x < cols; x++)
      if (grid[x][y] == 'A') {
        memset(moi, false, sizeof (moi));
        if (dfs(x, y, 0)) {
          puts("YES");
          return;
        }
      }
  puts("NO");
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
  ALLIZWEL::solve();
  return 0;
}

