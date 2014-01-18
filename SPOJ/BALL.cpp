/* Solved
 * 8391. The Ball
 * File:   BALL.cpp
 * Author: Andy Y.F. Huang
 * Created on March 31, 2013, 10:53 PM
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

namespace BALL {

template <class T, size_t MAXSIZE, class Comp = less<T> > struct Indexer {
  T arr[MAXSIZE];
  int len;

  void add(const T & val) {
    arr[len++] = val;
  }

  void process() {
    sort(arr, arr + len, Comp());
    len = unique(arr, arr + len) - arr;
  }

  int get(const T & val) {
    return lower_bound(arr, arr + len, val, Comp()) - arr;
  }
} ;

template <size_t MAXSIZE> struct Tree {
  //set [L, R], get tree[X]
  #define lch(x) (x<<1)
  #define rch(x) (x<<1|1)
  #define mid ((start+end)>>1)
  int tree[3 * MAXSIZE], lazy[3 * MAXSIZE];
  int size, X, Y, val;

  void init(int size) {
    this->size = size;
    memset(tree, -1, sizeof (int) * 3 * size);
    memset(lazy, -1, sizeof (int) * 3 * size);
  }

  void prog(int node) {
    if (lazy[node] == -1) return;
    tree[lch(node)] = tree[rch(node)] = lazy[node];
    lazy[lch(node)] = lazy[rch(node)] = lazy[node];
    lazy[node] = -1;
  }

  int ask(int pos) {
    int node = 1, start = 0, end = size - 1;
    while (start < end) {
      prog(node);
      if (pos <= mid) {
        node = lch(node);
        end = mid;
      }
      else {
        node = rch(node);
        start = mid + 1;
      }
    }
    return tree[node];
  }

  void update(int from, int to, int val) {
    X = from;
    Y = to;
    this->val = val;
    _update(1, 0, size - 1);
  }

  void _update(int node, int start, int end) {
    if (X > end || Y < start) return;
    if (X <= start && end <= Y) tree[node] = lazy[node] = val;
    else {
      prog(node);
      _update(lch(node), start, mid);
      _update(rch(node), mid + 1, end);
      tree[node] = max(tree[lch(node)], tree[rch(node)]);
    }
  }

} ;

struct Belt {
  int x1, x2, y;

  bool operator<(const Belt & b) const {
    return y < b.y;
  }
} ;
#define MAX 111000
int last[2 * MAX], next[2 * MAX];
//
int dp[MAX], xval[MAX];
Belt belts[MAX];
int len, quests;
Indexer<int, 5 * MAX> vals;
Tree < 5 * MAX> tree;

void solve(int test_num) {
  vals.len = 0;
  scanf("%d", &len);
  for (int i = 0; i < len; i++) {
    scanf("%d %d %d", &belts[i].x1, &belts[i].x2, &belts[i].y);
    vals.add(belts[i].x1);
    vals.add(belts[i].x1 - 1);
    vals.add(belts[i].x2);
    vals.add(belts[i].x2 + 1);
  }
  scanf("%d", &quests);
  for (int q = 0; q < quests; q++) {
    scanf("%d", xval + q);
    vals.add(xval[q]);
  }
  vals.process();
  sort(belts, belts + len);
  //tree.update(0, 2, 5);
  tree.init(vals.len);
  //pln(tree.ask(0));
  for (int i = 0; i < len; i++) {
    int from = vals.get(belts[i].x1);
    int to = vals.get(belts[i].x2);
    int left = tree.ask(from - 1);
    int right = tree.ask(to + 1);
    if (left > -1) dp[i] = dp[left];
    if (right > -1) dp[i] = max(dp[i], dp[right]);
    dp[i]++;
    tree.update(from, to, i);
  }
  //plnarr(dp, dp + len);
  for (int q = 0; q < quests; q++) {
    int pos = tree.ask(vals.get(xval[q]));
    printf("%d\n", pos == -1 ? 0 : dp[pos]);
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
  BALL::solve();
  return 0;
}

