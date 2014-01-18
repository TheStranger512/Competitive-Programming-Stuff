/*
 * Solved
 * 5465. Deliver pizza
 * File:   DP.cpp
 * Author: Andy Y.F. Huang
 * Created on April 25, 2013, 6:09 PM
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

namespace DP {
typedef pair<int, int> Node;
const int DR[] = {1, 0, -1, 0};
const int DC[] = {0, 1, 0, -1};
char grid[55][55];
int dist[55][55];
int vals[22];
queue<Node> q;

void solve(int test_num) {
  int rows, cols, sr = -1, sc = -1;
  scanf("%d %d", &rows, &cols);
  for (int r = 0; r < rows; r++) {
    scanf("%s", grid[r]);
    for (int c = 0; c < cols; c++)
      if (grid[r][c] == 'X')
        sr = r, sc = c;
  }
  memset(dist, 0x3F, sizeof (dist));
  q.push(Node(sr, sc));
  dist[sr][sc] = 0;
  grid[sr][sc] = '$';
  for (int r, c, cdist; !q.empty(); q.pop()) {
    r = q.front().first;
    c = q.front().second;
    cdist = dist[r][c];
    for (int d = 0, nr, nc, ndist; d < 4; d++) {
      nr = r + DR[d];
      nc = c + DC[d];
      ndist = cdist;
      if (r < 0 || r >= rows || c < 0 || c >= cols)
        continue;
      if (grid[r][c] == '$' || grid[nr][nc] == '$')
        ndist += 2;
      else if (abs(grid[r][c] - grid[nr][nc]) <= 1)
        ndist += grid[r][c] == grid[nr][nc] ? 1 : 3;
      else continue;
      if (ndist < dist[nr][nc]) {
        dist[nr][nc] = ndist;
        q.push(Node(nr, nc));
      }
    }
  }
  grid[sr][sc] = 'X';
  int len = 0;
  for (int r = 0; r < rows; r++)
    for (int c = 0; c < cols; c++)
      if (grid[r][c] == '$') {
        vals[len++] = 2 * dist[r][c];
        if (dist[r][c] >= (1 << 25)) {
          puts("-1");
          return;
        }
      }
  //plnarr(vals, vals + len);
  int best = 1 << 30, sum = accumulate(vals, vals + len, 0);
  for (int mask = (1 << len) - 1; mask >= 0; mask--) {
    int temp = 0, best1 = 0, best2 = 0;
    for (int bit = 0; bit < len; bit++) {
      if (1 << bit & mask) {
        temp += vals[bit];
        best1 = max(best1, vals[bit]);
      }
      else best2 = max(best2, vals[bit]);
    }
    best1 >>= 1;
    best2 >>= 1;
    best = min(best, max(temp - best1, sum - temp - best2));
  }
  printf("%d\n", best);
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
  DP::solve();
  return 0;
}

