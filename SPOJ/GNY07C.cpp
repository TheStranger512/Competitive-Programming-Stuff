/* Solved
 * 2525. Encoding - string manip
 * File:   GNY07C.cpp
 * Author: Andy Huang
 * Created on June 9, 2012, 12:19 PM
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

int matrix[max_size][max_size];
bool used[max_size][max_size];
const char dx[] = {0, 1, 0, -1};
const char dy[] = {1, 0, -1, 0};
const char turnright[] = {3, 0, 1, 2};

void solve() {
  memset(matrix, 0, sizeof (matrix));
  memset(used, true, sizeof (used));
  int rows, cols;
  scanf("%d %d", &rows, &cols);
  string mess;
  getline(cin, mess);
  for (int y = 1; y <= rows; y++)
    for (int x = 1; x <= cols; x++)
      used[x][y] = false;
  int dir = 1, x = 0, y = 1;
  for (int i = 1; i < mess.length(); i++) {
    char ch = mess[i];
    int val = ch - 'A' + 1;
    if (ch == ' ')
      val = 0;
    if (val < 0)
      break;
    for (int d = 4; d >= 0; d--) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (used[nx][ny]) {
        dir = turnright[dir];
        nx = x + dx[dir];
        ny = y + dy[dir];
      }
      if (1 << d & val)
        matrix[nx][ny] = 1;
      used[nx][ny] = true;
      x = nx;
      y = ny;
    }
  }
  for (int y = 1; y <= rows; y++)
    for (int x = 1; x <= cols; x++)
      printf("%d", matrix[x][y]);
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

