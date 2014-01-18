/*
 * Solved
 * 13381. Manku Word
 * File:   MAY99_2.cpp
 * Author: Andy Y.F. Huang
 * Created on February 22, 2013, 4:16 PM
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
namespace MAY99_2 {
const char* STR = "manku";
typedef long long llong;
char ans[555];

void solve(int test_num) {
  llong n;
  scanf("%lld", &n);
  n--;
  int steps = 1;
  llong five = 1;
  for (;five * 5 <= n; steps++) {
    five *= 5;
    n -= five;
  }
  for (int i = 0; i < steps; i++, n /= 5)
    ans[i] = STR[n % 5];
  reverse(ans, ans + steps);
  for (int i = 0; i < steps; i++)
    putchar(ans[i]);
  putchar('\n');
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
  MAY99_2::solve();
  return 0;
}

