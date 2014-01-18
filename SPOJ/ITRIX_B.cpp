/* Solved
 * 8665. Lucky Sequence Again - bit operations
 * File:   ITRIX_B.cpp
 * Author: Andy Huang
 * Created on June 10, 2012, 5:21 PM
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
  while (num - (1LL << (len << 1)) >= 0) {
    num -= 1LL << (len << 1);
    len++;
  }
  stringstream ss;
  for (int bit = len - 1; bit >= 0; bit--) {
    int rem = num % 4;
    num >>= 2;
    if (rem == 0)
      ss << '2';
    else if (rem == 1)
      ss << '3';
    else if (rem == 2)
      ss << '5';
    else
      ss <<'7';
  }
  string ans = ss.str();
  reverse(ans.begin(), ans.end());
  puts(ans.c_str());
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

