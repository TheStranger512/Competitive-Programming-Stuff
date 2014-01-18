/* Solved
 * 2526. Decoding - string manip
 * File:   GNY07D.cpp
 * Author: Andy Huang
 * Created on June 9, 2012, 2:50 PM
 */

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <fstream>
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#define pln(x) println(x)
#define pf(x) print(x)
#define plnarr(i, j) println(i, j)
#endif

using namespace std;

#define max_size 25
#define max_len 500

const char dx[] = {0, 1, 0, -1};
const char dy[] = {1, 0, -1, 0};
const char turnright[] = {3, 0, 1, 2};

bool used[max_size][max_size];
int grid[max_size][max_size];

void solve() {
  memset(used, true, sizeof (used));
  int rows, cols;
  char str[max_len];
  scanf("%d %d ", &rows, &cols);
  gets(str);
  int index = 0;
  int len = rows * cols / 5;
  for (int y = 1; y <= rows; y++) {
    for (int x = 1; x <= cols; x++) {
      grid[x][y] = str[index++] - '0';
      used[x][y] = false;
    }
  }
  int dir = 1, x = 0, y = 1;
  while (len--) {
    int val = 0;
    for (int d = 4; d >= 0; d--) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (used[nx][ny]) {
        dir = turnright[dir];
        nx = x + dx[dir];
        ny = y + dy[dir];
      }
      val += grid[nx][ny] << d;
      used[nx][ny] = true;
      x = nx;
      y = ny;
    }
    if (val == 0)
      putchar(' ');
    else
      putchar(val + 'A' - 1);
  }
  puts("");
}

int main() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++) {
    printf("%d ", i);
    solve();
  }
  return 0;
}

