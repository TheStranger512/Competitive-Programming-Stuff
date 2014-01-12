/* Solved
 * SPOJ 16245. Living with Courage
 * File:   COURAGE.cpp
 * Author: Andy Y.F. Huang
 * Created on Dec 1, 2013, 7:20:15 PM
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

namespace COURAGE {
typedef long long ll;

struct Node {
  int low, cnt;
  ll sum;
};

Node tree[1 << 18];
int N, PW;

void merge(Node& res, Node& l, Node& r) {
  static ll sum;
  static int low, cnt;
  sum = l.sum + r.sum;
  low = min(l.low, r.low);
  cnt = (l.low == low ? l.cnt : 0) + (r.low == low ? r.cnt : 0);
  res.sum = sum;
  res.low = low;
  res.cnt = cnt;
}

ll get(int l, int r) {
  static Node res;
  memset(&res, 0, sizeof(Node));
  res.low = 1 << 30;
  for (l += PW, r += PW + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1)
      merge(res, res, tree[l++]);
    if (r & 1)
      merge(res, res, tree[--r]);
  }
  return res.sum - (ll) (res.low) * res.cnt;
}

void update(int i, int v) {
  i += PW;
  tree[i].sum += v;
  tree[i].low += v;
  for (i >>= 1; i > 0; i >>= 1)
    merge(tree[i], tree[i + i], tree[i + i + 1]);
}

void solve(int test_num) {
  memset(tree, 0, sizeof(tree));
  scanf("%d", &N);
  for (PW = 1; PW < N;)
    PW <<= 1;
  for (int i = 0; i < N; i++) {
    scanf("%d", &tree[i + PW].low);
    tree[i + PW].sum = tree[i + PW].low;
    tree[i + PW].cnt = 1;
  }
  for (int i = N; i < PW; i++)
    tree[i + PW].low = 1 << 30;
  for (int i = PW - 1; i > 0; i--)
    merge(tree[i], tree[i + i], tree[i + i + 1]);
  int Q;
  scanf("%d", &Q);
  while (Q--) {
    static char ty[11];
    static int l, r, v, p;
    scanf("%s", ty);
    if (ty[0] == 'C') {
      scanf("%d %d", &l, &r);
      printf("%lld\n", get(l, r));
    } else {
      scanf("%d %d", &v, &p);
      if (ty[0] == 'E')
        v = -v;
      update(p, v);
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
  COURAGE::solve();
  return 0;
}
