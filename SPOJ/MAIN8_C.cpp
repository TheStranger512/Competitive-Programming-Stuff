/* Solved
 * 8756. Shake Shake Shaky
 * File:   MAIN8_C.cpp
 * Author: Andy Y.F. Huang
 * Created on October 20, 2012, 2:27 PM
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
namespace MAIN8_C {
int candies[55555];

void solve(int test_num) {
  int boxes, ppl;
  scanf("%d %d", &boxes, &ppl);
  for (int i = 0; i < boxes; i++)
    scanf("%d", &candies[i]);
  int ans = 0;
  for (int low = 1, high = (int) 1e9; low <= high; ) {
    int mid = (low + high) >> 1;
    long long cnt = 0;
    for (int b = 0; b < boxes; b++)
      cnt += candies[b] / mid;
    if (cnt >= ppl) {
      low = mid + 1;
      ans = max(ans, mid);
    }
    else
      high = mid - 1;
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
  MAIN8_C::solve();
  return 0;
}

