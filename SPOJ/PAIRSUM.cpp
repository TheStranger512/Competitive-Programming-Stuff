/* Solved
 * 9569. Sum of Pairwise Products
 * File:   PAIRSUM.cpp
 * Author: Andy Y.F. Huang
 * Created on May 22, 2013, 12:02 AM
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

namespace PAIRSUM {
typedef long long llong;
llong prod[100111], sum[100111];

void solve(int test_num) {
  int len;
  scanf("%d", &len);
  sum[0] = prod[0] = 0;
  for (int i = 1, x; i <= len; i++) {
    scanf("%d", &x);
    sum[i] = x + sum[i - 1];
    prod[i] = x * sum[i] + prod[i - 1];
  }
  int quests;
  scanf("%d", &quests);
  for (int q = 0, a, b; q < quests; q++) {
    scanf("%d %d", &a, &b);
    b++, a++;
    llong res = prod[b] - prod[a - 1];
    res -= sum[a - 1] * (sum[b] - sum[a - 1]);
    printf("%lld\n", res);
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
  PAIRSUM::solve();
  return 0;
}

