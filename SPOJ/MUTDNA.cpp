/* Solved
 * 13105. DNA
 * File:   MUTDNA.cpp
 * Author: Andy Y.F. Huang
 * Created on December 31, 2012, 4:52 PM
 */

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <iomanip>
#include <cassert>
#include <ctime>
#include <functional>
#include <complex>
#include <numeric>
#include <cctype>
#include <cstddef>
#include <utility>
#include <valarray>
#include <cstdlib>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace MUTDNA {
char str[1111111];
int toa[1111111], tob[1111111];

void solve(int test_num) {
  int len;
  scanf("%d%s", &len, str + 1);
  if (str[1] == 'A') tob[1] = 1;
  else toa[1] = 1;
  for (int i = 2; i <= len; i++) {
    if (str[i] == 'A') {
      toa[i] = min(toa[i - 1], tob[i - 1] + 1);
      tob[i] = min(tob[i - 1] + 1, toa[i - 1] + 1);
    }
    else {
      toa[i] = min(toa[i - 1] + 1, tob[i - 1] + 1);
      tob[i] = min(tob[i - 1], toa[i - 1] + 1);
    }
  }
  printf("%d\n", toa[len]);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests = 1;
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  MUTDNA::solve();
  return 0;
}

