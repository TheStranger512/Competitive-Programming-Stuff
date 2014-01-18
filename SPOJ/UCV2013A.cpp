/* Solved
 * 15429. Counting Ids
 * File:   UCV2013A.cpp
 * Author: Andy Y.F. Huang
 * Created on July 29, 2013, 3:55 AM
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

namespace UCV2013A {
#define MOD 1000000007
typedef long long ll;
int N, L;

ll fpow(ll base, int e) {
  ll res = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) res = res * base % MOD;
    base = base * base % MOD;
  }
  return res;
}

void solve(int test_num) {
  if (N + L == 0) return;
  int res = N == 1 ? L : N * (fpow(N, L) - 1) % MOD * fpow(N - 1, MOD - 2) % MOD;
  printf("%d\n", res);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (scanf("%d %d", &N, &L) != EOF)
    solve(1);
}
}

int main() {
  UCV2013A::solve();
  return 0;
}

