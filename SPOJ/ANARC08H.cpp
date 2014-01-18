/* Solved
 * 4557. Musical Chairs
 * File:   ANARC08H.cpp
 * Author: Andy Y.F. Huang
 * Created on March 29, 2013, 1:01 PM
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

namespace ANARC08H {
int len, step;

void solve(int test_num) {
  int rem = 0;
  for (int i = 2; i <= len; i++)
    rem = (rem + step) % i;
  printf("%d %d %d\n", len, step, rem + 1);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (scanf("%d %d", &len, &step) != EOF)
    if (len > 0)
      solve(1);
}
}

int main() {
  ANARC08H::solve();
  return 0;
}

