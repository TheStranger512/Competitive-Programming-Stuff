/* Solved
 * 11516. VALIDATE THE MAZE - dfs
 * File:   MAKEMAZE.cpp
 * Author: Andy Huang
 * Created on June 4, 2012, 6:20 PM
 */

#include <stdio.h>
#include <iostream>
#include <math.h>
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
#define pln(x) println(x)
#define pf(x) print(x)
#define plnarr(i, j) println(i, j)
#endif

using namespace std;

#define max_size 25
#define wall '#'
#define floor '.'
#define dirs 4

char grid[max_size][max_size];
const char dx[] = {0, 1, 0, -1};
const char dy[] = {1, 0, -1, 0};
bool moi[max_size][max_size];

bool dfs(int x, int y, const int& ex, const int& ey) {
  moi[x][y] = true;
  if (x == ex && y == ey)
    return true;
  for (int dir = 0; dir < dirs; dir++) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (!moi[nx][ny] && grid[nx][ny] == floor && dfs(nx, ny, ex, ey))
      return true;
  }
  return false;
}

bool solve() {
  memset(grid, wall, sizeof (grid));
  int rows, cols;
  scanf("%d %d", &rows, &cols);
  //printf("%d %d\n", rows, cols);
  int startx[2], starty[2];
  int index = 0;
  bool valid = true;
  for (int y = 1; y <= rows; y++) {
    char str[max_size];
    scanf("%s", str);
    for (int x = 1; x <= cols; x++) {
      grid[x][y] = str[x - 1];
      if (str[x - 1] != floor)
        continue;
      if (x == cols || x == 1 || y == rows || y == 1) {
        if (index == 2) {
          valid = false;
          break;
        }
        startx[index] = x;
        starty[index] = y;
        index++;
      }
    }
  }
  if (index != 2 || !valid)
    return false;
  memset(moi, false, sizeof (moi));
  return dfs(startx[0], starty[0], startx[1], starty[1]);
}

int main() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d", &tests);
  while (tests--)
    printf("%s\n", solve() ? "valid" : "invalid");
  return 0;
}

