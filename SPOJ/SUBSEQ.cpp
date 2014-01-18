/* Solved
 * 2150. Counting Subsequences
 * File:   SUBSEQ.cpp
 * Author: Andy Y.F. Huang
 * Created on August 8, 2012, 3:57 PM
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
namespace SUBSEQ {
multiset<int> cnt;

void solve(int test_num) {
  cnt.clear();
  int len = Input::next_int(), cur, sum = 0, ans = 0;
  cnt.insert(0);
  for (int i = 0; i < len; i++) {
    cur = Input::next_int();
    sum += cur;
    ans += (cnt.count(sum - 47));
    cnt.insert(sum);
  }
  printf("%d\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests = Input::next_int();
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  SUBSEQ::solve();
  return 0;
}

