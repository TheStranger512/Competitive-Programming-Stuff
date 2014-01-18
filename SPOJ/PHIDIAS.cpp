/* Solved
 * 365. Phidias - dp
 * File:   PHIDIAS.cpp
 * Author: Andy Y.F. Huang
 * Created on September 18, 2012, 8:33 PM
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
namespace PHIDIAS {
const int k_maxsize = 601;
int dp[k_maxsize][k_maxsize];
//dp[w][h] = least wasted space of w x h rectangle
const unsigned int buffer_size = 1 << 16;
char input_buffer[buffer_size];
const unsigned int char_to_int[58] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                                      11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                                      21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
                                      31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
                                      41, 42, 43, 44, 45, 46, 47,
                                      0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
unsigned int bytes_read = 0;
unsigned int input_index = 0;

inline char next_char() {
  if (input_index == bytes_read) {
    bytes_read = fread(input_buffer, sizeof (char) , buffer_size, stdin);
    input_buffer[bytes_read] = '\0'; //sentinel
    input_index = 0;
  }
  return input_buffer[input_index++];
}

inline int next_int() {
  char c = 0;
  int ans = 0;
  while (c < '-') c = next_char();
  while (c >= '0') {
    ans = (ans << 1) + (ans << 3);
    ans += char_to_int[int(c)];
    c = next_char();
  }
  return ans;
}

inline int min(int a, int b) {
  return a < b ? a : b;
}

void solve(int test_num) {
  int width, height, diff;
  width = next_int();
  height = next_int();
  diff = next_int();
  for (int w = 0; w <= width; w++)
    for (int h = 0; h <= height; h++)
      dp[w][h] = w * h; //all space wasted
  for (int i = 0; i < diff; i++) {
    dp[next_int()][next_int()] = 0; //can use rectangle fully
  }
  for (int x = 1; x <= width; x++) {
    int limx = x >> 1;
    for (int y = 1; y <= height; y++) {
      int limy = y >> 1;
      for (int c = 1; c <= limx; c++)
        dp[x][y] = min(dp[x][y], dp[c][y] + dp[x - c][y]);
      for (int c = 1; c <= limy; c++)
        dp[x][y] = min(dp[x][y], dp[x][c] + dp[x][y - c]);
    }
  }
  printf("%d\n", dp[width][height]);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests = next_int();
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  PHIDIAS::solve();
  return 0;
}

