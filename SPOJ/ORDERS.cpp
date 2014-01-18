/* Solve
 * 227. Ordering the Soldiers
 * File:   ORDERS.cpp
 * Author: Andy Y.F. Huang
 * Created on December 8, 2012, 6:37 PM
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
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <iomanip>
#include <cassert>
#include <ctime>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace ORDERS {
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
    ans += c - '0';
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

int tree[1 << 18];
int invs[1 << 18], ans[1 << 18];
int size, len;

void update(int pos, int val) {
  for (int i = pos; i <= len; i += i&-i)
    tree[i] += val;
}

int kthele(int val) {
  int pos = 0, total = 0;
  for (int add = size; add; add >>= 1) {
    if (pos + add <= len && total + tree[pos + add] < val) {
      pos += add;
      total += tree[pos];
    }
  }
  return pos + 1;
}

void solve(int test_num) {
  //memset(tree, 0, sizeof (tree));
  len = next_int();
  size = 1;
  while (size < len)
    size <<= 1;
  //scanf("%d", &len);
  for (int i = 1; i <= len; i++) {
    invs[i] = next_int();
    update(i, 1);
  }
  //scanf("%d", &invs[i]);
  for (int i = len; i > 0; i--) {
    ans[i] = kthele(i - invs[i]);
    update(ans[i], -1);
  }
  for (int i = 1; i <= len; i++)
    write_int(ans[i]), write_char(' ');
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
  ORDERS::solve();
  return 0;
}

