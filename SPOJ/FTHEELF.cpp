/* Solved
 * 7104. Feanor The Elf
 * Max range of ideal projectile
 * See http://en.wikipedia.org/wiki/Range_of_a_projectile
 * Derivation of formula is long
 * File:   FTHEELF.cpp
 * Author: Andy Y.F. Huang
 * Created on September 22, 2012, 10:42 PM
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
namespace FTHEELF {
const double g = 9.8;

void solve(int test_num, int v, int h) {
  printf("%.6lf\n", v * sqrt(v * v + 2 * g * h) / g);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (true) {
    int velocity, height;
    scanf("%d %d", &velocity, &height);
    if (velocity == -1 && height == -1)
      break;
    solve(1, velocity, height);
  }
}
}

int main() {
  FTHEELF::solve();
  return 0;
}

