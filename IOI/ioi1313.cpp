/* Solved
 * IOI '13 - Brisbane, Australia
 * Wombats
 * File:   ioi1313.cpp
 * Author: Andy Y.F. Huang
 * Created on July 18, 2013, 6:53 AM
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

namespace ioi1313 {
const unsigned int buffer_size = 1 << 16;
char input_buffer[buffer_size];
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

#define INF 0x3F3F3F3F
#define MAXC 200
#define BSIZE 20
int h[5128][MAXC], v[5128][MAXC];
int tree[512][MAXC][MAXC];
int N, OFFSET;
int R, C;

void rec(int c1, int c2, int k1, int k2, int a[MAXC], int b[MAXC][MAXC], int res[MAXC]) {
  if (c1 > c2) return;
  int best = k1;
  int cmid = (c1 + c2) >> 1;
  res[cmid] = a[best] + b[best][cmid];
  for (int k = k1 + 1, temp; k <= k2; k++) {
    temp = a[k] + b[k][cmid];
    if (temp < res[cmid]) {
      res[cmid] = temp;
      best = k;
    }
  }
  rec(c1, cmid - 1, k1, best, a, b, res);
  rec(cmid + 1, c2, best, k2, a, b, res);
}

void merge(int a[MAXC][MAXC], int b[MAXC][MAXC], int res[MAXC][MAXC]) {
  //O(C^2 logC)
  for (int st = 0; st < C; st++)
    rec(0, C - 1, 0, C - 1, a[st], b, res[st]);
}

void make_block(int f[MAXC][MAXC], int r1) {
  //O(R * BSIZE * C * C)
  for (int st = 0; st < C; st++) {
    f[st][st] = 0;
    for (int c = st - 1; c >= 0; c--)
      f[st][c] = f[st][c + 1] + h[r1][c];
    for (int c = st + 1; c < C; c++)
      f[st][c] = f[st][c - 1] + h[r1][c - 1];
    for (int c = 0; c < C; c++)
      f[st][c] += v[r1][c];
  }
  for (int r = r1 + 1; r < r1 + BSIZE; r++) {
    for (int st = 0; st < C; st++) {
      for (int c = 1; c < C; c++)
        f[st][c] = min(f[st][c], f[st][c - 1] + h[r][c - 1]);
      for (int c = C - 2; c >= 0; c--)
        f[st][c] = min(f[st][c], f[st][c + 1] + h[r][c]);
      for (int c = 0; c < C; c++)
        f[st][c] += v[r][c];
    }
  }
}

void update(int pos) {
  make_block(tree[pos + OFFSET], pos * BSIZE);
  pos += OFFSET;
  //O(log N * C ^ 2 log C);
  for (int i = pos >> 1; i > 0; i >>= 1)
    merge(tree[i + i], tree[i + i + 1], tree[i]);
}

void build() {
  for (int b = 0; b < N; b++)
    make_block(tree[b + OFFSET], b * BSIZE);
  //extend rows
  for (int i = N + OFFSET; i < OFFSET + OFFSET; i++)
    for (int st = 0; st < C; st++)
      for (int ed = 0; ed < C; ed++)
        if (st != ed)
          tree[i][st][ed] = INF;
  for (int i = OFFSET - 1; i > 0; i--)
    merge(tree[i + i], tree[i + i + 1], tree[i]);
}

void solve(int test_num) {
  #ifdef AZN
  double start_time = 1.0 * clock() / CLOCKS_PER_SEC;
  #endif
  scanf("%d %d", &R, &C);
  for (int r = 0; r < R; r++)
    for (int c = 0; c < C - 1; c++)
      h[r][c] = next_int();
  for (int r = 0; r < R - 1; r++)
    for (int c = 0; c < C; c++)
      v[r][c] = next_int();
  N = (R + BSIZE - 1) / BSIZE;
  while (R % BSIZE != 0) {
    for (int c = 0; c + 1 < C; c++)
      h[R][c] = INF;
    R++;
  }
  OFFSET = 1;
  while (OFFSET < N) OFFSET <<= 1;
  build();
  int Q;
  Q = next_int();
  for (int q = 0, type, r, c, val, st, ed; q < Q; q++) {
    type = next_int();
    if (type == 3) {
      st = next_int();
      ed = next_int();
      write_int(tree[1][st][ed]);
      write_char('\n');
    }
    else {
      r = next_int();
      c = next_int();
      val = next_int();
      if (type == 1)
        h[r][c] = val;
      else
        v[r][c] = val;
      update(r / BSIZE);
    }
  }
  write_flush();
  #ifdef AZN
  pln("Took:", 1.0 * clock() / CLOCKS_PER_SEC - start_time);
  #endif
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  solve(1);
}
}

int main() {
  ioi1313::solve();
  return 0;
}

