/* Solved
 * 11354. Amusing numbers - bit operations
 * File:   TSHOW1.cpp
 * Author: Andy Huang
 * Created on June 10, 2012, 4:59 PM
 */

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <fstream>
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#define pln(x) println(x)
#define pf(x) print(x)
#define plnarr(i, j) println(i, j)
#endif

using namespace std;

void solve() {
  long long num;
  scanf("%lld", &num);
  int len = 0;
  while (num - (1LL << len) >= 0) {
    num -= 1LL << len;
    len++;
  }
  for (int bit = len - 1; bit >= 0; bit--)
    putchar(1 << bit & num ? '6' : '5');
  puts("");
}

int main() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d", &tests);
  while (tests--)
    solve();
  return 0;
}

