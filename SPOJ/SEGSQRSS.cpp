/* Solved
 * SPOJ 11840. Sum of Squares with Segment Tree
 * File:   SEGSQRSS.cpp
 * Author: Andy Y.F. Huang
 * Created on Dec 2, 2013, 11:22:32 AM
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

namespace SEGSQRSS {
typedef long long ll;
const int NIL = 1337;
struct Node {
  ll sum, sqsum;
  int set, inc;

  Node()
      : sum(0), sqsum(0), set(NIL), inc(0) {
  }
};

Node tree[1 << 18];
int init[111000];
int L, R, val;
ll res;
bool is_set;

void prog(Node& n, Node& l, Node& r, int size) {
  //(x+y)^2 = x^2 + y^2 + 2xy
  const int ls = (size + 1) >> 1, rs = size - ls;
  if (n.set != NIL) {
    l.sum = ll(ls) * n.set;
    l.sqsum = l.sum * n.set;
    r.sum = ll(rs) * n.set;
    r.sqsum = r.sum * n.set;
    l.set = r.set = n.set;
    n.set = NIL;
  }
  if (n.inc == 0)
    return;
  l.sqsum += ll(ls) * n.inc * n.inc + 2LL * n.inc * l.sum;
  l.sum += ll(ls) * n.inc;
  l.inc += n.inc;
  r.sqsum = ll(rs) * n.inc * n.inc + 2LL * n.inc * r.sum;
  r.sum += ll(rs) * n.inc;
  r.inc += n.inc;
  n.inc = 0;
}

void query(int n, int l, int r) {
  if (L > r || R < l)
    return;
  if (L <= l && r <= R)
    res += tree[n].sqsum;
  else {
    const int m = (l + r) >> 1;
    prog(tree[n], tree[n + n], tree[n + n + 1], r - l + 1);
    query(n + n, l, m);
    query(n + n + 1, m + 1, r);
  }
}

void update(int n, int l, int r) {
  if (L > r || R < l)
    return;
  if (L <= l && r <= R) {
    const ll size = r - l + 1;
    if (is_set) {
      tree[n].inc = 0;
      tree[n].set = val;
      tree[n].sum = size * val;
      tree[n].sqsum = tree[n].sum * val;
    } else {
      tree[n].inc += val;
      tree[n].sqsum += size * val * val + 2 * val * tree[n].sum;
      tree[n].sum += size * val;
    }
  } else {
    const int m = (l + r) >> 1;
    prog(tree[n], tree[n + n], tree[n + n + 1], r - l + 1);
    update(n + n, l, m);
    update(n + n + 1, m + 1, r);
    tree[n].sum = tree[n + n].sum + tree[n + n + 1].sum;
    tree[n].sqsum = tree[n + n].sqsum + tree[n + n + 1].sqsum;
  }
}

void build(int n, int l, int r) {
  if (l == r) {
    tree[n] = Node();
    tree[n].sum = init[l];
    tree[n].sqsum = init[l] * init[l];
  } else {
    const int m = (l + r) >> 1;
    build(n + n, l, m);
    build(n + n + 1, m + 1, r);
    tree[n].sum = tree[n + n].sum + tree[n + n + 1].sum;
    tree[n].sqsum = tree[n + n].sqsum + tree[n + n + 1].sqsum;
  }
}

void solve(int test_num) {
  int N, Q;
  scanf("%d %d", &N, &Q);
  for (int i = 1; i <= N; i++)
    scanf("%d", init + i);
  build(1, 1, N);
  printf("Case %d:\n", test_num);
  while (Q--) {
    int typ;
    scanf("%d %d %d", &typ, &L, &R);
    if (typ == 2) {
      res = 0;
      query(1, 1, N);
      printf("%lld\n", res);
    } else {
      scanf("%d", &val);
      is_set = typ == 0;
      update(1, 1, N);
    }
  }
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
  SEGSQRSS::solve();
  return 0;
}
