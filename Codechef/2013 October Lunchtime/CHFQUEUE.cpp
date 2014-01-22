/* Solved
 * Codechef 2013 October Lunchtime
 * Chefs in Queue
 * File:   CHFQUEUE.cpp
 * Author: Andy Y.F. Huang
 * Created on Oct 27, 2013, 1:57:45 AM
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

namespace CHFQUEUE {
typedef long long ll;
const int mod = 1000000007;
int a[1 << 20];

void solve(int test_num) {
  int N, K;
  scanf("%d %d", &N, &K);
  for (int i = 0; i < N; i++)
    scanf("%d", a + i);
  reverse(a, a + N);
  stack<int> s;
  ll res = 1;
  for (int i = 0; i < N; i++) {
    while (!s.empty() && a[i] <= a[s.top()])
      s.pop();
    if (!s.empty()) {
      res = res * (i - s.top() + 1) % mod;
      //pln(i, s.top());
    }
    s.push(i);
  }
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
  CHFQUEUE::solve();
  return 0;
}
