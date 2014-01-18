/* Solved
 * 10293. FANCY NUMBERS
 * File:   FANCY.cpp
 * Author: Andy Y.F. Huang
 * Created on August 16, 2012, 11:21 AM
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
namespace FANCY {
char str[50];

void solve(int test_num) {
  gets(str);
  int len = strlen(str), i = 0;
  long long ans = 1;
  while (i < len) {
    char cur = str[i];
    int j = i;
    while (j < len && str[j] == cur)
      j++;
    ans *= (1LL << (j - i - 1));
    i = j;
  }
  printf("%lld\n", ans);
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
  FANCY::solve();
  return 0;
}

