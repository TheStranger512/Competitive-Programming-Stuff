/*
 * 
 * File:   RRMATRIX.cpp
 * Author: Andy Y.F. Huang
 * Created on Sep 22, 2013, 12:10:36 PM
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

namespace RRMATRIX {
typedef long long ll;

void solve(int test_num) {
  int R, C;
  cin >> R >> C;
  if (R == 1 || C == 1)
    cout << ll(R * C) << endl;
  else {
    cout << (__gcd(R - 1, C - 1) + 1) << endl;
  }
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
  RRMATRIX::solve();
  return 0;
}
