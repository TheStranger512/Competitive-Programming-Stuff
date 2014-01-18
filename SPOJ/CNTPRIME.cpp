/* Solved
 * 13015. Counting Primes
 * File:   CNTPRIME.cpp
 * Author: Andy Y.F. Huang
 * Created on February 15, 2013, 6:38 PM
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

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace CNTPRIME {
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

inline char* next_str(char* str) {
  char c = 0;
  while (c <= ' ') c = next_char();
  do {
    *str++ = c;
    c = next_char();
  } while (c > ' ');
  *str = '\0';
  return str;
}

inline int next_int() {
  char c = 0;
  int ans = 0;
  while (c < '0') c = next_char();
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

#define MAX 1000010
#define lch(x) (x << 1)
#define rch(x) ((x << 1) + 1)
#define mid ((start + end) >> 1)

int tree[111111];
int lazy[111111];
int aux[111111];
bool prime[1 << 20];
int from, to, val;
const char* CASE = "Case ";

void prog(int node, int start, int end) {
  if (lazy[node] == -1) return;
  lazy[lch(node)] = lazy[rch(node)] = lazy[node];
  tree[lch(node)] = lazy[node] * (mid - start + 1);
  tree[rch(node)] = lazy[node] * (end - mid);
  lazy[node] = -1;
}

void build(int node, int start, int end) {
  if (start == end) {
    tree[node] = prime[aux[start]];
    lazy[node] = -1;
    return;
  }
  build(lch(node), start, mid);
  build(rch(node), mid + 1, end);
  lazy[node] = -1;
  tree[node] = tree[lch(node)] + tree[rch(node)];
}

int query(int node, int start, int end) {
  if (from > end || to < start) return 0;
  if (from <= start && end <= to) return tree[node];
  prog(node, start, end);
  return query(lch(node), start, mid) + query(rch(node), mid + 1, end);
}

void update(int node, int start, int end) {
  if (from > end || to < start) return;
  if (from <= start && end <= to) {
    tree[node] = val * (end - start + 1);
    lazy[node] = val;
    return;
  }
  prog(node, start, end);
  update(lch(node), start, mid);
  update(rch(node), mid + 1, end);
  tree[node] = tree[lch(node)] + tree[rch(node)];
}

void solve(int test_num) {
  int len, quests;
  len = next_int();
  quests = next_int();
  for (int i = 0; i < len; i++)
    aux[i] = next_int();
  build(1, 0, len - 1);
  for (int i = 0; i < 5; i++)
    write_char(CASE[i]);
  write_int(test_num);
  write_char(':');
  write_char('\n');
  for (int q = 0; q < quests; q++) {
    int type = next_int();
    from = next_int() - 1;
    to = next_int() - 1;
    if (type == 0) {
      val = prime[next_int()];
      update(1, 0, len - 1);
    }
    else {
      write_int(query(1, 0, len - 1));
      write_char('\n');
    }
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  memset(prime, true, sizeof (prime));
  prime[0] = prime[1] = false;
  for (int i = 2; i * i <= MAX; i++)
    if (prime[i])
      for (int j = i * i; j <= MAX; j += i)
        prime[j] = false;
  int tests = next_int();
  for (int i = 1; i <= tests; i++)
    solve(i);
  write_flush();
}
}

int main() {
  CNTPRIME::solve();
  return 0;
}

