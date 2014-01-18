/* Solved
 * 7102. Doing The Word Wrap
 * File:   DTWW.cpp
 * Author: Andy Y.F. Huang
 * Created on April 26, 2013, 12:23 AM
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

namespace DTWW {
int maxlines, words;
int len[111111];
char str[55];

bool check(int width) {
  int cnt = 1;
  for (int i = 1, at = len[0]; i < words; i++) {
    if (at + 1 + len[i] <= width)
      at += 1 + len[i];
    else {
      cnt++;
      at = len[i];
    }
  }
  return cnt <= maxlines;
}

void solve(int test_num) {
  for (int i = 0; i < words; i++) {
    scanf("%s", str);
    len[i] = strlen(str);
  }
  int ans = 300000;
  for (int low = *max_element(len, len + words), high = 266666; low <= high; ) {
    int mid = (low + high) >> 1;
    if (check(mid)) {
      ans = mid;
      high = mid - 1;
    }
    else low = mid + 1;
  }
  printf("%d\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (scanf("%d %d", &maxlines, &words) != EOF)
    if (maxlines > -1)
      solve(1);
}
}

int main() {
  DTWW::solve();
  return 0;
}

