/* Solved
 * 8424. Life Game
 * File:   BTCODE_F.cpp
 * Author: Andy Y.F. Huang
 * Created on February 16, 2013, 1:22 PM
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
namespace BTCODE_F {

struct Node {
  int r, c, cnt;

  Node(int a, int b, int c) : r(a), c(b), cnt(c) { }
} ;
#define OFF 1250
bool dp[27][27][2500];
bool poss[2500];
int grid[27][27];
queue<Node> q;

void solve(int test_num) {
  int rows, cols, A, B;
  scanf("%d %d %d %d", &rows, &cols, &A, &B);
  memset(grid, 0, sizeof (grid));
  for (int r = 1; r <= rows; r++)
    for (int c = 1; c <= cols; c++)
      scanf("%d", &grid[r][c]);
  memset(poss, false, sizeof (poss));
  memset(dp, false, sizeof (dp));
  for (int c = 1; c <= cols; c++) {
    q.push(Node(1, c, grid[1][c] + OFF));
    dp[1][c][grid[1][c] + OFF] = true;
  }
  for (; !q.empty(); q.pop()) {
    int r = q.front().r, c = q.front().c, cnt = q.front().cnt;
    if (r == rows) {
      poss[cnt] = true;
      continue;
    }
    if (!dp[r + 1][c][cnt + grid[r + 1][c]]) {
      dp[r + 1][c][cnt + grid[r + 1][c]] = true;
      q.push(Node(r + 1, c, cnt + grid[r + 1][c]));
    }
    if (c > 1 && !dp[r + 1][c - 1][cnt + grid[r + 1][c - 1]]) {
      dp[r + 1][c - 1][cnt + grid[r + 1][c - 1]] = true;
      q.push(Node(r + 1, c - 1, cnt + grid[r + 1][c - 1]));
    }
    if (c < cols && !dp[r + 1][c + 1][cnt + grid[r + 1][c + 1]]) {
      dp[r + 1][c + 1][cnt + grid[r + 1][c + 1]] = true;
      q.push(Node(r + 1, c + 1, cnt + grid[r + 1][c + 1]));
    }
  }
  int low = 10000, high = -10000;
  for (int i = A; i <= B; i++) {
    if (poss[i + OFF]) {
      low = min(low, i);
      high = max(high, i);
    }
  }
  if (low > B) puts("NO NO");
  else printf("%d %d\n", low, high);
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
  BTCODE_F::solve();
  return 0;
}

