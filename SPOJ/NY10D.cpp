/* Solved
 * 8626. Show Me The Fax - decoding
 * File:   NY10D.cpp
 * Author: Andy Y.F. Huang
 * Created on September 8, 2012, 8:30 PM
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
#include <fstream>
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace NY10D {
char ans[1000100], code[100100];

inline char nextchar() {
  char c = 0;
  while (c <= ' ')
    c = getchar_unlocked();
  return c;
}

int decode(char a, char b) {
  int ans = 0;
  if (a >= 'A')
    ans += a - 'A' + 10;
  else
    ans += a - '0';
  ans <<= 4;
  if (b >= 'A')
    ans += b - 'A' + 10;
  else
    ans += b - '0';
  return ans;
}

void solve(int test_num) {
  int bytes, len = 0;
  scanf("%d %d", &test_num, &bytes);
  bytes <<= 1;
  for (int i = 0; i < bytes; i++)
    code[i] = nextchar();
  for (int i = 0; i < bytes; ) {
    int val = decode(code[i], code[i + 1]);
    if (val >= 128) {
      val = (val - 128) + 3;
      char a = code[i + 2], b = code[i + 3];
      for (int j = 0; j < val; j++)
        ans[len++] = a, ans[len++] = b;
      i += 4;
    }
    else {
      val++;
      memcpy(ans + len, code + i + 2, val << 1);
      i += 2 + (val << 1);
      len += (val << 1);
    }
  }
  printf("%d %d", test_num, len >> 1);
  for (int i = 0; i < len; i++) {
    if (i % 80 == 0)
      putchar('\n');
    putchar(ans[i]);
  }
  putchar('\n');
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  NY10D::solve();
  return 0;
}

