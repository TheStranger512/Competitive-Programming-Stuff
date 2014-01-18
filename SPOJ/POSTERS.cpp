/* Solved
 * 138. Election Posters
 * File:   POSTERS.cpp
 * Author: Andy Y.F. Huang
 * Created on February 18, 2013, 9:05 PM
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

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace POSTERS {

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

#define lch(x) (x<<1)
#define rch(x) ((x<<1)+1)
#define mid ((start+end)>>1)
typedef pair<int, int> Strip;
Indexer<int, 44444 > hasher;
Strip strips[44444];
int tree[444444];
int lazy[444444];
bool covered[44444];
int from, to, val;

void prog(int node, int start, int end) {
  if (lazy[node] < 0) return;
  lazy[lch(node)] = lazy[rch(node)] = lazy[node];
  tree[lch(node)] = tree[rch(node)] = lazy[node];
  lazy[node] = -1;
}

void update(int node, int start, int end) {
  if (from > end || to < start) return;
  if (from <= start && end <= to)
    tree[node] = lazy[node] = val;
  else {
    prog(node, start, end);
    update(lch(node), start, mid);
    update(rch(node), mid + 1, end);
  }
}

void push(int node, int start, int end) {
  if (start == end) {
    if (tree[node] >= 0) covered[tree[node]] = true;
    return;
  }
  prog(node, start, end);
  push(lch(node), start, mid);
  push(rch(node), mid + 1, end);
}

void solve(int test_num) {
  hasher.len = 0;
  int len;
  scanf("%d", &len);
  for (int i = 0; i < len; i++) {
    covered[i] = false;
    scanf("%d %d", &strips[i].first, &strips[i].second);
    hasher.add(strips[i].first);
    hasher.add(strips[i].second);
  }
  hasher.process();
  memset(tree, -1, sizeof (int) * 8 * len);
  memset(lazy, -1, sizeof (int) * 8 * len);
  for (int i = 0; i < len; i++) {
    from = strips[i].first = hasher.get(strips[i].first);
    to = strips[i].second = hasher.get(strips[i].second);
    val = i;
    update(1, 0, hasher.len - 1);
  }
  push(1, 0, hasher.len - 1);
  printf("%d\n", count(covered, covered + len, true));
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
  POSTERS::solve();
  return 0;
}

