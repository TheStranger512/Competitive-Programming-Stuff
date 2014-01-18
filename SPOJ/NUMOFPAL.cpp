/* Solved
 * 7586. Number of Palindromes
 * File:   NUMOFPAL.cpp
 * Author: Andy Y.F. Huang
 * Created on March 30, 2013, 11:30 PM
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

namespace NUMOFPAL {
#define MAX 1010
char str[MAX], rev[MAX];

void solve(int test_num) {
  gets(str);
  int len = strlen(str);
  while (str[len - 1] <= ' ') len--;
  reverse_copy(str, str + len, rev);
  int ans = 0;
  for (int i = 0; i < len; i++) {
    int a = i, b = i;
    while (a >= 0 && b < len && str[a] == str[b]) {
      ans++;
      a--;
      b++;
    }
    if (i + 1 < len) {
      a = i, b = i + 1;
      while (a >= 0 && b < len && str[a] == str[b]) {
        ans++;
        a--;
        b++;
      }
    }
  }
  printf("%d\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  solve(1);
}
}

int main() {
  NUMOFPAL::solve();
  return 0;
}

