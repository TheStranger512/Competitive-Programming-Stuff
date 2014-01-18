/* Solved
 * 12092. Dessert - binary searching
 * File:   ACMPRAC4.cpp
 * Author: Andy Y.F. Huang
 * Created on August 31, 2012, 5:08 PM
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
namespace ACMPRAC4 {
int nuts[500];

void solve(int test_num) {
  int icecreams, judges, ans = 1000, mostnuts = 0;
  scanf("%d %d", &icecreams, &judges);
  for (int i = 0; i < icecreams; i++)
    scanf("%d", &nuts[i]), mostnuts = max(mostnuts, nuts[i]);
  for (int low = mostnuts, high = 1000; low <= high; ) {
    int mid = (low + high) >> 1, need = 1;
    for (int i = 0, cur = 0; i < icecreams; i++) {
      if (cur + nuts[i] <= mid)
        cur += nuts[i];
      else
        need++, cur = nuts[i];
    }
    if (need <= judges)
      high = mid - 1, ans = min(ans, mid);
    else
      low = mid + 1;
  }
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
  ACMPRAC4::solve();
  return 0;
}

