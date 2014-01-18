/*
 * TCO 2013 Marathon Round 2
 * File:   FragileMirrors.cpp
 * Author: Andy Y.F. Huang
 * Created on May 1, 2013, 4:07 PM
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

//{RIGHT, UP, LEFT, DOWN}
//odd is up-down, even is left-right
const int DR[] = {0, -1, 0, 1};
const int DC[] = {1, 0, -1, 0};

struct FragileMirrors {
  #define MAX 111
  #define RIGHT 0
  #define UP 1
  #define LEFT 2
  #define DOWN 3
  typedef vector<int> VecInt;
  typedef vector<string> VecStr;
  char grid[MAX][MAX];
  bool gone[MAX][MAX];
  int size;

  int nextrand(int upto) {
    return rand() % upto;
  }

  int nextrand(int a, int b) {
    return rand() % (b - a + 1) + a;
  }

  double get_time() {
    return 1.0 * clock() / CLOCKS_PER_SEC;
  }

  bool oob(int r, int c) {
    return r < 0 || r >= size || c < 0 || c >= size;
  }

  int left(int dir) {
    return (dir + 1) & 3;
  }

  int right(int dir) {
    return (dir + 3) & 3;
  }

  int turn(int dir, char mir) {
    if (mir == 'L') {
      if (dir & 1) return right(dir);
      else return left(dir);
    }
    else { //R mirror
      if (dir & 1) return left(dir);
      else return right(dir);
    }
  }

  /**
   * returns number of mirrors destroyed
   */
  int shoot(int srow, int scol, bool real) {
    static bool seen[MAX][MAX];
    memcpy(seen, gone, sizeof (seen));
    int r = srow, c = scol, dir, cnt = 0;
    if (r == -1) dir = DOWN;
    else if (r == size) dir = UP;
    else if (c == -1) dir = RIGHT;
    else dir = LEFT;
    while (true) {
      r += DR[dir];
      c += DC[dir];
      if (oob(r, c)) break;
      if (!seen[r][c]) {
        seen[r][c] = true;
        cnt++;
        dir = turn(dir, grid[r][c]);
      }
    }
    if (real)
      for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
          gone[i][j] |= seen[i][j];
    return cnt;
  }

  VecInt go() {
    VecInt res;
    memset(gone, false, sizeof (gone));
    int cnt = 0, best = 0, sr, sc;
    while (cnt < size * size) {
      best = 0;
      for (int i = 0; i < size; i++) {
        int temp = shoot(i, -1, false);
        if (temp > best)
          best = temp, sr = i, sc = -1;
        temp = shoot(i, size, false);
        if (temp > best)
          best = temp, sr = i, sc = size;
        temp = shoot(-1, i, false);
        if (temp > best)
          best = temp, sr = -1, sc = i;
        temp = shoot(size, i, false);
        if (temp > best)
          best = temp, sr = size, sc = i;
      }
      cnt += shoot(sr, sc, true);
      res.push_back(sr);
      res.push_back(sc);
    }
    return res;
  }

  VecInt destroy(VecStr board) {
    srand(time(NULL));
    size = board.size();
    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++)
        grid[i][j] = board[i][j];
    //double timest = get_time();
    VecInt res = go();
    return res;
  }
} ;
