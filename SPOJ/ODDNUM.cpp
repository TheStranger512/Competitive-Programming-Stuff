/*
 * Solved
 * 13983. Count The Odd Number
 * File:   ODDNUM.cpp
 * Author: Andy Y.F. Huang
 * Created on March 4, 2013, 9:49 PM
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
namespace ODDNUM {
int fact[11];

void solve(int test_num) {
  int len, zeroes = 0, odd = 0;
  scanf("%d", &len);
  for (int i = 0, digit; i < len; i++) {
    scanf("%d", &digit);
    if (digit == 0)
      zeroes++;
    if (digit & 1)
      odd++;
  }
  if (len == 1)
    printf("%d\n", odd);
  else if (len - zeroes - 2 < 0)
    puts("0");
  else
    printf("%d\n", odd * (len - zeroes - 1) * fact[len - 2]);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  fact[0] = 1;
  for (int i = 1; i <= 10; i++)
    fact[i] = fact[i - 1] * i;
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  ODDNUM::solve();
  return 0;
}

