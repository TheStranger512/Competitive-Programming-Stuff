/*
 * Solved
 * 13384. Nice Binary Trees
 * File:   NICEBTRE.cpp
 * Author: Andy Y.F. Huang
 * Created on January 22, 2013, 7:01 PM
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
namespace NICEBTRE {
char str[11111];
int pos;

int go(int depth) {
  if (str[pos++] == 'l')
    return depth;
  return max(go(depth + 1), go(depth + 1));
}

void solve(int test_num) {
  scanf("%s", str);
  pos = 0;
  printf("%d\n", go(0));
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
  NICEBTRE::solve();
  return 0;
}

