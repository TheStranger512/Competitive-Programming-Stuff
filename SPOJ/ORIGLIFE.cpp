/* Solved
 * 1267. Origin of Life - very hackish right now
 * File:   ORIGLIFE.cpp
 * Author: Andy Y.F. Huang
 * Created on August 4, 2012, 12:08 AM
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
namespace ORIGLIFE {
const int k_max_size = 1 << 20, inf = 12345;
int rows, cols, a, b, c, moi[k_max_size], succ[k_max_size];
const char dx[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
const char dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
char str[25];

int next(int cur) {
  int ans = 0;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      int alive = 0;
      int bit = y * cols + x;
      for (int d = 0; d < 8; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx < 0 || nx >= cols || ny < 0 || ny >= rows)
          continue;
        if ((1 << (ny * cols + nx) & cur) > 0) //alive neighbour
          alive++;
      }
      if ((1 << bit & cur) > 0) { //already alive
        if (a <= alive && alive <= b)
          ans += 1 << bit;
      }
      else if (alive > c)
        ans += 1 << bit;
    }
  }
  succ[cur] = ans;
  return ans;
}

void dfs(int state, int steps) {
  moi[state] = steps;
  int nextstate = succ[state];
  if (steps + 1 < moi[nextstate])
    dfs(nextstate, steps + 1);
}

void solve(int test_num) {
  int nrows, ncols;
  scanf("%d %d %d %d %d", &nrows, &ncols, &a, &b, &c);
  int init = 0;
  for (int y = 0; y < nrows; y++) {
    scanf("%s", str);
    for (int x = 0; x < ncols; x++)
      if (str[x] == '*')
        init += (1 << (y * ncols + x));
  }
  int mask = 1 << (nrows * ncols);
  if (nrows == rows && ncols == cols)
    goto end;
  memset(moi, 0, sizeof (moi));
  rows = nrows, cols = ncols;
  while (mask--)
    moi[next(mask)] = inf; //not garden of eden
  mask = 1 << (rows * cols);
  while (mask--)
    if (moi[mask] == 0)
      dfs(mask, 0);
end:
  printf("%d\n", moi[init] == inf ? -1 : moi[init]);
}

void solve() {
  rows = cols = -1;
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
  ORIGLIFE::solve();
  return 0;
}

