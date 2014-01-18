/* Solved
 * 13769. Roommate Agreement
 * File:   CRAN02.cpp
 * Author: Andy Y.F. Huang
 * Created on February 18, 2013, 2:33 PM
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

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace CRAN02 {
int seq[1 << 20];

void solve(int test_num) {
  seq[0] = 0;
  int len;
  scanf("%d", &len);
  for (int i = 1; i <= len; i++) {
    scanf("%d", seq + i);
    seq[i] += seq[i - 1];
  }
  sort(seq, seq + len + 1);
  long long total = 0;
  for (int i = 0; i <= len; ) {
    int j = i;
    while (j <= len && seq[j] == seq[i])
      j++;
    total += (0LL + j - i) * (j - i - 1) / 2;
    i = j;
  }
  printf("%lld\n", total);
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
  CRAN02::solve();
  return 0;
}

