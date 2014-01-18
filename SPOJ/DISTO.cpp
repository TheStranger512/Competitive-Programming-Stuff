/* Solved
 * 10346. Streets of distortion
 * File:   DISTO.cpp
 * Author: Andy Y.F. Huang
 * Created on August 2, 2012, 7:08 PM
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
namespace DISTO {

struct Node {
  int x, y;

  Node(int x, int y) : x(x), y(y) {
  }
} ;
const char dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
const char dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
const int k_max_size = 510;
int grid[k_max_size][k_max_size];
int temp[k_max_size][k_max_size];
int size, meteors;
queue<Node> q;

void bfs(int sx, int sy) {
  temp[sx][sy] = 5;
  q.push(Node(sx, sy));
  while (!q.empty()) {
    Node cur = q.front();
    q.pop();
    for (int d = 0; d < 8; d++) {
      int nx = cur.x + dx[d], ny = cur.y + dy[d];
      if (nx < 0 || nx >= size || ny < 0 || ny >= size)
        continue;
      if (temp[cur.x][cur.y] - 1 > temp[nx][ny]) {
        temp[nx][ny] = temp[cur.x][cur.y] - 1;
        q.push(Node(nx, ny));
      }
    }
  }
}

void solve(int test_num) {
  scanf("%d %d", &size, &meteors);
  for (int y = 0; y < size; y++) {
    for (int x = 0; x < size; x++) {
      char c = ' ';
      while (c <= ' ')
        c = getchar_unlocked();
      grid[x][y] = c;
      temp[x][y] = 1;
    }
  }
  for (int i = 0; i < meteors; i++) {
    int x, y;
    scanf("%d %d", &y, &x);
    bfs(--x, --y);
  }
  for (int y = 0; y < size; y++) {
    for (int x = 0; x < size; x++)
      printf("%c ", (grid[x][y] * temp[x][y]) % 93 + 33);
    putchar('\n');
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
  DISTO::solve();
  return 0;
}

