/* Solved
 * 9119. Indiana Jones and the lost Soccer Cup
 * Topological sorting
 * File:   GCPC11C.cpp
 * Author: Andy Y.F. Huang
 * Created on September 1, 2012, 12:31 AM
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
namespace GCPC11C {
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
  char c;
  while (c <= ' ') c = next_char();
  int ans = 0;
  while (c >= '0') {
    ans = (ans << 1) + (ans << 3);
    ans += char_to_int[c];
    c = next_char();
  }
  return ans;
}

const char digit_to_char[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char output_buffer[buffer_size];
unsigned int output_index = 0;

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

int last[10010], to[100010], next[100010];
int deg[10010], free[10010], order[10010];
bool moi[10010], searched[10010];
const char* k_cycle = "recheck hints", *k_multiple = "missing hints";

bool incycle(int cur) {
  moi[cur] = searched[cur] = true;
  for (int i = last[cur]; i != -1; i = next[i])
    if (moi[to[i]] || (!searched[to[i]] && incycle(to[i])))
      return true;
  moi[cur] = false;
  return false;
}

void solve(int test_num) {
  memset(moi, false, sizeof (moi));
  memset(searched, false, sizeof (searched));
  memset(deg, 0, sizeof (deg));
  memset(last, 0xFF, sizeof (last));
  int vertices = next_int(), edges = next_int();
  for (int i = 0; i < edges; i++) {
    int start = next_int(), end = next_int();
    --start, --end;
    deg[end]++;
    to[i] = end;
    next[i] = last[start];
    last[start] = i;
  }
  int top = 0, len = 0;
  for (int i = 0; i < vertices; i++) {
    if (!searched[i]) {
      if (incycle(i)) {
        for (int i = 0; i < 13; i++)
          write_char(k_cycle[i]);
        write_char('\n');
        return;
      }
    }
    if (deg[i] == 0)
      free[top++] = i;
  }
  while (len < vertices) {
    if (top > 1) {
      for (int i = 0; i < 13; i++)
        write_char(k_multiple[i]);
      write_char('\n');
      return;
    }
    order[len++] = free[top - 1];
    for (int i = last[free[--top]]; i != -1; i = next[i])
      if (--deg[to[i]] == 0)
        free[top++] = to[i];
  }
  for (int i = 0; i < len; i++)
    write_int(order[i] + 1), write_char(' ');
  write_char('\n');
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests = next_int();
  for (int i = 1; i <= tests; i++)
    solve(i);
  write_flush();
}
}

int main() {
  GCPC11C::solve();
  return 0;
}

