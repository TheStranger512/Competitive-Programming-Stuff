/* Solved
 * 4525. Digger Octaves
 * File:   UCI2009D.cpp
 * Author: Andy Y.F. Huang
 * Created on February 17, 2013, 1:08 AM
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

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace UCI2009D {
typedef unsigned long long ullong;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
char grid[11][11];
vector<ullong> ans;
bool vis[11][11];
int size;

void dfs(int row, int col, int len, ullong mask) {
  if (len == 8) {
    ans.push_back(mask);
    return;
  }
  vis[row][col] = true;
  for (int d = 0; d < 4; d++) {
    int nr = row + dy[d], nc = col + dx[d];
    if (!vis[nr][nc] && grid[nr][nc] == 'X')
      dfs(nr, nc, len + 1, mask | 1LLu << ((nr - 1) * size + nc - 1));
  }
  vis[row][col] = false;
}

void solve(int test_num) {
  memset(grid, '.', sizeof (grid));
  ans.clear();
  scanf("%d", &size);
  for (int r = 1; r <= size; r++) {
    scanf("%s", grid[r] + 1);
    grid[r][size + 1] = '.';
  }
  for (int r = 1; r <= size; r++)
    for (int c = 1; c <= size; c++)
      if (grid[r][c] == 'X')
        dfs(r, c, 1, 1LLu << ((r - 1) * size + c - 1));
  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end());
  printf("%d\n", ans.size());
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
  UCI2009D::solve();
  return 0;
}

