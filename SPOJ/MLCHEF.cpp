/* Solved
 * Codechef 2013 September Challenge
 * Merciless Chef
 * File: MLCHEF.cpp
 * Author: Andy Y.F. Huang
 * Created on 2013-09-07, 10:29:51 PM
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

namespace MLCHEF {
template <class T, size_t size> struct FenwickTree {
  T tree[size + 1];

  void init() {
    memset(tree, 0, sizeof(tree));
  }

  void update(int pos, T val) {
    for (int i = pos; i <= (int) size; i += i & -i)
      tree[i] += val;
  }

  T query(int pos) const {
    T ans = 0;
    for (int i = pos; i > 0; i -= i & -i)
      ans += tree[i];
    return ans;
  }
};

#define MAX 100111
vector<int> ch[MAX];
FenwickTree<int, MAX> bit;
int tree[1 << 18], lazy[1 << 18];
int lef[MAX], rig[MAX], val[MAX], inv[MAX];
int L, R, V, CNT = 0;

static int next_time() {
  static int T = 0;
  return T++;
}

void dfs(int at) {
  lef[at] = rig[at] = next_time();
  inv[lef[at]] = at;
  for (int& to : ch[at])
    dfs(to);
  if (!ch[at].empty())
    rig[at] = rig[ch[at].back()];
}

void build(int n, int l, int r) {
  lazy[n] = 0;
  if (l == r)
    tree[n] = val[inv[l]];
  else {
    int mid = (l + r) >> 1;
    build(n + n, l, mid);
    build(n + n + 1, mid + 1, r);
    tree[n] = min(tree[n + n], tree[n + n + 1]);
  }
}

void push(int n) {
  int by = lazy[n];
  lazy[n + n] += by;
  lazy[n + n + 1] += by;
  tree[n + n] -= by;
  tree[n + n + 1] -= by;
  lazy[n] = 0;
}

void update(int n, int l, int r) {
  if (L > r || R < l)
    return;
//pln(l, r, L, R, V);
  if (L <= l && r <= R) {
    tree[n] -= V;
    lazy[n] += V;
  } else {
    push(n);
    int mid = (l + r) >> 1;
    update(n + n, l, mid);
    update(n + n + 1, mid + 1, r);
    tree[n] = min(tree[n + n], tree[n + n + 1]);
  }
}

void erase(int n, int l, int r) {
  if (tree[n] > 0)
    return;
  if (l == r) {
    tree[n] = 1 << 30;
    bit.update(l, -1);
    CNT++;
  } else {
    push(n);
    int mid = (l + r) >> 1;
    erase(n + n, l, mid);
    erase(n + n + 1, mid + 1, r);
    tree[n] = min(tree[n + n], tree[n + n + 1]);
  }
}

void solve(int test_num) {
  int N, Q;
  scanf("%d", &N);
  N++;
  for (int i = 1, p; i < N; i++) {
    scanf("%d %d", val + i, &p);
    ch[p].push_back(i);
  }
  scanf("%d", &Q);
  dfs(0);
  val[0] = 1 << 30;
  build(1, 0, N - 1);
  for (int i = 1; i < N; i++)
    bit.update(i, 1);
  //plnarr(lef, lef + N);
  //plnarr(rig, rig + N);
  for (int q = 0, type, at; q < Q; q++) {
    scanf("%d %d", &type, &at);
    L = lef[at] + 1;
    R = rig[at];
    if (type == 1) {
      scanf("%d", &V);
      update(1, 0, N - 1);
      erase(1, 0, N - 1);
    } else {
      int res = bit.query(R) - bit.query(L - 1);
      printf("%d\n", res);
    }
    assert(CNT <= N);
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
  MLCHEF::solve();
  return 0;
}
