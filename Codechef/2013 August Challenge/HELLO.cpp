/* Solved
 * August Challenge 2013
 * Hello Hello
 * File:   HELLO.cpp
 * Author: Andy Y.F. Huang
 * Created on August 2, 2013, 11:09 AM
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

namespace HELLO {

void solve(int test_num) {
  double D; //default rate
  int U, N; //minutes, number of plan choices
  cin >> D >> U >> N;
  double best = D * U;
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    int M, C; //period, cost
    double R; //rate
    cin >> M >> R >> C;
    double temp = (C + M * U * R) / M;
    if (temp < best) {
      ans = i;
      best = temp;
    }
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
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  HELLO::solve();
  return 0;
}

