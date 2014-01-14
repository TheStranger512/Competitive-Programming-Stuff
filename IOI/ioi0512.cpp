/* Solved
 * IOI '05 - Nowy Sacz, Poland
 * Mean Sequence
 * File:   ioi0512.cpp
 * Author: Andy Y.F. Huang
 * Created on November 17, 2012, 5:44 PM
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
namespace ioi0512 {
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

void solve(int test_num) {
  int len = next_int();
  int low = -(1 << 30), high = -low, prev = 0;
  for (int i = 0; i < len; i++) {
    int val = next_int();
    if (i & 1)
      low = max(low, prev - val);
    else
      high = min(high, val - prev);
    prev = 2 * val - prev;
  }
  if (low > high) puts("0");
  else printf("%d\n", high - low + 1);
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
  ioi0512::solve();
  return 0;
}

