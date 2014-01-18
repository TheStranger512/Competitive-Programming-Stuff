/* Solved
 * 7212. Find String Roots
 * File:   FINDSR.cpp
 * Author: Andy Y.F. Huang
 * Created on February 7, 2013, 10:00 PM
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

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace FINDSR {
char str[111111];
int table[111111];

void solve(int test_num) {
  table[0] = -1;
  int len = strlen(str);
  for (int i = 0, j = -1; i < len; ) {
    while (j >= 0 && str[i] != str[j])
      j = table[j];
    table[++i] = ++j;
  }
  if (len % (len - table[len]) != 0)
    printf("%d\n", 1);
  else
    printf("%d\n", len / (len - table[len]));
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (true) {
    scanf("%s", str);
    if (str[0] == '*') break;
    solve(1);
  }
}
}

int main() {
  FINDSR::solve();
  return 0;
}

