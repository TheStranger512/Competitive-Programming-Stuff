/* Solved
 * 5450. Tiles of Tetris, Not!
 * File:   ANARC09B.cpp
 * Author: Andy Y.F. Huang
 * Created on August 8, 2012, 3:07 PM
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
namespace ANARC09B {
typedef long long int64;

int64 gcd(int64 a, int64 b) {
  return b == 0 ? a : gcd(b, a % b);
}

void solve(int test_num, int64 a, int64 b) {
  int64 g = gcd(a, b);
  printf("%lld\n", a * b / (g* g));
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (true) {
    int64 a, b;
    scanf("%lld %lld", &a, &b);
    if (!a)
      break;
    solve(1, a, b);
  }
}
}

int main() {
  ANARC09B::solve();
  return 0;
}

