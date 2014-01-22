/* Solved
 * Codechef 2014 January Cook-off
 * Interrogating Gangsters
 * File:   GANGAAM.cpp
 * Author: Andy Y.F. Huang (azneye)
 * Created on Jan 19, 2014, 11:53:16 AM
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

namespace GANGAAM {
typedef pair<int, int> Inter;

static Inter t[222];

bool cmp(int a, int b) {
  return t[a].second > t[b].second;
}

void solve(int test_num) {
  int N, X;
  cin >> N >> X;
  for (int i = 0; i < N; i++)
    cin >> t[i].first >> t[i].second;
  sort(t, t + N);
  static int now[222];
  static bool asked[222];
  memset(asked, false, sizeof(asked));
  int len = 0, res = 0;
  for (int i = 0; i < N; i++) {
    int cnt = 0; //already asked
    {
      int nlen = 0;
      for (int j = 0; j < len; j++)
        if (t[now[j]].second >= t[i].first)
          now[nlen++] = now[j];
      len = nlen;
      for (int j = 0; j < len; j++)
        if (asked[now[j]])
          cnt++;
      now[len++] = i;
    }
    if (len >= X) {
      int need = len - X + 1 - cnt;
      sort(now, now + len, cmp);
      for (int j = 0; j < len && need > 0; j++) {
        if (!asked[now[j]]) {
          asked[now[j]] = true;
          need--;
          res++;
        }
      }
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
  cin >> tests;
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  GANGAAM::solve();
  return 0;
}
