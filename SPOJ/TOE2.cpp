/* Solved
 * 1162. Tic-Tac-Toe ( II ) - DFS
 * File:   TOE2.cpp
 * Author: Andy Y.F. Huang
 * Created on September 9, 2012, 11:23 PM
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
namespace TOE2 {
bool good[1 << 20] = {false}, end[1 << 20] = {false};
char grid[5][5], prev[5][5];

int encode() {
  int ans = 0;
  for (int y = 0; y < 3; y++) {
    for (int x = 0; x < 3; x++) {
      ans <<= 2;
      if (grid[x][y] == 'O')
        ans += 1;
      else if (grid[x][y] == 'X')
        ans += 2;
    }
  }
  return ans;
}

void print() {
  for (int y = 0; y < 3; y++, putchar('\n'))
    for (int x = 0; x < 3; x++)
      putchar(grid[x][y]);
  putchar('\n');
}

bool endstate() {
  for (int y = 0; y < 3; y++)
    if (grid[0][y] != '.' && grid[0][y] == grid[1][y] && grid[1][y] == grid[2][y])
      return true;
  for (int x = 0; x < 3; x++)
    if (grid[x][0] != '.' && grid[x][0] == grid[x][1] && grid[x][1] == grid[x][2])
      return true;
  if (grid[0][0] != '.' && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])
    return true;
  if (grid[2][0] != '.' && grid[2][0] == grid[1][1] && grid[1][1] == grid[0][2])
    return true;
  return false;
}

void dfs(int state, int depth) {
  good[state] = true;
  //print();
  if (endstate()) {
    end[state] = true;
    return;
  }
  bool empty = false;
  for (int y = 0; y < 3; y++) {
    for (int x = 0; x < 3; x++) {
      if (grid[x][y] == '.') {
        empty = true;
        if (depth & 1) {
          grid[x][y] = 'O';
          int nstate = encode();
          if (!good[nstate])
            dfs(nstate, depth + 1);
        }
        else {
          grid[x][y] = 'X';
          int nstate = encode();
          if (!good[nstate])
            dfs(nstate, depth + 1);
        }
        grid[x][y] = '.';
      }
    }
  }
  if (!empty)
    end[state] = true;
}

void solve(int test_num, char* str) {
  for (int y = 0; y < 3; y++)
    for (int x = 0; x < 3; x++)
      grid[x][y] = str[y * 3 + x];
  //print();
  if (end[encode()])
    puts("valid");
  else
    puts("invalid");
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  memset(grid, '.', sizeof (grid));
  dfs(encode(), 0);
  while (true) {
    char str[15];
    scanf("%s", str);
    if (str[0] == 'e')
      break;
    solve(1, str);
  }
}
}

int main() {
  TOE2::solve();
  return 0;
}

