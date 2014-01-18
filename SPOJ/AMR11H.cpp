/* Solved
 * 10235. Array Diversity
 * File:   AMR11H.cpp
 * Author: Andy Y.F. Huang
 * Created on April 2, 2013, 8:06 PM
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

namespace AMR11H {
#define MOD 1000000007
int arr[111000];
long long two[111000];

void solve(int test_num) {
  int len;
  scanf("%d", &len);
  int high = -1, low = 1 << 20, highcnt = 0, lowcnt = 0;
  int firsth, firstl;
  for (int i = 0; i < len; i++) {
    scanf("%d", arr + i);
    if (arr[i] > high) {
      high = arr[i];
      highcnt = 0;
      firsth = i;
    }
    if (arr[i] == high) highcnt++;
    if (arr[i] < low) {
      low = arr[i];
      lowcnt = 0;
      firstl = i;
    }
    if (arr[i] == low) lowcnt++;
  }
  int sstr = 0;
  int lasth = firsth, lastl = firstl;
  for (int i = min(firstl, firsth); i < len; i++) {
    if (arr[i] == high) lasth = i;
    if (arr[i] == low) lastl = i;
    if (i < max(firstl, firsth)) continue;
    sstr += min(lastl, lasth) + 1;
    if (sstr >= MOD) sstr -= MOD;
  }
  int sseq;
  if (low == high)
    sseq = (int) (two[len] - 1);
  else
    sseq = ((two[highcnt] - 1) * (two[lowcnt] - 1) % MOD) * two[len - highcnt - lowcnt] % MOD;
  printf("%d %d\n", sstr, sseq);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  two[0] = 1;
  for (int i = 1; i <= 100000; i++) {
    two[i] = two[i - 1] << 1;
    if (two[i] >= MOD) two[i] -= MOD;
  }
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  AMR11H::solve();
  return 0;
}

