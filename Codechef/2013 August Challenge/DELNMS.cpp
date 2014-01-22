/*
 * August Challenge 2013
 * Deleting numbers
 * File:   DELNMS.cpp
 * Author: Andy Y.F. Huang
 * Created on Aug 4, 2013, 9:00:32 PM
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

using namespace std;

namespace DELNMS {

const unsigned int buffer_size = 1 << 16;
char input_buffer[buffer_size];
unsigned int bytes_read = 0;
unsigned int input_index = 0;

inline char next_char() {
  if (input_index == bytes_read) {
    bytes_read = fread(input_buffer, sizeof(char), buffer_size, stdin);
    input_buffer[bytes_read] = '\0'; //sentinel
    input_index = 0;
  }
  return input_buffer[input_index++];
}

inline int next_int() {
  char c = 0;
  int ans = 0;
  while (c < '-')
    c = next_char();
  for (; c >= '0'; c = next_char())
    ans = (ans << 1) + (ans << 3) + c - '0';
  return ans;
}

char output_buffer[buffer_size];
unsigned int output_index = 0;

inline void write_flush() {
  fwrite(output_buffer, sizeof(char), output_index, stdout);
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

template <class T, size_t MAXSIZE> struct Vector {
  T arr[MAXSIZE + 1], *last;

  Vector()
      : last(arr) {
  }

  int size() {
    return last - arr;
  }

  void push_back(const T & val) {
    *last++ = val;
  }

  T operator[](size_t pos) {
    return arr[pos];
  }

};

template <class T, size_t size> struct FenwickTree {
  T tree[size + 1];

  void init() {
    memset(tree, 0, sizeof(tree));
  }

  void update(int pos, T val) {
    for (size_t i = pos; i <= size; i += i & -i)
      tree[i] += val;
  }

  T query(int pos) const {
    T ans = 0;
    for (int i = pos; i > 0; i -= i & -i)
      ans += tree[i];
    return ans;
  }

};

#define MAX 100111
FenwickTree<int, MAX> bit;
int prev[MAX], last[MAX];
int arr[MAX];
bool del[MAX];
int N;
Vector<pair<int, int>, MAX> ans;

void solve(int test_num) {
  memset(last, -1, sizeof(last));
  N = next_int();
  for (int i = 1; i <= N; i++)
    arr[i] = next_int();
  for (int i = 1; i <= N; i++) {
    bit.update(i, 1);
    prev[i] = last[arr[i]];
    last[arr[i]] = i;
  }
  memset(del, false, sizeof(del));
  for (int i = N; i > 0; i--) {
    if (del[i])
      continue;
    if (prev[i] == -1) {
      del[i] = true;
      ans.push_back(make_pair(bit.query(i), 1));
    } else {
      int at = prev[i], rank = bit.query(at), temp = bit.query(i);
      int diff = temp - rank;
      bit.update(at, -1);
      del[i] = del[at] = true;
      while (prev[at] != -1 && rank - (temp = bit.query(prev[at])) == diff) {
        at = prev[at];
        rank = temp;
        bit.update(at, -1);
        del[at] = true;
      }
      ans.push_back(make_pair(rank, diff));
    }
    bit.update(i, -1);
  }
  write_int(ans.size());
  write_char('\n');
  for (int i = 0; i < ans.size(); i++) {
    write_int(ans[i].first);
    write_char(' ');
    write_int(ans[i].second);
    write_char('\n');
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
  DELNMS::solve();
  return 0;
}
