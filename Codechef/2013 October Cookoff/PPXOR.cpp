/* Solved
 * Polo the Penguin and the XOR
 * File:   PPXOR.cpp
 * Author: Andy Y.F. Huang
 * Created on Oct 20, 2013, 12:28:03 PM
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

namespace PPXOR {
typedef long long ll;
int a[111000], xsum[111000];
int cnt[30];

void solve(int test_num) {
  int N;
  ll res = 0;
  cin >> N;
  for (int i = 1; i <= N; i++)
    cin >> a[i];
  xsum[0] = 0;
  memset(cnt, 0, sizeof(cnt)); //count of one bits
  for (int i = 1; i <= N; i++) {
    xsum[i] = a[i] ^ xsum[i - 1];
    for (int e = 0; e < 30; e++) {
      if (1 << e & xsum[i])
        res += (1LL << e) * (i - cnt[e]);
      else
        res += (1LL << e) * cnt[e];
      if (1 << e & xsum[i])
        cnt[e]++;
    }
  }
  cout << res << endl;
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
  PPXOR::solve();
  return 0;
}
