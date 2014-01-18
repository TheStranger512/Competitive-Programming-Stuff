/* Solved
 * 9032. Cube Free Numbers
 * File:   CUBEFR.cpp
 * Author: Andy Y.F. Huang
 * Created on September 21, 2012, 7:53 PM
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
namespace CUBEFR {
int ans[1000010];
bool good[1000100];

void init() {
  memset(good, true, sizeof (good));
  int pos = 1;
  for (int i = 2; i <= 100; i++) {
    int cube = i * i * i;
    for (int j = cube; j <= 1000000; j += cube)
      good[j] = false;
  }
  for (int i = 1; i <= 1000000; i++)
    if (good[i])
      ans[i] = pos++;
}

void solve(int test_num) {
  int n;
  scanf("%d", &n);
  if (!good[n])
    printf("Case %d: Not Cube Free\n", test_num);
  else
    printf("Case %d: %d\n", test_num, ans[n]);
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
  CUBEFR::solve();
  return 0;
}

