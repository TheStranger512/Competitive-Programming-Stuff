/* Solved
 * August Challenge 2013
 * Sereja and Ballons
 * File:   SEABAL.cpp
 * Author: Andy Y.F. Huang
 * Created on Aug 4, 2013, 4:13:12 PM
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

namespace SEABAL {
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
  bool neg;
  if (c == '-')
    neg = true, c = next_char();
  else
    neg = false;
  for (; c >= '0'; c = next_char())
    ans = (ans << 1) + (ans << 3) + c - '0';
  return neg ? -ans : ans;
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

inline void println(int num) {
  write_int(num);
  write_char('\n');
}

#define MAX 100111
int N, M, Q, ans = 0, PW;
int box[MAX], lef[MAX], rig[MAX];
int zl[MAX], zr[MAX]; //furthest left/right zero box
vector<int> tree[1 << 18];
bool del[MAX];
int qleft;

bool cmp(int a, int b) {
  return lef[a] < lef[b];
}

void remove(vector<int>& v) {
  //remove all elements >= qleft
  while (!v.empty() && lef[v.back()] >= qleft) {
    if (!del[v.back()]) {
      ans++;
      del[v.back()] = true;
    }
    v.pop_back();
  }
}

void go(int qR) {
  for (int l = 1 + PW, r = qR + PW + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1)
      remove(tree[l++]);
    if (r & 1)
      remove(tree[--r]);
  }
}

int findleft(int x) {
  return zl[x] == x ? x : zl[x] = findleft(zl[x]);
}

int findright(int x) {
  return zr[x] == x ? x : zr[x] = findright(zr[x]);
}

void solve(int test_num) {
  N = next_int();
  M = next_int();
  for (int i = 1; i <= N; i++)
    box[i] = next_int();
  for (int j = 0; j < M; j++) {
    lef[j] = next_int();
    rig[j] = next_int();
  }
  box[0] = box[N + 1] = MAX;
  for (int i = 0; i <= N + 1; i++)
    zl[i] = zr[i] = -1;
  for (PW = 1; PW <= N;)
    PW <<= 1;
  for (int j = 0; j < M; j++)
    tree[rig[j] + PW].push_back(j);
  for (int i = 1; i <= N; i++)
    sort(tree[i + PW].begin(), tree[i + PW].end(), cmp);
  for (int i = PW - 1, l, r; i; i--) {
    l = i + i, r = l + 1;
    tree[i].resize(tree[l].size() + tree[r].size());
    merge(tree[l].begin(), tree[l].end(), tree[r].begin(), tree[r].end(), tree[i].begin(), cmp);
  }
  memset(del, false, sizeof(del));
  Q = next_int();
  for (int q = 0, y, r; q < Q; q++) {
    y = next_int() + ans;
    if (--box[y] == 0) {
      zl[y] = box[y - 1] == 0 ? y - 1 : y;
      zr[y] = box[y + 1] == 0 ? y + 1 : y;
      if (box[y - 1] == 0)
        zr[y - 1] = y;
      if (box[y + 1] == 0)
        zl[y + 1] = y;
      qleft = findleft(y);
      r = findright(y);
      go(r);
    }
    println(ans);
  }
  write_flush();
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
  SEABAL::solve();
  return 0;
}
