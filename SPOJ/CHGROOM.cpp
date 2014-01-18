/* Solved
 * 13545. Room Change
 * File:   CHGROOM.cpp
 * Author: Andy Y.F. Huang
 * Created on March 25, 2013, 8:17 PM
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

namespace CHGROOM {
const char* FIRST = "ANNE";
const char* SECOND = "MARIAN";

void solve(int test_num) {
  long long num;
  cin >> num;
  int cnt = 0;
  for (long long i = 2; i * i <= num && cnt < 3; i++) {
    for (; num % i == 0; num /= i)
      cnt++;
  }
  if (num > 1) cnt++;
  if (num == 1 || cnt == 1 || cnt >= 3) puts(FIRST);
  else puts(SECOND);
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
  CHGROOM::solve();
  return 0;
}

