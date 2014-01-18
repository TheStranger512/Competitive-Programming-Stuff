/*
 * Solved
 * 2853. Decode the Strings
 * File:   PDECODE.cpp
 * Author: Andy Y.F. Huang
 * Created on March 25, 2013, 8:08 PM
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

namespace PDECODE {
int len, by;
int next[33][99];
char str[99];
int at[99], ans[99];

void solve(int test_num) {
  for (int i = 1; i <= len; i++)
    scanf("%d", &next[0][i]);
  gets(str);
  gets(str + 1);
  for (int j = 1; j < 31; j++)
    for (int i = 1; i <= len; i++)
      next[j][i] = next[j - 1][next[j - 1][i]];
  for (int i = 1; i <= len; i++)
    at[i] = i;
  for (int bit = 30; bit >= 0; bit--)
    if (1 << bit & by)
      for (int i = 1; i <= len; i++)
        at[i] = next[bit][at[i]];
  for (int i = 1; i <= len; i++)
    ans[at[i]] = i;
  for (int i = 1; i <= len; i++)
    putchar(str[ans[i]]);
  putchar('\n');
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (scanf("%d %d", &len, &by) != EOF) {
    if (len == 0)
      break;
    solve(1);
  }
}
}

int main() {
  PDECODE::solve();
  return 0;
}

