/* Solved
 * 4103. Extend to Palindrome
 * File:   EPALIN.cpp
 * Author: Andy Y.F. Huang
 * Created on June 1, 2013, 3:07 PM
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

namespace EPALIN {
char str[111000];
char rev[111000];
int fail[111000];

void solve(int test_num) {
  int len = strlen(str);
  for (int i = 0; i < len; i++)
    rev[len - i - 1] = str[i];
  fail[0] = -1;
  for (int i = 0, j = -1; i < len; i++) {
    while (~j && rev[j] != rev[i])
      j = fail[j];
    fail[i + 1] = ++j;
  }
  //plnarr(fail, fail + len + 1);
  int j = 0;
  for (int i = 0; i < len; i++) {
    while (~j && rev[j] != str[i])
      j = fail[j];
    ++j;
  }
  printf("%s", str);
  for (int i = len - j - 1; i >= 0; i--)
    putchar(str[i]);
  putchar('\n');
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (scanf("%s", str) != EOF)
    solve(1);
}
}

int main() {
  EPALIN::solve();
  return 0;
}

