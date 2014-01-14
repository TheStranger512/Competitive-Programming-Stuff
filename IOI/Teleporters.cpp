/* Solved
 * IOI 2008 Day 2 - Teleporters
 * File:   Teleporters.cpp
 * Author: Andy Y.F. Huang
 * Created on December 26, 2012, 5:59 PM
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
#include <functional>
#include <complex>
#include <numeric>
#include <cctype>
#include <cstddef>
#include <utility>
#include <valarray>
#include <cstdlib>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace Teleporters {
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

int start[1 << 20], end[1 << 20];
int match[1 << 21];
int cycles[1 << 20];
int vals[1 << 21];
bool vis[1 << 21];
int cnt[1 << 21] = {0};
int hash[1 << 21];

void countsort(int* arr, int len) {
  for (int i = 0; i < len; i++)
    cnt[arr[i]]++;
  int nlen = 0;
  for (int i = 0; i < (1 << 21); i++)
    for (; cnt[i] > 0; cnt[i]--)
      arr[nlen++] = i;
}

void solve(int test_num) {
  memset(match, 0xFF, sizeof (match));
  memset(vis, false, sizeof (vis));
  int len = next_int(), toadd = next_int();
  for (int i = 0; i < len; i++) {
    start[i] = next_int();
    end[i] = next_int();
    vals[i] = start[i];
    vals[i + len] = end[i];
  }
  countsort(vals, len + len);
  for (int i = 0; i < len + len; i++)
    hash[vals[i]] = i;
  for (int i = 0; i < len; i++) {
    start[i] = hash[start[i]];
    end[i] = hash[end[i]];
    match[start[i]] = end[i];
    match[end[i]] = start[i];
  }
  int ans = 0;
  //main path
  for (int cur = 0; cur < len + len; ) {
    vis[cur] = true;
    cur = match[cur] + 1;
    ans++;
  }
  int cyclelen = 0;
  for (int i = 0; i < len + len; i++) {
    int curlen = 0;
    for (int cur = i; !vis[cur]; curlen++) {
      vis[cur] = true;
      cur = match[cur] + 1;
    }
    if (curlen > 0)
      cycles[cyclelen++] = curlen;
  }
  countsort(cycles, cyclelen);
  for (int i = cyclelen - 1, j = 0; i >= 0 && j < toadd; i--, j++)
    ans += cycles[i] + 2;
  toadd -= cyclelen;
  if (toadd > 0) {
    ans += toadd / 2 * 4; //add tele on same interval and another to created cycle of len 1
    if (toadd & 1)
      ans++;
  }
  printf("%d\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve(1);
}
}

int main() {
  Teleporters::solve();
  return 0;
}

