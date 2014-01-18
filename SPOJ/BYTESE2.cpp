/* Solved
 * 3921. The Great Ball - interval coverage using brute force
 * File:   BYTESE2.cpp
 * Author: Andy Y.F. Huang
 * Created on June 17, 2012, 10:10 PM
 */

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <fstream>
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#define pln(x) println(x)
#define pf(x) print(x)
#define plnarr(i, j) println(i, j)
#endif

namespace Int_Input {
#define in Int_Input
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

int next_int() {
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
struct BYTESE2 {
  #define max_len 10000010

  void solve() {
    #ifdef AZN
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int tests;
    scanf("%d", &tests);
    for (int i = 1; i <= tests; i++)
      solve(i);
  }

  void solve(const int test_num) {
    int* cnt = new int[max_len];
    int events = in::next_int();
    int ans = 0;
    int maxtime = 0;
    while (events--) {
      int start = in::next_int();
      int end = in::next_int();
      cnt[start]++;
      cnt[end]--;
      if (end > maxtime)
        maxtime = end;
    }
    for (int i = 1; i <= maxtime; i++) {
      cnt[i] += cnt[i - 1];
      if (cnt[i] > ans)
        ans = cnt[i];
    }
    delete [] cnt;
    printf("%d\n", ans);
  }

private:

}  ;

int main() {
  BYTESE2 solver;
  solver.solve();
  return 0;
}

