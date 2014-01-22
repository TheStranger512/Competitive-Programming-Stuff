/*
 * 
 * File:   RRCODE.cpp
 * Author: Andy Y.F. Huang
 * Created on Sep 22, 2013, 12:02:07 PM
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

namespace RRCODE {
int a[1111];

void solve(int test_num) {
  int N, K, ans;
  cin >> N >> K >> ans;
  for (int i = 0; i < N; i++)
    cin >> a[i];
  string op;
  cin >> op;
  for (int i = 0; i < N; i++) {
    if (op == "XOR") {
      if (K & 1)
        ans ^= a[i];
    } else if (op == "AND") {
      if (K > 0)
        ans &= a[i];
    } else if (K > 0)
      ans |= a[i];
  }
  cout << ans << endl;
}

void solve() {
#ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
#endif
  int tests;
  cin >> tests;
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  RRCODE::solve();
  return 0;
}
