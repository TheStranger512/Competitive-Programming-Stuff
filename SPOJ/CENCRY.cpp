/* Solved
 * 7696. Encryption
 * File:   CENCRY.cpp
 * Author: Andy Y.F. Huang
 * Created on August 27, 2012, 11:23 PM
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
namespace CENCRY {
char str[50050];
const char* vowels = "aeiou";
const char* consts = "bcdfghjklmnpqrstvwxyz";
int loc[30];

bool isvowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void init() {
  for (int i = 0; i < 5; i++)
    loc[vowels[i] - 'a'] = i;
  for (int i = 0; i < 21; i++)
    loc[consts[i] - 'a'] = i;
}

void solve(int test_num) {
  int cnt[26] = {0}, len;
  scanf("%s", str);
  len = strlen(str);
  for (int i = 0; i < len; i++) {
    char c = str[i] - 'a';
    int k = cnt[c]++;
    if (isvowel(str[i]))
      putchar(consts[(k * 5 + loc[c]) % 21]);
    else
      putchar(vowels[(k * 21 + loc[c]) % 5]);
  }
  putchar('\n');
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  init();
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  CENCRY::solve();
  return 0;
}

