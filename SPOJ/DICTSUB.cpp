/* Solved
 * 3106. Dictionary Subsequences
 * File:   DICTSUB.cpp
 * Author: Andy Y.F. Huang
 * Created on June 22, 2013, 1:05 PM
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

namespace DICTSUB {
vector<int> pos[26];
char str[11111], rle[222];

void solve(int test_num) {
  for (int i = 0; i < 26; i++)
    pos[i].clear();
  int cnt;
  scanf("%d %s", &cnt, str);
  for (int i = 0; str[i] > ' '; i++)
    pos[str[i] - 'A'].push_back(i);
  for (int i = 0; i < cnt; i++) {
    scanf("%s", rle);
    int at = -1;
    bool ok = true;
    for (int j = 0; rle[j] > ' '; ) {
      int k = j, run;
      while (isdigit(rle[k]))
        k++;
      sscanf(rle + j, "%d", &run);
      int c = rle[k] - 'A';
      j = k + 1;
      at = upper_bound(pos[c].begin(), pos[c].end(), at) - pos[c].begin() + run - 1;
      if (at >= (int) pos[c].size()) {
        ok = false;
        break;
      }
      at = pos[c][at];
    }
    if (ok) puts("YES");
    else puts("NO");
  }
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
  DICTSUB::solve();
  return 0;
}

