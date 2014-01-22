/*
 * 
 * File:   QMARKS.cpp
 * Author: Andy Y.F. Huang
 * Created on Nov 24, 2013, 1:41:37 AM
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

namespace QMARKS {
string dict[1111];
int dp[1111][1024];
int N, M;
string str;

void subtask_1() {
  string best = "zzzzzzzzzzzzz";
  int res = -1, m = 1;
  for (int i = 0; i < N; i++) //<=8
    m *= 3;
  for (; m >= 0; m--) {
    string s = "";
    bool ok = true;
    for (int i = 0, t = m; i < N; i++, t /= 3) {
      s += t % 3 + 'a';
      if (str[i] != '?' && str[i] != s[i])
        ok = false;
    }
    if (!ok)
      continue;
    //pln(s);
    int cnt = 0;
    for (int i = 0; i < M; i++)
      for (int j = 0; j <= N - (int) dict[i].size(); j++)
        if (equal(dict[i].begin(), dict[i].end(), s.begin() + j))
          cnt++;
    if (cnt > res)
      res = cnt, best = "zzzzzzzzzzzzz";
    if (cnt == res)
      best = min(best, s);
  }
  cout << res << endl;
  cout << best << endl;
}

inline int two(int x) {
  return 1 << x;
}

void subtask_2() {
  memset(dp, 0, sizeof(dp));
  int mask[1111];
  for (int i = 0; i < M; i++) {
    mask[i] = 0;
    for (char& c : dict[i])
      mask[i] = mask[i] << 1 | (c - 'a');
  }
  str = " " + str;
  memset(dp, 0xC0, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 1; i <= N; i++) {
    for (int m = 0; m < 1024; m++) {
      if (str[i] != '?') {
        int nm = (m << 1 | (str[i]-'a')) & 1023;
        int cnt = dp[i-1][m];

      }
    }
  }
}

void solve(int test_num) {
  cin >> N >> M >> str;
  for (int i = 0; i < M; i++)
    cin >> dict[i];
//  if (N <= 8 && *max_element(str.begin(), str.end()) <= 'c')
//    subtask_1();
//  else
  if (*max_element(str.begin(), str.end()) <= 'b')
    subtask_2();
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
  QMARKS::solve();
  return 0;
}
