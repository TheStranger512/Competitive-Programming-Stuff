/* Solved
 * 10570. Longest Common Substring
 * File:   LONGCS.cpp
 * Author: Andy Y.F. Huang
 * Created on April 4, 2013, 11:19 PM
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

namespace LONGCS {
#define MAX 11100
typedef unsigned uint;
const uint BASE = 31;
char str[11][MAX];
int len[11];
uint power[MAX];
uint hash[11][MAX];
uint vals[11][MAX];
int valcnt[11];
int cnt;

void go(int pos, int size) {
  int cur = hash[pos][size - 1];
  int cnt = 1;
  vals[pos][0] = cur;
  for (int i = size; i < len[pos]; i++)
    vals[pos][cnt++] = hash[pos][i] - hash[pos][i - size] * power[size];
  valcnt[pos] = cnt;
}

bool good() {
  for (int i = 0; i < valcnt[0]; i++) {
    bool ok = true;
    for (int j = 1; j < cnt && ok; j++)
      if (!binary_search(vals[j], vals[j] + valcnt[j], vals[0][i]))
        ok = false;
    if (ok) return true;
  }
  return false;
}

void solve(int test_num) {
  int minlen = MAX, maxlen = 0;
  scanf("%d", &cnt);
  for (int i = 0; i < cnt; i++) {
    scanf("%s", str[i]);
    len[i] = strlen(str[i]);
    minlen = min(minlen, len[i]);
    maxlen = max(maxlen, len[i]);
  }
  power[0] = 1;
  for (int i = 1; i < minlen; i++)
    power[i] = power[i - 1] * BASE;
  for (int i = 0; i < cnt; i++) {
    hash[i][0] = str[i][0];
    for (int j = 1; j < len[i]; j++)
      hash[i][j] = hash[i][j - 1] * BASE + str[i][j];
  }
  int ans = 0;
  for (int low = 1, high = minlen, mid; low <= high; ) {
    mid = (low + high) >> 1;
    //dbgln(mid);
    for (int i = 0; i < cnt; i++) {
      go(i, mid);
      //plnarr(vals[i], vals[i] + valcnt[i]);
      sort(vals[i], vals[i] + valcnt[i]);
    }
    if (good()) {
      ans = mid;
      low = mid + 1;
    }
    else high = mid - 1;
  }
  printf("%d\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int t = 1; t <= tests; t++)
    solve(t);
}
}

int main() {
  LONGCS::solve();
  return 0;
}

