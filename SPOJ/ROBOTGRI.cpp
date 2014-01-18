/* Solved
 * 9652. Robots on a grid
 * File:   ROBOTGRI.cpp
 * Author: Andy Y.F. Huang
 * Created on August 28, 2012, 10:17 PM
 */

#include <cstdio>
#include <queue>
#include <cstring>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace ROBOTGRI {

struct Point {
  int x, y;

  Point(int x, int y) : x(x), y(y) { }
} ;

typedef unsigned int uint;
char grid[1100][1100];
uint dp[1100][1100];
bool poss[1100][1100];

inline char nextchar() {
  char c = 0;
  while (c <= ' ') c = getchar_unlocked();
  return c;
}

void solve(int test_num) {
  const uint mod = (1u << 31) - 1;
  const uint dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
  memset(grid, '#', sizeof (grid));
  memset(dp, 0, sizeof (dp));
  memset(poss, false, sizeof (poss));
  int size;
  scanf("%d", &size);
  dp[0][1] = 1;
  for (int y = 1; y <= size; y++) {
    for (int x = 1; x <= size; x++) {
      grid[x][y] = nextchar();
      if (grid[x][y] != '#')
        dp[x][y] = (dp[x - 1][y] + dp[x][y - 1]) % mod;
    }
  }
  if (dp[size][size] != 0)
    printf("%d\n", dp[size][size]);
  else {
    queue<Point>q;
    q.push(Point(1, 1));
    while (!q.empty()) {
      int x = q.front().x, y = q.front().y;
      q.pop();
      for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (grid[nx][ny] != '#' && !poss[nx][ny])
          poss[nx][ny] = true, q.push(Point(nx, ny));
      }
    }
    puts(poss[size][size] ? "THE GAME IS A LIE" : "INCONCEIVABLE");
  }
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
  ROBOTGRI::solve();
  return 0;
}

