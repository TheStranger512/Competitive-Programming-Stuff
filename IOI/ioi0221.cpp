/* Solved
 * PEG
 * IOI '02 - Yong-In, Korea
 * Batch Scheduling
 * File:   ioi0221.cpp
 * Author: Andy Y.F. Huang
 * Created on Aug 8, 2013, 11:06:07 PM
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

namespace ioi0221 {
typedef pair<int, int> Point; //slope, y-int
typedef long long ll;
int T[10111], F[10111], dp[10111];
deque<Point> q;

int val(const Point& p, int x) {
  return p.first + p.second * x;
}

bool better(const Point& a, const Point& b, const Point& c) {
  //is A intersection C >= A intersection B
  return (ll) (a.second - c.second) * (b.first - a.first)
      >= (ll) (a.second - b.second) * (c.first - a.first);
}

void solve(int test_num) {
  int N, S;
  scanf("%d %d", &N, &S);
  for (int i = 1; i <= N; i++)
    scanf("%d %d", T + i, F + i);
  dp[N] = T[0] = 0;
  for (int i = 1; i <= N; i++)
    T[i] += T[i - 1];
  for (int i = N, sumF = 0; i > 0; i--) {
    sumF += F[i];
    Point cur(dp[i + 1], S + T[i]);
    while (q.size() > 1 && better(q[q.size() - 2], q.back(), cur))
      q.pop_back();
    q.push_back(cur);
    while (q.size() > 1 && val(q[0], sumF) >= val(q[1], sumF))
      q.pop_front();
    dp[i] = val(q.front(), sumF) - T[i - 1] * sumF;
  }
  printf("%d\n", dp[1]);
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
  ioi0221::solve();
  return 0;
}
