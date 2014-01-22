/* Solved
 * Codechef 2013 August Lunchtime
 * Pairwise AND sum
 * File:   AND.cpp
 * Author: Andy Y.F. Huang
 * Created on Aug 25, 2013, 5:16:48 PM
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

using namespace std;

namespace AND {
int arr[100111];
int cnt[30];

void solve(int test_num) {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%d", arr + i);
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < N; i++)
    for (int j = 0; j < 30; j++)
      if (1 << j & arr[i])
        cnt[j]++;
  long long res = 0;
  for (int j = 0; j < 30; j++)
    res += cnt[j] * (cnt[j] - 1LL) * (1 << j) / 2;
  printf("%lld\n", res);
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
  AND::solve();
  return 0;
}
