/* Solved
 * 15431. Farmer Cream
 * File:   UCV2013C.cpp
 * Author: Andy Y.F. Huang
 * Created on July 29, 2013, 3:13 AM
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

namespace UCV2013C {
long long D;
int B, F, M;

void solve(int test_num) {
  if (D + B + F + M == 0)
    return;
  long long cost = (1 + F * (F + 1LL) / 2) * B;
  if (D - cost >= M)
    printf("Farmer Cream will have %lld Bsf to spend.\n", D - cost);
  else
    printf("The firm is trying to bankrupt Farmer Cream by %lld Bsf.\n", cost + M - D);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (cin >> D >> F >> B >> M)
    solve(1);
}
}

int main() {
  UCV2013C::solve();
  return 0;
}

