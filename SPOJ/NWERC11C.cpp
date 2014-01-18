/* Solved
 * 9889. Movie collection
 * do not assume constraints
 * File:   NWERC11C.cpp
 * Author: Andy Y.F. Huang
 * Created on December 7, 2012, 9:14 PM
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
 * Unsolved
 * @author Andy Y.F. Huang
 */
namespace NWERC11C {
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


int tree[1 << 18], loc[1 << 17];
int len, quests, lim, id, i, j, front, sum;

void solve(int test_num) {
  memset(tree, 0, sizeof (tree));
  len = next_int();
  quests = next_int();
  lim = len + quests;
  //scanf("%d %d", &len, &quests);
  front = quests;
  for (i = 1; i <= len; i++) {
    for (j = i + quests; j <= lim; j += j&-j)
      tree[j]++;
    loc[i] = i + quests;
  }
  //plnarr(tree, tree + lim);
  for (i = 0; i < quests; i++) {
    id = next_int();
    sum = 0;
    for (j = loc[id] - 1; j; j -= j&-j)
      sum += tree[j];
    for (j = loc[id]; j <= lim; j += j&-j)
      tree[j]--;
    for (j = front; j <= lim; j += j&-j)
      tree[j]++;
    loc[id] = front--;
    write_int(sum);
    write_char(' ');
  }
  //putchar('\n');
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
  NWERC11C::solve();
  return 0;
}

