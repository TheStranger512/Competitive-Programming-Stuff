/* Solved
 * 13913. Real Mangoes for Ranjith
 * File:   MANGOES.cpp
 * Author: Andy Y.F. Huang
 * Created on June 2, 2013, 10:55 PM
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

namespace MANGOES {

void solve(int test_num) {
  //find sum of all odd numbers <= n - 2 mod n
  int n;
  scanf("%d", &n);
  int last = n - 2;
  if (~last & 1) last--;
  printf("%lld\n", (((n - 1) / 2) * (1LL + last) / 2) % n);
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
  MANGOES::solve();
  return 0;
}

