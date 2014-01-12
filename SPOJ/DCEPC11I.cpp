/* Solved
 * SPOJ 16210. Impossible Boss
 * File:   DCEPC11I.cpp
 * Author: Andy Y.F. Huang
 * Created on Dec 1, 2013, 6:09:02 PM
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

namespace DCEPC11I {
typedef long long ll;
ll tree[1 << 18], A[1 << 18], B[1 << 18];
int L, R;
ll res;

void prog(int n, int size) {
  const int ls = (size + 1) >> 1, rs = size >> 1;
  tree[n + n] += ls * (2 * A[n] + (ls - 1) * B[n]) / 2;
  A[n + n] += A[n];
  B[n + n] += B[n];
  tree[n + n + 1] += rs * (2 * (A[n] + ls * B[n]) + (rs - 1) * B[n]) / 2;
  A[n + n + 1] += A[n] + ls * B[n];
  B[n + n + 1] += B[n];
  A[n] = B[n] = 0;
}

void update(int n, int l, int r) {
  if (L > r || R < l)
    return;
  if (L <= l && r <= R) {
    tree[n] += (r - l + 1LL) * (2 * (l - L + 1) + (r - l)) / 2;
    A[n] += (l - L + 1);
    B[n]++;
  } else {
    const int m = (l + r) >> 1;
    prog(n, r - l + 1);
    update(n + n, l, m);
    update(n + n + 1, m + 1, r);
    tree[n] = tree[n + n] + tree[n + n + 1];
  }
}

void query(int n, int l, int r) {
  if (L > r || R < l)
    return;
  if (L <= l && r <= R)
    res += tree[n];
  else {
    const int m = (l + r) >> 1;
    prog(n, r - l + 1);
    query(n + n, l, m);
    query(n + n + 1, m + 1, r);
  }
}

void solve(int test_num) {
  int N, Q;
  scanf("%d %d", &N, &Q);
  memset(tree, 0, sizeof(tree));
  memset(A, 0, sizeof(A));
  memset(B, 0, sizeof(B));
  while (Q--) {
    int ty;
    scanf("%d %d %d", &ty, &L, &R);
    if (ty == 0)
      update(1, 1, N);
    else {
      res = 0;
      query(1, 1, N);
      printf("%lld\n", res);
    }
  }
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
  DCEPC11I::solve();
  return 0;
}
