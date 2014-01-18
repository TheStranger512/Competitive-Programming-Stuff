/* Solved
 * 4556. Think I will Buy Me a Football Team
 * File:   ANARC08G.cpp
 * Author: Andy Y.F. Huang
 * Created on August 15, 2012, 4:56 PM
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
  while (c < '0')
    c = next_char();
  int ans = 0;
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
namespace ANARC08G {
int debt[1010][1010], net[1010];

void solve(int test_num, int len) {
  memset(net, 0, sizeof (net));
  int ans = 0, sum = 0;
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      debt[i][j] = next_int();
      sum += debt[i][j];
      net[j] += debt[i][j];
      net[i] -= debt[i][j];
    }
  }
  for (int i = 0; i < len; i++)
    if (net[i] > 0)
      ans += net[i];
  printf("%d. %d %d\n", test_num, sum, ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (true) {
    static int i = 1;
    int len = next_int();
    if (len == 0)
      break;
    solve(i++, len);
  }
}
}

int main() {
  ANARC08G::solve();
  return 0;
}

