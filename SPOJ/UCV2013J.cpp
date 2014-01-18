/* Solved
 * 15438. Valences
 * File:   UCV2013J.cpp
 * Author: Andy Y.F. Huang
 * Created on July 23, 2013, 12:01 AM
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

namespace UCV2013J {
int N;
short val[1111000];

void solve(int test_num) {
  for (int i = 1; i <= N; i++) {
    scanf("%hd", val + i);
    //assert(val[i] <= 100);
  }
  int l = 1, res = 0;
  while (l <= N) l <<= 1;
  l >>= 1;
  for (int i = (N >> 1) + 1; i <= N; i++)
    res += val[i];
  printf("%d\n", res);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (scanf("%d", &N) != EOF)
    if (N > 0)
      solve(1);
}
}

int main() {
  UCV2013J::solve();
  return 0;
}

