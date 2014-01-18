/* Solved
 * 1870. Making Labels
 * File:   MKLABELS.cpp
 * Author: Andy Y.F. Huang
 * Created on April 21, 2013, 11:18 PM
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

namespace MKLABELS {

void solve(int test_num) {
  int n;
  for (int t = 1; cin >> n; t++) {
    if (n == 0) break;
    long long ans = 1;
    for (int i = 0; i < n - 2; i++)
      ans *= n;
    printf("Case %d, N = %d, # of different labelings = %lld\n", t, n, ans);
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  solve(1);
}
}

int main() {
  MKLABELS::solve();
  return 0;
}

