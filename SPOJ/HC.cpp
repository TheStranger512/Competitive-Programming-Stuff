/* Solved
 * 6772. Happy Coins
 * File:   HC.cpp
 * Author: Andy Y.F. Huang
 * Created on July 25, 2013, 9:54 PM
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

namespace HC {

void solve(int test_num) {
  int N, cnt = 0;
  char a, b, c;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf(" %c%c%c", &a, &b, &c);
    if (a == 'l')
      cnt ^= 1;
  }
  if (cnt & 1) puts("lxh");
  else puts("hhb");
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
  HC::solve();
  return 0;
}

