/* Solved
 * IOI 2008 Day 2
 * File:   LinearGarden.cpp
 * Author: Andy Y.F. Huang
 * Created on December 26, 2012, 5:31 PM
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
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <iomanip>
#include <cassert>
#include <ctime>
#include <functional>
#include <complex>
#include <numeric>
#include <cctype>
#include <cstddef>
#include <utility>
#include <valarray>
#include <cstdlib>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace LinearGarden {
int len, mod;
char str[1234567];

int fpow(int expon) {
  long long ans = 1, temp = 2;
  for (int e = expon; e > 0; e >>= 1) {
    if (e & 1) ans = ans * temp % mod;
    temp = temp * temp % mod;
  }
  return (int) ans;
}

void solve(int test_num) {
  scanf("%d %d %s", &len, &mod, str);
  int ans = 0, low = 0, high = 0, cur = 0;
  for (int i = 0; i < len; i++) {
    if (str[i] == 'P') {
      int tlow = min(low, cur - 1); //temporary add a lotus
      if (high - tlow == 2)
        ans += cur - 1 == tlow + 1 ? fpow((len - i) >> 1) : fpow((len - i - 1) >> 1);
      else if (high - tlow == 1)
        ans += fpow((len - i) >> 1) + fpow((len - i - 1) >> 1) - 1;
      ans %= mod;
      cur++;
    }
    else cur--;
    low = min(low, cur);
    high = max(high, cur);
  }
  printf("%d\n", (ans + 1) % mod);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve(1);
}
}

int main() {
  LinearGarden::solve();
  return 0;
}

