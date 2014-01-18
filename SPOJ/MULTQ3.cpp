/* Solved
 * 7299. Multiples of 3
 * File:   MULTQ3.cpp
 * Author: Andy Y.F. Huang
 * Created on December 7, 2012, 5:54 PM
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
namespace MULTQ3 {
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


int tree[3][1 << 18];
int lazy[1 << 18];
int from, to, temp;

void inc(int node) {
  temp = tree[0][node];
  tree[0][node] = tree[2][node];
  tree[2][node] = tree[1][node];
  tree[1][node] = temp;
}

void prog(int node) {
  if (!lazy[node]) return;
  int l = node << 1, r = l + 1;
  lazy[l] += lazy[node];
  if (lazy[l] >= 3) lazy[l] -= 3;
  lazy[r] += lazy[node];
  if (lazy[r] >= 3) lazy[r] -= 3;
  inc(l), inc(r);
  if (lazy[node] == 2) inc(l), inc(r);
  lazy[node] = 0;
}

int query(int node, int start, int end) {
  if (from > end || to < start) return 0;
  if (from <= start && end <= to) return tree[0][node];
  prog(node);
  int mid = (start + end) >> 1;
  return query(node << 1, start, mid) + query(node + node + 1, mid + 1, end);
}

void update(int node, int start, int end) {
  if (from > end || to < start) return;
  if (from <= start && end <= to) {
    lazy[node]++;
    if (lazy[node] == 3) lazy[node] = 0;
    inc(node);
    return;
  }
  prog(node);
  int mid = (start + end) >> 1;
  update(node << 1, start, mid);
  update(node + node + 1, mid + 1, end);
  for (int i = 0; i < 3; i++)
    tree[i][node] = tree[i][node << 1] + tree[i][node + node + 1];
}

void init(int node, int start, int end) {
  if (start == end) tree[0][node] = 1;
  else {
    int mid = (start + end) >> 1;
    init(node << 1, start, mid);
    init(node + node + 1, mid + 1, end);
    tree[0][node] = end - start + 1;
  }
}

void solve(int test_num) {
  int len = next_int(), quests = next_int();
  //scanf("%d %d", &len, &quests);
  init(1, 0, len - 1);
  for (int q = 0; q < quests; q++) {
    int type = next_int();
    from = next_int(), to = next_int();
    //scanf("%d %d %d", &type, &from, &to);
    if (type == 0)
      update(1, 0, len - 1);
    else
      //printf("%d\n", query(1, 0, len - 1));
      write_int(query(1, 0, len - 1)), write_char('\n');
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve(1);
  write_flush();
}
}

int main() {
  MULTQ3::solve();
  return 0;
}

