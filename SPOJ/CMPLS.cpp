/* Solved
 * 8. Complete the Sequence!
 * File:   CMPLS.cpp
 * Author: Andy Y.F. Huang
 * Created on January 22, 2013, 6:45 PM
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

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace CMPLS {
int diff[111][111];

bool good(const int* arr, int len) {
  for (int i = 1; i < len; i++)
    if (arr[i] != arr[i - 1])
      return false;
  return true;
}

void solve(int test_num) {
  memset(diff, 0, sizeof (diff));
  int len, needlen;
  scanf("%d %d", &len, &needlen);
  needlen += len;
  for (int i = 0; i < len; i++)
    scanf("%d", &diff[0][i]);
  int deg = 0;
  while (!good(diff[deg], len - deg)) {
    for (int i = 0; i < len - deg - 1; i++)
      diff[deg + 1][i] = diff[deg][i + 1] - diff[deg][i];
    deg++;
  }
//  plnarr(diff, deg + 1, len);
//  pln("");
  while (deg >= 0) {
    for (int i = len - deg; i < needlen; i++)
      diff[deg][i] = diff[deg][i - 1] + diff[deg + 1][i - 1];
    deg--;
  }
//  plnarr(diff, 10, needlen);
//  pln("");
  for (int i = len; i < needlen; i++)
    printf("%d ", diff[0][i]);
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
  CMPLS::solve();
  return 0;
}

