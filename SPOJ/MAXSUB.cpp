/* Solved
 * 8495. Maximum Subset of Array
 * File:   MAXSUB.cpp
 * Author: Andy Y.F. Huang
 * Created on April 17, 2013, 10:10 PM
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

namespace MAXSUB {
#define MOD 1000000009
int arr[55555], two[55555];

void solve(int test_num) {
  int len;
  scanf("%d", &len);
  for (int i = 0; i < len; i++)
    scanf("%d", arr + i);
  sort(arr, arr + len);
  if (arr[len - 1] < 0)
    printf("%d %d\n", arr[len - 1], count(arr, arr + len, arr[len - 1]));
  else {
    long long sum = 0;
    for (int pos = len - 1; pos >= 0 && arr[pos] > 0; pos--)
      sum += arr[pos];
    printf("%lld %d\n", sum, two[count(arr, arr + len, 0)] - (sum == 0));
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  two[0] = 1;
  for (int i = 1; i < 50010; i++) {
    two[i] = two[i - 1] << 1;
    if (two[i] >= MOD)
      two[i] -= MOD;
  }
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  MAXSUB::solve();
  return 0;
}

