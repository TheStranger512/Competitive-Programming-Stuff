/* Solved
 * 6665. Easy Longest Common Substring
 * Find LCPS between strings
 * File:   ELCS.cpp
 * Author: Andy Y.F. Huang
 * Created on March 29, 2013, 3:32 PM
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

namespace ELCS {
int ipool[555000], *iptr;
int* hash[100100];
char str[500100];
int length[100100];

void solve(int test_num) {
  iptr = ipool;
  int len;
  scanf("%d", &len);
  for (int i = 0; i < len; i++) {
    scanf("%s", str);
    length[i] = strlen(str);
    hash[i] = iptr;
    iptr += length[i];
    hash[i][0] = str[0];
    for (int k = 1, base = 1337; k < length[i]; k++, base = (base << 5) - base)
      hash[i][k] = hash[i][k - 1] + str[k] * base;
    plnarr(hash[i], hash[i] + length[i]);
  }
  int quests;
  scanf("%d", &quests);
  for (int q = 0, a, b; q < quests; q++) {
    scanf("%d %d", &a, &b);
    int ans = -1;
    for (int low = 0, high = min(length[a], length[b]) - 1; low <= high; ) {
      int mid = (low + high) >> 1;
      if (hash[a][mid] == hash[b][mid]) {
        low = mid + 1;
        ans = max(ans, mid);
      }
      else high = mid - 1;
    }
    printf("%d\n", ans + 1);
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  solve(1);
}
}

int main() {
  ELCS::solve();
  return 0;
}

