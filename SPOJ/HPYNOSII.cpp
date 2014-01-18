/* Solved
 * 7753. Happy Numbers II
 * File:   HPYNOSII.cpp
 * Author: Andy Y.F. Huang
 * Created on September 2, 2012, 11:36 PM
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
namespace HPYNOSII {
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
const char digit_to_char[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char output_buffer[buffer_size];
unsigned int output_index = 0;

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
    ans += char_to_int[c];
    c = next_char();
  }
  return ans;
}

inline void write_flush() {
  fwrite(output_buffer, sizeof (char) , output_index, stdout);
  output_index = 0;
}

inline void write_char(char c) {
  output_buffer[output_index++] = c;
  if (output_index == buffer_size)
    write_flush();
}

inline void write_int(int num) {
  if (num >= 10)
    write_int(num / 10);
  write_char(digit_to_char[num % 10]);
}

const int sqr[10] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
int dist[1024];
bool moi[1024];

int next(int num) {
  int ans = 0;
  while (num > 0)
    ans += sqr[num % 10], num /= 10;
  return ans;
}

void init() {
  dist[1] = 0;
  for (int i = 0; i < 1024; i++)
    dist[i] = -2;
  for (int i = 2; i < 1024; i++) {
    int cur = i, cnt = 0;
    memset(moi, false, sizeof (moi));
    bool cycle = true;
    while (!moi[cur]) {
      cnt++;
      moi[cur] = true;
      cur = next(cur);
      if (cur == 1)  {
        dist[i] = cnt;
        cycle = false;
        break;
      }
    }
    if (cycle)
      dist[i] = -1;
  }
}

void solve(int test_num) {
  int num = next_int();
  bool extra = false;
  if (num >= 1024)
    num = next(num), extra = true;
  if (dist[num] == -1) {
    write_char('-');
    write_char('1');
    write_char('\n');
  }
  else {
    write_int(dist[num] + extra);
    write_char('\n');
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  init();
  int tests = next_int();
  for (int i = 1; i <= tests; i++)
    solve(i);
  write_flush();
}
}

int main() {
  HPYNOSII::solve();
  return 0;
}

