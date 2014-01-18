/* Solved
 * 5699. The last digit re-visited
 * File:   LASTDIG2.cpp
 * Author: Andy Y.F. Huang
 * Created on June 9, 2013, 11:01 PM
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
#include <limits>
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

namespace LASTDIG2 {
char base[1111];
int end[11];

void solve(int test_num) {
  long long expon;
  scanf("%s %lld", base, &expon);
  int slen = strlen(base), len = 0, cur = base[slen - 1] - '0', b = cur;
  if (slen == 1 && cur == 0) {
    puts("0");
    return;
  }
  if (expon == 0) {
    puts("1");
    return;
  }
  memset(end, -1, sizeof (end));
  while (!~end[cur]) {
    end[cur] = len++;
    cur = (int) (cur * b % 10);
  }
  expon = (expon - 1) % len;
  for (int i = 0; i < 10; i++)
    if (end[i] == expon)
      printf("%d\n", i);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  LASTDIG2::solve();
  return 0;
}

