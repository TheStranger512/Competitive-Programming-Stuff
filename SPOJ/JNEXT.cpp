/* Solved
 * 12150. Just Next !!!
 * swap first two non-inversion pair and sort the rest after the first val
 * File:   JNEXT.cpp
 * Author: Andy Y.F. Huang
 * Created on August 31, 2012, 5:18 PM
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
namespace JNEXT {
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

inline char nextchar() {
  char c = 0;
  while (c <= ' ') c = next_char();
  return c;
}

inline int next_int() {
  char c = 0;
  while (c <= ' ') c = next_char();
  int ans = 0;
  while (c >= '0') {
    ans = (ans << 1) + (ans << 3);
    ans += char_to_int[c];
    c = next_char();
  }
  return ans;
}

char arr[1000010];

void solve(int test_num) {
  int pos[10];
  int len = next_int();
  memset(pos, 0xFF, sizeof (pos));
  for (int i = 0; i < len; i++)
    arr[i] = nextchar();
  for (int i = len - 1; i >= 0; i--) {
    for (int j = arr[i] - '0' + 1; j <= 9; j++) {
      if (pos[j] != -1) {
        swap(arr[i], arr[pos[j]]);
        sort(arr + i + 1, arr + len);
        for (int i = 0; i < len; i++)
          putchar(arr[i]);
        putchar('\n');
        return;
      }
    }
    pos[arr[i] - '0'] = i;
  }
  puts("-1");
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
  JNEXT::solve();
  return 0;
}

