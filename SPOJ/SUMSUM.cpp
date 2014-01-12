/* Solved
 * 15766. Enjoy Sum with Operations
 * File:   SUMSUM.cpp
 * Author: Andy Y.F. Huang
 * Created on Dec 1, 2013, 11:44:29 PM
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

namespace SUMSUM {
typedef long long ll;

struct Node {
  int cnt[30];
};

Node tree[1 << 18];
int PW;

void merge(Node& res, const Node& l, const Node& r) {
  for (int b = 0; b < 30; b++)
    res.cnt[b] = l.cnt[b] + r.cnt[b];
}

void update(int i, int v) {
  i += PW;
  for (int b = 0; b < 30; b++)
    tree[i].cnt[b] = v >> b & 1;
  for (i >>= 1; i > 0; i >>= 1)
    merge(tree[i], tree[i + i], tree[i + i + 1]);
}

Node get(int l, int r) {
  static Node res;
  memset(&res, 0, sizeof(res));
  for (l += PW, r += PW + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1)
      merge(res, res, tree[l++]);
    if (r & 1)
      merge(res, res, tree[--r]);
  }
  return res;
}

ll comb2(int x) {
  return x * (x - 1LL) / 2;
}

void solve(int test_num) {
  memset(tree, 0, sizeof(tree));
  int N, Q;
  scanf("%d %d", &N, &Q);
  for (PW = 1; PW <= N;)
    PW <<= 1;
  for (int i = 1, x; i <= N; i++) {
    scanf("%d", &x);
    for (int b = 0; b < 30; b++)
      tree[i + PW].cnt[b] = x >> b & 1;
  }
  for (int i = PW - 1; i > 0; i--)
    merge(tree[i], tree[i + i], tree[i + i + 1]);
  while (Q--) {
    static int type, x, l, r, p;
    static char op[11];
    scanf("%d", &type);
    if (type == 1) {
      scanf("%d %d", &x, &p);
      update(p, x);
    } else {
      scanf("%s %d %d", op, &l, &r);
      Node res = get(l, r);
      //plnarr(res.cnt, res.cnt + 30);
      const ll all2 = comb2(r - l + 1);
      ll ans = 0;
      for (int b = 0; b < 30; b++) {
        if (op[0] == 'A')
          ans += comb2(res.cnt[b]) * (1 << b);
        else if (op[0] == 'O')
          ans += (all2 - comb2(r - l + 1 - res.cnt[b])) * (1 << b);
        else
          ans += (res.cnt[b] * (r - l + 1LL - res.cnt[b])) * (1 << b);
      }
      printf("%lld\n", ans);
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
  SUMSUM::solve();
  return 0;
}
