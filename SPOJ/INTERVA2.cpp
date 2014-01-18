/*
 * Solved
 * 5298. Interval Challenge
 * File:   INTERVA2.cpp
 * Author: Andy Y.F. Huang
 * Created on March 29, 2013, 2:56 PM
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

namespace INTERVA2 {
const unsigned int buffer_size = 1 << 16;
char input_buffer[buffer_size];
unsigned int bytes_read = 0;
unsigned int input_index = 0;
bool eof = false;

inline char next_char() {
  if (input_index == bytes_read) {
    bytes_read = fread(input_buffer, sizeof (char) , buffer_size, stdin);
    input_buffer[bytes_read] = '\0'; //sentinel
    input_index = 0;
  }
  if (bytes_read == 0) eof = true;
  return input_buffer[input_index++];
}

inline int next_int() {
  char c = 0;
  int ans = 0;
  while (c < '-') c = next_char();
  bool neg;
  if (c == '-')
    neg = true, c = next_char();
  else
    neg = false;
  while (c >= '0') {
    ans = (ans << 1) + (ans << 3);
    ans += c - '0';
    c = next_char();
  }
  return neg ? -ans : ans;
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

inline void write_int(int num) {
  if (num >= 10)
    write_int(num / 10);
  write_char(num % 10 + '0');
}

inline void print(int num) {
  write_int(num);
  write_char(' ');
}

typedef pair<int, int> Interval;
int len;
Interval inters[200010];
int order[200010];
int tree[200100];
int vals[200100];
int ans[200100];

bool cmp(int a, int b) {
  return inters[a].first < inters[b].first ||
          (inters[a].first == inters[b].first && inters[a].second > inters[b].second);
}

void solve(int test_num) {
  int unilen = 0;
  for (int i = 0; i < len; i++) {
    inters[i].first = next_int();
    inters[i].second = next_int();
    vals[unilen++] = inters[i].second;
    order[i] = i;
  }
  sort(vals, vals + unilen);
  unilen = unique(vals, vals + unilen) - vals;
  memset(tree, 0, sizeof (int) * unilen + 16);
  sort(order, order + len, cmp);
  for (int i = 0; i < len; ) {
    int j = i;
    while (j < len && inters[order[i]] == inters[order[j]])
      j++;
    int temp = 0;
    int end = lower_bound(vals, vals + unilen, inters[order[i]].second) - vals + 1;
    for (int id = end - 1; id > 0; id -= id&-id)
      temp += tree[id];
    temp = i - temp;
    for (int k = i; k < j; k++)
      ans[order[k]] = temp;
    for (int id = end; id <= unilen; id += id&-id)
      tree[id] += j - i;
    i = j;
  }
  for (int i = 0; i < len; i++)
    print(ans[i]);
  write_char('\n');
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (true) {
    len = next_int();
    if (eof) break;
    solve(1);
  }
  write_flush();
}
}

int main() {
  INTERVA2::solve();
  return 0;
}

