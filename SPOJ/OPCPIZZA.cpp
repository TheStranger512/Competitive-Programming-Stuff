/* Solved
 * 12151. Pizzamania - binary search
 * File:   OPCPIZZA.cpp
 * Author: Andy Y.F. Huang
 * Created on August 31, 2012, 4:41 PM
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
namespace OPCPIZZA {
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
  while (c < '-') c = next_char();
  bool neg;
  if (c == '-') neg = true, c = next_char();
  else neg = false;
  int ans = 0;
  while (c >= '0') {
    ans = (ans << 1) + (ans << 3);
    ans += char_to_int[c];
    c = next_char();
  }
  return neg ? -ans : ans;
}

int money[100100];

void solve(int test_num) {
  int friends, need, ans = 0;
  friends = next_int(), need = next_int();
  for (int i = 0; i < friends; i++)
    money[i] = next_int();
  sort(money, money + friends);
  for (int i = 0; i < friends; i++) {
    long long diff = (long long) (need) - money[i];
    if (diff != money[i] && diff >= money[0] && diff <= money[friends - 1]
            && binary_search(money, money + friends, int(need - money[i])))
      ans++;
  }
  ans >>= 1;
  printf("%d\n", ans);
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
  OPCPIZZA::solve();
  return 0;
}

