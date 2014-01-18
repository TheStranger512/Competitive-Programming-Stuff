/* Solved
 * 3544. Binary Search Tree - using tree set
 * File:   BST.cpp
 * Author: Andy Y.F. Huang
 * Created on June 17, 2012, 6:43 PM
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

namespace Int_Output {
const char digit_to_char[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
const unsigned int buffer_size = 1 << 16;
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
  if (num >= 10)
    write_int(num / 10);
  write_char(digit_to_char[num % 10]);
}

}

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
struct BST {

  void solve() {
    #ifdef AZN
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int tests = 1;
    for (int i = 1; i <= tests; i++)
      solve(i);
  }

  void solve(const int test_num) {
    long long ans = 0;
    int len = Int_Input::next_int();
    set<int> depths;
    set<int>::const_iterator iter;
    while (len--) {
      int num = Int_Input::next_int(), curdepth = 0;
      iter = depths.lower_bound(num);
      if (iter != depths.end()) {
        curdepth = max(curdepth, arr[*iter] + 1);
      }
      if (iter != depths.begin()) {
        iter--;
        curdepth = max(curdepth, arr[*iter] + 1);
      }
      arr[num] = curdepth;
      ans += curdepth;
      depths.insert(num);
      Int_Output::write_int(ans);
      Int_Output::write_char('\n');
    }
    Int_Output::write_flush();
  }
private:
  #define max_len 300010
  int arr[max_len];
} ;

int main() {
  BST solver;
  solver.solve();
  return 0;
}

