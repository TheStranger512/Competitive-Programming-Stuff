/* Solved
 * 9547. Counting d-pairs
 * File:   DPAIR.cpp
 * Author: Andy Y.F. Huang
 * Created on April 1, 2013, 4:19 PM
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

namespace DPAIR {
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

inline void write_int(long long num) {
  if (num > 9)
    write_int(num / 10);
  write_char(num % 10 + '0');
}

inline void println(long long num) {
  write_int(num);
  write_char('\n');
}

#define MAX 1000100
long long cnt[800100];
int last[MAX];

void solve(int test_num) {
  int len = next_int(), front = 1;
  for (int i = 1, val; i <= len; i++) {
    val = next_int();
    front = max(front, last[val] + 1);
    last[val] = i;
    cnt[1]++;
    cnt[i - front + 1 + 1]--;
  }
  for (int i = 1; i <= len; i++)
    cnt[i] += cnt[i - 1];
  for (int i = 1; i <= len; i++)
    cnt[i] += cnt[i - 1];
  int quests = next_int();
  for (int q = 0, low, high; q < quests; q++) {
    low = next_int();
    high = next_int();
    println(cnt[high] - cnt[low - 1]);
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  solve(1);
  write_flush();
}
}

int main() {
  DPAIR::solve();
  return 0;
}

