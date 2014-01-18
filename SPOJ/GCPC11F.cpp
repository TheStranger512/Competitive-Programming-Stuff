/* Solved
 * 9122. Diary - substitution cipher
 * File:   GCPC11F.cpp
 * Author: Andy Y.F. Huang
 * Created on August 31, 2012, 11:24 PM
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
namespace GCPC11F {
char str[1010];

void solve(int test_num) {
  gets(str);
  int cnt[26] = {0}, len = strlen(str);
  for (int i = 0; i < len; i++) {
    if (str[i] <= ' ')
      continue;
    cnt[str[i] - 'A']++;
  }
  int high = -1, highcnt = 0;
  for (int i = 0; i < 26; i++) {
    if (cnt[i] > high)
      high = cnt[i], highcnt = 1;
    else if (cnt[i] == high)
      highcnt++;
  }
  if (highcnt > 1) {
    puts("NOT POSSIBLE");
    return;
  }
  int dist;
  for (int i = 0; i < 26; i++)
    if (cnt[i] == high)
      dist = (i + 26 - 4) % 26; //E = 4
  printf("%d ", dist);
  for (int i = 0; i < len; i++)
    putchar(str[i] <= ' ' ? ' ' : (str[i] - 'A' + 26 - dist) % 26 + 'A');
  putchar('\n');
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
  GCPC11F::solve();
  return 0;
}

