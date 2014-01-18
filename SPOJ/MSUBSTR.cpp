/* Solved
 * 12262. Mirror Strings !!!
 * Longest Palindromic Substring see link below O(n)
 * http://www.leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
 * File:   MSUBSTR.cpp
 * Author: Andy Y.F. Huang
 * Created on September 21, 2012, 11:44 PM
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
namespace MSUBSTR {
char str[7000];
int p[7000];

void solve(int test_num) {
  int len = 1;
  str[0] = '@';
  while (true) {
    char c = getchar_unlocked();
    if (c <= ' ')
      break;
    str[len++] = '#';
    str[len++] = c;
  }
  str[len++] = '#';
  str[len++] = '$';
  str[len] = '\0';
  //O(n) solution
  int center = 0, right = 0, ans = 0, cntmax = 0;
  for (int i = 1; i < len - 1; i++) {
    int j = 2 * center - i;
    p[i] = i < right ? min(right - i, p[j]) : 0;
    while (str[i - p[i] - 1] == str[i + p[i] + 1])
      p[i]++;
    if (i + p[i] > right) {
      right = i + p[i];
      center = i;
    }
    if (p[i] > ans)
      ans = p[i], cntmax = 1;
    else if (p[i] == ans)
      cntmax++;
  }
  printf("%d %d\n", ans, cntmax);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d\r\n", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  MSUBSTR::solve();
  return 0;
}

