/* Solved
 * 8596. Wood, Axe and Grass - simulation
 * File:   WAGE.cpp
 * Author: Andy Huang
 * Created on June 3, 2012, 3:34 PM
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

#define max_size 500
#define null '?'
#define dirs 4

int rows, cols;
char grid[max_size][max_size];
char temp[max_size][max_size];
const char dx[] = {0, 1, 0, -1};
const char dy[] = {1, 0, -1, 0};

char winner(char a, char b) {
  if (a == 'W') {
    if (b == 'A')
      return a;
    else
      return b;
  }
  else if (a == 'A') {
    if (b == 'G')
      return a;
    else
      return b;
  }
  else {
    if (b == 'W')
      return a;
    else
      return b;
  }
}

void battle() {
  for (int y = 1; y <= rows; y++) {
    for (int x = 1; x <= cols; x++) {
      char a = grid[x][y];
      for (int dir = 0; dir < dirs; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        char b = grid[nx][ny];
        if (b == null || a == b)
          continue;
        if (a == winner(a, b))
          temp[nx][ny] = a;
        else
          temp[x][y] = b;
      }
    }
  }
  for (int y = 1; y <= rows; y++)
    for (int x = 1; x <= cols; x++)
      if (temp[x][y] != null)
        grid[x][y] = temp[x][y];
}

void solve() {
  memset(grid, null, sizeof (grid));
  int turns;
  scanf("%d %d %d", &rows, &cols, &turns);
  for (int i = 1; i <= rows; i++) {
    char str[max_size];
    scanf("%s", str);
    for (int j = 1; j <= cols; j++)
      grid[j][i] = str[j - 1];
  }
  while (turns--) {
    memset(temp, null, sizeof (temp));
    battle();
  }
  for (int y = 1; y <= rows; y++) {
    for (int x = 1; x <= cols; x++)
      printf("%c", grid[x][y]);
    puts("");
  }
}

int main() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d", &tests);
  while (tests--)
    solve();
  return 0;
}

