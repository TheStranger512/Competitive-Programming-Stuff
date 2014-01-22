/*
 * Solved
 * Codechef 2014 January Challenge
 * Chef and the Cake I
 * File:   CAKE1AM.cpp
 * Author: Andy Y.F. Huang (azneye)
 * Created on Jan 19, 2014, 11:09:50 AM
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

namespace CAKE1AM {

int inter(int a, int b, int c, int d) {
  //[a,b],[c,d]
  return max(0, min(b, d) - max(a, c));
}

int area(int a, int b, int c, int d) {
  return (b - a) * (d - c);
}

void solve(int test_num) {
  int x1[2], y1[2], x2[2], y2[2];
  for (int i = 0; i < 2; i++)
    cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
  int res = area(x1[0], x2[0], y1[0], y2[0]) + area(x1[1], x2[1], y1[1], y2[1])
      - inter(x1[0], x2[0], x1[1], x2[1]) * inter(y1[0], y2[0], y1[1], y2[1]);
  cout << res << endl;
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
  CAKE1AM::solve();
  return 0;
}
