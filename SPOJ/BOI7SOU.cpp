/* Solved
 * 7739. Sound
 * File:   BOI7SOU.cpp
 * Author: Andy Y.F. Huang
 * Created on August 16, 2012, 8:24 PM
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

namespace Input {
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
  while (c <= ' ')
    c = next_char();
  while (c >= '0') {
    ans = (ans << 1) + (ans << 3);
    ans += char_to_int[c];
    c = next_char();
  }
  return ans;
}
}

using namespace std;
using namespace Input;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace BOI7SOU {
deque<int> low, high;
int nums[1000010];

void solve(int test_num) {
  low.clear(), high.clear();
  int len, sample, limit, cnt = 0;
  len = next_int(), sample = next_int(), limit = next_int();
  for (int i = 0; i < len; i++)
    nums[i] = next_int();
  for (int i = 0; i < len; i++) {
    if (!high.empty() && high.front() <= i - sample)
      high.pop_front();
    while (!high.empty() && nums[high.back()] <= nums[i])
      high.pop_back();
    high.push_back(i);
    if (!low.empty() && low.front() <= i - sample)
      low.pop_front();
    while (!low.empty() && nums[low.back()] >= nums[i])
      low.pop_back();
    low.push_back(i);
    if (i >= sample - 1 && nums[high.front()] - nums[low.front()] <= limit)
      printf("%d\n", i - sample + 2), cnt++;
  }
  if (cnt == 0)
    puts("NONE");
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
  BOI7SOU::solve();
  return 0;
}

