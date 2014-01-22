/* Solved
 * Codechef 2013 October Challenge
 * Yet Another Nice Girl
 * File:   ARRGAME2.cpp
 * Author: Andy Y.F. Huang
 * Created on Oct 4, 2013, 4:07:31 PM
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

namespace ARRGAME2 {
int x[111000], y[111000];

void solve(int test_num) {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> x[i];
  for (int i = 0; i < N; i++) {
    cin >> y[i];
    y[i] = -y[i];
  }
  sort(y, y + N);
  int ones = count(y, y + N, -1);
  int threes = count(y, y + N, -3);
  double res = 0.0;
  for (int i = 0; i < N; i++) {
    if (x[i] == 1)
      continue;
    if (x[i] == 2)
      res += double(ones + lower_bound(y, y + N, -4) - y) / N;
    else if (x[i] == 3)
      res += double(N - threes) / N;
    else
      res += double(ones + lower_bound(y, y + N, -x[i]) - y) / N;
  }
  printf("%.6lf\n", res);
}

void solve() {
#ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
#endif
  //pln(log(2) / 2, log(3) / 3, log(4) / 4, log(5) / 5);
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  ARRGAME2::solve();
  return 0;
}
