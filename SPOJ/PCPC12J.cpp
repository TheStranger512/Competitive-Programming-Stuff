/* Solved
 * 13096. Amr Samir
 * File:   PCPC12J.cpp
 * Author: Andy Y.F. Huang
 * Created on December 28, 2012, 3:42 PM
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
namespace PCPC12J {
int cnt[111];

void solve(int test_num) {
  memset(cnt, 0, sizeof (cnt));
  int len;
  scanf("%d", &len);
  for (int i = 0; i < len; i++) {
    int val;
    scanf("%d", &val);
    cnt[val]++;
  }
  int lar = 0, best = -1;
  for (int i = 1; i <= 100; i++) {
    if (cnt[i] && cnt[i] % i == 0 && cnt[i] > lar) {
      lar = cnt[i];
      best = i;
    }
  }
  printf("%d\n", best);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  PCPC12J::solve();
  return 0;
}

