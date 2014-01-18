/* Solved
 * 8392. Youtube
 * File:   YOUTUBE.cpp
 * Author: Andy Y.F. Huang
 * Created on December 25, 2012, 8:42 PM
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
namespace YOUTUBE {
int succ[32][111111];
int start[111111];

void solve(int test_num) {
  int students, len, tar;
  scanf("%d %d %d", &students, &len, &tar);
  for (int i = 0; i < students; i++)
    scanf("%d", &start[i]);
  for (int i = 1; i <= len; i++)
    scanf("%d", &succ[0][i]);
  for (int j = 1; j < 31; j++)
    for (int i = 1; i <= len; i++)
      succ[j][i] = succ[j - 1][succ[j - 1][i]];
  for (int i = 0; i < students; i++) {
    int ans = start[i], rem = tar;
    for (int bit = 30; bit >= 0; bit--) {
      if ((1 << bit) < rem) {
        ans = succ[bit][ans];
        rem ^= 1 << bit;
      }
    }
    printf("%d ", ans);
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve(1);
}
}

int main() {
  YOUTUBE::solve();
  return 0;
}

