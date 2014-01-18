/* Solved
 * 1029. Matrix Summation - 2D BIT
 * File:   MATSUM.cpp
 * Author: Andy Y.F. Huang
 * Created on July 30, 2012, 6:45 PM
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

namespace Int_Input {
#define in Int_Input
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

inline void next_str(char* str) {
  char c;
  do {
    c = next_char();
  } while (c <= ' ');
  do {
    *str++ = c;
    c = next_char();
  } while (c > ' ');
  *str = '\0';
}

inline int next_int() {
  char c;
  do {
    c = next_char();
  } while (c < '-');
  bool neg;
  if (c == '-') {
    neg = true;
    c = next_char();
  }
  else
    neg = false;
  int ans = 0;
  while (c >= '0') {
    ans = (ans << 1) + (ans << 3);
    ans += char_to_int[c];
    c = next_char();
  }
  return neg ? -ans : ans;
}

}

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace MATSUM {
const int k_max_size = 1030;
int len, tree[k_max_size][k_max_size], aux[k_max_size][k_max_size];

void update(int x, int y, int val) {
  while (x < len) {
    int idy = y;
    while (idy < len) {
      tree[x][idy] += val;
      idy |= (idy + 1);
    }
    x |= (x + 1);
  }
}

int query(int x, int y) {
  int ans = 0;
  while (x >= 0) {
    for (int idy = y; idy >= 0; idy = (idy & (idy + 1)) - 1)
      ans += tree[x][idy];
    x = (x & (x + 1)) - 1;
  }
  return ans;
}

void solve(int test_num) {
  memset(tree, 0, sizeof (tree));
  memset(aux, 0, sizeof (aux));
  len = in::next_int();
  while (true) {
    char str[20];
    in::next_str(str);
    if (str[1] == 'N')
      break;
    else if (str[1] == 'E') {
      int x = in::next_int();
      int y = in::next_int();
      int val = in::next_int();
      update(x, y, val - aux[x][y]);
      aux[x][y] = val;
    }
    else {
      int x1 = in::next_int();
      int y1 = in::next_int();
      int x2 = in::next_int();
      int y2 = in::next_int();
      printf("%d\n", query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, y1 - 1));
    }
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests = in::next_int();
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  MATSUM::solve();
  return 0;
}

