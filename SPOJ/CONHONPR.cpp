/*
 * Solved
 * 13398. Contest Hall Preparation
 * File:   CONHONPR.cpp
 * Author: Andy Y.F. Huang
 * Created on January 19, 2013, 1:17 PM
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
namespace CONHONPR {
const int dy[] = {0, 0, 1, 1, 1, -1, -1, 1};
const int dx[] = {1, -1, 0, 1, -1, 0, 1, -1};
int grid[111][111];
bool bad[111];

void solve(int test_num) {
  int rows, cols;
  memset(grid, 0xFF, sizeof (grid));
  memset(bad, false, sizeof (bad));
  scanf("%d %d", &rows, &cols);
  for (int r = 1; r <= rows; r++)
    for (int c = 1; c <= cols; c++)
      scanf("%d", &grid[r][c]);
  for (int r = 1; r <= rows; r++) {
    for (int c = 1; c <= cols; c++) {
      if (grid[r][c] == -1 || bad[grid[r][c]]) continue;
      for (int d = 0; d < 8; d++)
        if (grid[r][c] == grid[r + dy[d]][c + dx[d]]) {
          bad[grid[r][c]] = true;
          break;
        }
    }
  }
  printf("%d\n", count(bad, bad + 111, true));
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
  CONHONPR::solve();
  return 0;
}

