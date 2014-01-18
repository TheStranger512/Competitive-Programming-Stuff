/*
 * Solved
 * 6829. Polynomial
 * File:   POLYNOM.cpp
 * Author: Andy Y.F. Huang
 * Created on February 26, 2013, 12:19 AM
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
namespace POLYNOM {
int diff[4][555];

void solve(int test_num) {
  int len;
  scanf("%d", &len);
  for (int i = 0; i < len; i++)
    scanf("%d", &diff[0][i]);
  for (int j = 1; j < 4; j++)
    for (int i = 0; i < len - j; i++)
      diff[j][i] = diff[j - 1][i + 1] - diff[j - 1][i];
  for (int j = 0; j < 4; j++) {
    if (count(diff[j], diff[j] + len - j, diff[j][0]) == len - j) {
      puts("YES");
      return;
    }
  }
  puts("NO");
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
  POLYNOM::solve();
  return 0;
}

