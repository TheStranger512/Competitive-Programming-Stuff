/* Solved
 * 263. Period
 * File:   PERIOD.cpp
 * Author: Andy Y.F. Huang
 * Created on January 4, 2013, 6:35 PM
 */

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace PERIOD {
char str[1 << 20];
int fail[1 << 20];

void solve(int test_num) {
  int len;
  scanf("%d %s", &len, str);
  printf("Test case #%d\n", test_num);
  fail[0] = -1;
  fail[1] = 0;
  for (int i = 1, j = 0; i < len; ) {
    while (j >= 0 && str[j] != str[i])
      j = fail[j];
    fail[++i] = ++j;
    if (fail[i] > 0 && i % (i - fail[i]) == 0)
      printf("%d %d\n", i, i / (i - fail[i]));
  }
  putchar('\n');
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
  PERIOD::solve();
  return 0;
}

