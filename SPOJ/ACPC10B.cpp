/*
 * Solved
 * 7976. Sum the Square
 * File:   ACPC10B.cpp
 * Author: Andy Y.F. Huang
 * Created on March 29, 2013, 7:35 PM
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

namespace ACPC10B {
int A, B;
int dist[1111], seq[1111];
bool have[1111];

int go(int num) {
  int res = 0;
  for (; num > 0; num /= 10)
    res += (num % 10) * (num % 10);
  return res;
}

void solve(int test_num) {
  printf("%d %d ", A, B);
  if (A == B) {
    puts("2");
    return;
  }
  memset(dist, -1, sizeof (dist));
  memset(have, false, sizeof (have));
  int len = 0;
  seq[len++] = A;
  for (int cur = A; ; ) {
    cur = go(cur);
    if (!have[cur]) have[seq[len++] = cur] = true;
    else break;
  }
  //plnarr(seq, seq + len);
  if (B < 1100) dist[B] = 1;
  for (int cur = B, d = 2; ; d++) {
    cur = go(cur);
    if (dist[cur] < 0) dist[cur] = d;
    else break;
  }
  int ans = 1 << 20;
  for (int i = 0; i < len; i++)
    if (seq[i] < 1100 && dist[seq[i]] > 0)
      ans = min(ans, i + 1 + dist[seq[i]]);
  if (ans > 10000) puts("0");
  else printf("%d\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (scanf("%d %d", &A, &B) != EOF)
    if (A > 0)
      solve(1);
}
}

int main() {
  ACPC10B::solve();
  return 0;
}

