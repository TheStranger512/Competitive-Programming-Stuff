/* Solved
 * 5979. Yet Another Permutations Problem
 * File:   YAPP.cpp
 * Author: Andy Y.F. Huang
 * Created on January 28, 2013, 9:31 AM
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
namespace YAPP {
#define mod 1000000007

void solve(int test_num) {
  int n;
  scanf("%d", &n);
  long long ans = 1, temp = 2;
  for (int e = n - 1; e > 0; e >>= 1) {
    if (e & 1)
      ans = ans * (temp) % mod;
    temp = temp * temp % mod;
  }
  printf("%lld\n", ans);
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
    solve(1);
}
}

int main() {
  YAPP::solve();
  return 0;
}

