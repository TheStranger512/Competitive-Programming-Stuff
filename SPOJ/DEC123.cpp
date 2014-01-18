/* Solved
 * 11935. Decorating the Palace
 * File:   DEC123.cpp
 * Author: Andy Y.F. Huang
 * Created on July 27, 2013, 3:05 AM
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

namespace DEC123 {
template <int MOD> struct Uint32Mod {
  int val;

  Uint32Mod() : val(0) { }

  Uint32Mod(long long x) : val(x % MOD) {
    if (val < 0) val += MOD;
  }

  Uint32Mod& operator+=(const Uint32Mod & x) {
    val += x.val;
    if (val >= MOD) val -= MOD;
    return *this;
  }

  Uint32Mod operator+(const Uint32Mod & x) const {
    Uint32Mod res(*this);
    return res += x;
  }

  Uint32Mod& operator-=(const Uint32Mod & x) {
    val -= x.val;
    if (val < 0) val += MOD;
    return *this;
  }

  Uint32Mod operator-(const Uint32Mod & x) const {
    Uint32Mod res(*this);
    return res -= x;
  }

  Uint32Mod& operator*=(const Uint32Mod & x) {
    val = (long long) (val) * x.val % MOD;
    return *this;
  }

  Uint32Mod operator*(const Uint32Mod & x) const {
    Uint32Mod res(*this);
    return res *= x;
  }

  friend ostream& operator<<(ostream& out, Uint32Mod & x) {
    return out << x.val;
  }

} ;

typedef Uint32Mod<1000000007> Int;
Int dp[55][51111];//height, flowers

void solve(int test_num) {
  int H, N;
  cin >> H >> N;
  printf("%d\n", dp[H][N].val);
 }

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  for (int j = 0; j <= 50000; j++)
    dp[1][j] = 1;
  for (int h = 2; h <= 50; h++) {
    for (int j = 0; j <= 50000; j++) {
      if (j & 1)
        dp[h][j] = dp[h - 1][j >> 1] * dp[h - 1][(j + 1) >> 1] * 2;
      else
        dp[h][j] = dp[h - 1][j >> 1] * dp[h - 1][j >> 1];
    }
  }
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  DEC123::solve();
  return 0;
}

