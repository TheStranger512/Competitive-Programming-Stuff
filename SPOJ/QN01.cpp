/* Solved
 * 12726. XOR Game
 * File:   QN01.cpp
 * Author: Andy Y.F. Huang
 * Created on April 28, 2013, 3:59 PM
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

namespace QN01 {
int sum[1111], seq[1111];

void solve(int test_num) {
  int len;
  scanf("%d", &len);
  for (int i = 1; i <= len; i++)
    scanf("%d", seq + i);
  sum[0] = 0;
  for (int i = 1; i <= len; i++)
    sum[i] = sum[i - 1] ^ seq[i];
  int best = -1, a, b;
  for (int i = 1; i <= len; i++)
    for (int j = i; j <= len; j++)
      if ((sum[j] ^ sum[i - 1]) > best)
        best = (sum[j] ^ sum[i - 1]), a = i, b = j;
  printf("%d\n%d %d\n", best, a, b);
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
  QN01::solve();
  return 0;
}

