/* Solved
 * 3962. ELEVATOR II
 * File:   MELE2.cpp
 * Author: Andy Y.F. Huang
 * Created on June 2, 2013, 10:22 PM
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

namespace MELE2 {
typedef long long llong;
typedef pair<llong, int> Node;
llong dp[111000];
priority_queue<Node> q;

void solve(int test_num) {
  llong height;
  int A, B, C;
  cin >> height >> A >> B >> C;
  if (B < A) swap(A, B);
  if (C < A) swap(A, C);
  memset(dp, 0x3F, sizeof (dp));
  q.push(Node(0, 0));
  dp[0] = 0;
  for (; !q.empty(); q.pop()) {
    int at = q.top().second;
    if (dp[at] < -q.top().first);
    if (dp[at] + B < dp[(at + B) % A]) {
      dp[(at + B) % A] = dp[at] + B;
      q.push(Node(-dp[at] - B, (at + B) % A));
    }
    if (dp[at] + C < dp[(at + C) % A]) {
      dp[(at + C) % A] = dp[at] + C;
      q.push(Node(-dp[at] - C, (at + C) % A));
    }
  }
  //plnarr(dp, dp + A);
  llong res = 0;
  height--;
  for (int i = 0; i < A; i++) {
    if (dp[i] <= height) {
      res += height / A - dp[i] / A;
    }
  }
  for (int i = height % A; i >= 0; i--)
    if (dp[i] <= height)
      res++;
  //if (res == 0) res = 1;
  cout << res << endl;
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
  MELE2::solve();
  return 0;
}

