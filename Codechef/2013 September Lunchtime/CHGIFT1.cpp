/* Solved
 * Chef and Gift
 * File:   CHGIFT1.cpp
 * Author: Andy Y.F. Huang
 * Created on Sep 29, 2013, 1:48:44 AM
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

namespace CHGIFT1 {
typedef long long ll;
int x[11];
ll h[11], l[11];

void solve(int test_num) {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%d", x + i);
  l[0] = h[0] = x[0];
  for (int i = 1; i < N; i++) {
    ll a = l[i - 1] * x[i], b = l[i - 1] - x[i], c = l[i - 1] + x[i];
    ll d = h[i - 1] * x[i], e = h[i - 1] - x[i], f = h[i - 1] + x[i];
    l[i] = min(min(min(a, b), min(c, d)), min(e, f));
    h[i] = max(max(max(a, b), max(c, d)), max(e, f));
  }
  printf("%lld\n", l[N - 1]);
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
  CHGIFT1::solve();
  return 0;
}
