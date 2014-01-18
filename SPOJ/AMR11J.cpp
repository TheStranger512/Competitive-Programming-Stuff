/* Solved
 * 10237. Goblin Wars
 * File:   AMR11J.cpp
 * Author: Andy Y.F. Huang
 * Created on December 28, 2012, 1:25 PM
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
namespace AMR11J {
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
char grid[555][555];

void solve(int test_num) {
  memset(grid, '#', sizeof (grid));
  int rows, cols;
  scanf("%d %d", &rows, &cols);
  for (int r = 1; r <= rows; r++) {
    scanf("%s", grid[r] + 1);
    grid[r][cols + 1] = '#';
  }
  queue<pair<int, int> > old, conq;
  for (int r = 1; r <= rows; r++)
    for (int c = 1; c <= cols; c++)
      if (isalpha(grid[r][c]))
        old.push(make_pair(r, c));
  while (!old.empty()) {
    while (!old.empty()) {
      int r = old.front().first, c = old.front().second;
      old.pop();
      if (grid[r][c] == '*') continue;
      for (int d = 0; d < 4; d++) {
        int nr = r + dy[d], nc = c + dx[d];
        if (grid[nr][nc] == '#')
          continue;
        if (grid[nr][nc] == '.') {
          grid[nr][nc] = grid[r][c] - 'a';
          conq.push(make_pair(nr, nc));
        }
        else if (grid[nr][nc] < 26 && grid[nr][nc] != grid[r][c] - 'a')
          grid[nr][nc] = '*';
      }
    }
    while (!conq.empty()) {
      old.push(conq.front());
      if (grid[conq.front().first][conq.front().second] != '*')
        grid[conq.front().first][conq.front().second] += 'a';
      conq.pop();
    }
  }
  for (int r = 1; r <= rows; r++) {
    grid[r][cols + 1] = 0;
    puts(grid[r] + 1);
  }
  putchar('\n');
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
  AMR11J::solve();
  return 0;
}

