/* Solved
 * Polo the Penguin and the Numbers
 * File:   PPNUM.cpp
 * Author: Andy Y.F. Huang
 * Created on Oct 20, 2013, 12:18:40 PM
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

using namespace std;

namespace PPNUM {
typedef long long ll;
const int MOD = 1000000007;
ll pw[12];

ll sum2(int x) {
  return x * (x + 1LL) / 2;
}

ll sum(int a, int b) {
  return (sum2(b) - sum2(a - 1)) % MOD;
}

ll f(int upto) {
  //< upto
  ll res = 0;
  for (int e = 0; pw[e] < upto; e++)
    res = (res + sum(pw[e], min(pw[e + 1], (ll) upto) - 1) * (e + 1)) % MOD;
  return res;
}

void solve(int test_num) {
  int L, R;
  cin >> L >> R;
  ll res = f(R + 1) - f(L);
  res %= MOD;
  if (res < 0)
    res += MOD;
  cout << res << endl;
  //pln(sum(9, 12));
}

void solve() {
#ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
#endif
  pw[0] = 1;
  for (int i = 1; i < 12; i++)
    pw[i] = 10 * pw[i - 1];
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  PPNUM::solve();
  return 0;
}
