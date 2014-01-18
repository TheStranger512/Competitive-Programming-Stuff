/* Solved
 * 13047. Saruman of Many Colours
 * File:   AMR12I.cpp
 * Author: Andy Y.F. Huang
 * Created on December 21, 2012, 11:55 PM
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

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace AMR12I {
char str[22222];

void solve(int test_num) {
  int len, width;
  scanf("%d %d %s", &len, &width, str);
  int ans = 0, high = 0;
  for (int i = 0; i < len; ) {
    int j = i, cnt = 0;
    while (j < len && str[j] == str[i])
      j++, cnt++;
    high = max(high, cnt);
    ans += (cnt + width - 1) / width;
    i = j;
  }
  printf("%d\n", high < width ? -1 : ans);
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
  AMR12I::solve();
  return 0;
}

