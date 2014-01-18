/* Solved
 * 2320. Manhattan - manhattan distance heuristic
 * see DWITE JAN 2012 prob # 5
 * File:   DISTANCE.cpp
 * Author: Andy Y.F. Huang
 * Created on September 2, 2012, 10:19 PM
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
namespace DISTANCE {
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
  char c = 0;
  int ans = 0;
  bool neg;
  while (c < '-') c = next_char();
  if (c == '-')
    neg = true, c = next_char();
  else
    neg = false;
  while (c >= '0') {
    ans = (ans << 1) + (ans << 3);
    ans += char_to_int[c];
    c = next_char();
  }
  return neg ? -ans : ans;
}

int low[1 << 7], high[1 << 7], coord[10];


void solve(int test_num) {
  memset(low, 0x7F, sizeof (low));
  for (int i = 1 << 6; i >= 0; i--)
    high[i] = -1234567890;
  int pts = next_int(), dimen = next_int(), ans = 0;
  for (int i = 0; i < pts; i++) {
    for (int d = 0; d < dimen; d++)
      coord[d] = next_int();
    for (int mask = (1 << dimen) - 1; mask >= 0; mask--) {
      int sum = 0;
      for (int bit = 0; bit < dimen; bit++) {
        if (1 << bit & mask)
          sum += coord[bit];
        else
          sum += -coord[bit];
      }
      low[mask] = min(low[mask], sum);
      high[mask] = max(high[mask], sum);
    }
  }
  for (int mask = (1 << dimen) - 1; mask >= 0; mask--)
    ans = max(ans, high[mask] - low[mask]);
  printf("%d\n", ans);
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
  DISTANCE::solve();
  return 0;
}

