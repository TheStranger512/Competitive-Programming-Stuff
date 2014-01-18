/* Solved
 * 11443. Davids Greed
 * File:   DAVIDG.cpp
 * Author: Andy Y.F. Huang
 * Created on October 28, 2012, 1:26 AM
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

namespace DAVIDG {
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
  bool neg;
  while (c < '-') c = next_char();
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

#define INF (1 << 30)
const int MOD = (int) (1e9 + 7);
int x[1111], y[1111], dist[1111];
int per, len;

inline int getdist(int a, int b) {
  return (int) ceil(per * hypot(x[a] - x[b], y[a] - y[b]));
}

void solve(int test_num) {
  int cnt = next_int();
  per = next_int();
  for (int i = 0; i < cnt; i++) {
    x[i] = next_int();
    y[i] = next_int();
  }
  int ans = 0;
  dist[0] = INF;
  for (int i = 1; i < cnt; i++)
    dist[i] = getdist(0, i);
  for (int its = 1; its < cnt; its++) {
    int best = 0;
    for (int i = 0; i < cnt; i++)
      if (dist[i] < dist[best])
        best = i;
    ans += dist[best];
    dist[best] = INF;
    for (int i = 0; i < cnt; i++)
      if (dist[i] < INF)
        dist[i] = min(dist[i], getdist(best, i));
  }
  printf("Scenario #%d: %d\n", test_num, ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  int tests = next_int();
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  DAVIDG::solve();
  return 0;
}

