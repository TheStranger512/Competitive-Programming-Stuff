/* Solved
 * 11460. Planning Poker
 * File:   VUDBOL7.cpp
 * Author: Andy Y.F. Huang
 * Created on January 6, 2013, 9:33 PM
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

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace VUDBOL7 {
const unsigned int buffer_size = 1 << 16;
char input_buffer[buffer_size];
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
  write_char(num % 10 + '0');
}

int len;
int ans[1 << 17], fib[37];

void solve(int test_num) {
  int val, pos;
  for (int i = 0; i < len; i++) {
    val = next_int();
    pos = upper_bound(fib, fib + 37, val) - fib;
    if (val - fib[pos - 1] < fib[pos] - val)
      ans[i] = fib[pos - 1];
    else
      ans[i] = fib[pos];
  }
  sort(ans, ans + len);
  for (int i = 0; i < len; i++) {
    write_int(ans[i]);
    write_char(' ');
  }
  write_char('\n');
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  fib[0] = 0;
  fib[1] = 1;
  fib[2] = 2;
  for (int i = 3; i < 37; i++)
    fib[i] = fib[i - 1] + fib[i - 2];
  while (true) {
    len = next_int();
    if (len == 0) break;
    solve(1);
  }
  write_flush();
}
}

int main() {
  VUDBOL7::solve();
  return 0;
}

