/* Solved
 * 12101. Entrée - simple counting and sorting
 * File:   ACMPRAC2.cpp
 * Author: Andy Y.F. Huang
 * Created on August 30, 2012, 11:23 PM
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
namespace ACMPRAC2 {
char str[100010];
int mealsize[100010];

void solve(int test_num) {
  int lim, ans = 0, meals = 0;
  scanf("%d %s", &lim, str);
  int len = strlen(str);
  for (int i = 0; i < len; ) {
    char c = str[i];
    int cnt = 0;
    while (i < len && str[i] == c)
      i++, cnt++;
    mealsize[meals++] = cnt;
  }
  sort(mealsize, mealsize + meals);
  for (int i = meals - 1; i >= 0 && lim > 0; i--, lim--)
    ans += mealsize[i];
  printf("%d\n", ans);
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
  ACMPRAC2::solve();
  return 0;
}

