/* Solved
 * 2916. Can you answer these queries V
 * File:   GSS5.cpp
 * Author: Andy Y.F. Huang
 * Created on December 7, 2012, 6:32 PM
 */

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <set>
#include <numeric>
#include <map>
#include <sstream>
#include <deque>
#include <iomanip>
#include <cassert>
#include <ctime>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace GSS5 {

struct Node {
  int pre, suff, total, sub;

  void fill(int val) {
    pre = suff = total = sub = val;
  }
} ;

#define inf (1 << 29)
#define lim (1 << 14)
Node tree[1 << 15];
int arr[11111], len;
int sum[11111];
int rmax[44444];
int rmin[44444];
int from, to;
Node identity;

inline int max(int a, int b) {
  return a > b ? a : b;
}

inline int min(int a, int b) {
  return a < b ? a : b;
}

Node func(const Node& a, const Node& b) {
  Node ans;
  ans.total = a.total + b.total;
  ans.pre = max(a.pre, a.total + b.pre);
  ans.suff = max(b.suff, b.total + a.suff);
  ans.sub = max(a.suff + b.pre, max(a.sub, b.sub));
  return ans;
}

void init(int node, int start, int end) {
  if (start == end) tree[node].fill(arr[start]);
  else {
    int mid = (start + end) >> 1;
    init(node + node, start, mid);
    init(node + node + 1, mid + 1, end);
    tree[node] = func(tree[node + node], tree[node + node + 1]);
  }
}

Node query(int node, int start, int end) {
  if (from > end || to < start)
    return identity;
  if (from <= start && end <= to)
    return tree[node];
  int mid = (start + end) >> 1;
  return func(query(node + node, start, mid), query(node + node + 1, mid + 1, end));
}

template <class Func> void initrmq(int* tree, Func f) {
  for (int i = 0; i <= len; i++)
    tree[i + lim] = sum[i];
  for (int i = lim - 1; i > 0; i--)
    tree[i] = f(tree[i + i], tree[i + i + 1]);
}

template <class Func> int queryrmq(int* tree, Func f, int left, int right, int null) {
  int ans = null;
  for (int l = left + lim, r = right + lim + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ans = f(ans, tree[l++]);
    if (r & 1) ans = f(ans, tree[--r]);
  }
  return ans;
}

int rmqmax(int left, int right) {
  return queryrmq(rmax, max, left, right, -inf);
}

int rmqmin(int left, int right) {
  return queryrmq(rmin, min, left, right, inf);
}

void solve(int test_num) {
  scanf("%d", &len);
  for (int i = 1; i <= len; i++)
    scanf("%d", arr + i);
  partial_sum(arr, arr + len + 1, sum);
  init(1, 1, len);
  memset(rmax, 0xF0, sizeof (rmax));
  memset(rmin, 0x3F, sizeof (rmin));
  initrmq(rmax, max);
  initrmq(rmin, min);
  int quests;
  scanf("%d", &quests);
  for (int q = 0; q < quests; q++) {
    int i, j, k, l;
    scanf("%d %d %d %d", &i, &j, &k, &l);
    if (j <= k)
      printf("%d\n", rmqmax(k, l) - rmqmin(i - 1, j - 1));
    else {
      int ans = rmqmax(k, l) - rmqmin(i - 1, k - 1);
      ans = max(ans, rmqmax(j, l) - rmqmin(k, j - 1));
      from = k + 1;
      to = j;
      ans = max(ans, query(1, 1, len).sub);
      printf("%d\n", ans);
    }
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  identity.fill(-inf);
  identity.total = 0;
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  GSS5::solve();
  return 0;
}

