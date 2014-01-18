/* Solved
 * 8184. Bureaucracy
 * File:   BUREAU.cpp
 * Author: Andy Y.F. Huang
 * Created on May 22, 2013, 8:45 PM
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

namespace BUREAU {
int par[100100];
bool active[100100];
char str[11];

void solve(int test_num) {
  int len;
  scanf("%d", &len);
  for (int i = 1; i <= len; i++) {
    active[i] = true;
    scanf("%s", str);
    if (str[0] == 'd')
      par[i] = 0;
    else
      scanf("%d", par + i);
  }
  int cnt = 0;
  for (int i = len; i > 0; i--) {
    active[par[i]] &= !active[i];
    if (active[i])
      cnt++;
  }
  printf("%d\n", cnt);
  for (int i = 1; i <= len; i++)
    if (active[i])
      printf("%d ", i);
  putchar('\n');
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
  BUREAU::solve();
  return 0;
}

