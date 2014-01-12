/*
 * Solved
 * 3267. D-query
 * File:   DQUERY.cpp
 * Author: Andy Y.F. Huang
 * Created on February 16, 2013, 6:44 PM
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
namespace DQUERY {

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

template <class T, size_t size> struct FenwickTree {
  T tree[size + 1];

  void init() {
    memset(tree, 0, sizeof (tree));
  }

  void update(int pos, T val) {
    for (size_t i = pos; i <= size; i += i&-i)
      tree[i] += val;
  }

  T query(int pos) const {
    T ans = 0;
    for (int i = pos; i > 0; i -= i&-i)
      ans += tree[i];
    return ans;
  }

  int lowerbound(T val) {
    int pos = 0, add = 1;
    while (add < size) add <<= 1;
    for (; add > 0; add >>= 1)
      if (pos + add <= size && tree[pos + add] < val)
        val -= tree[pos += add];
    return pos + 1;
  }

} ;

struct Query {
  int start, end, pos;

  bool operator<(const Query& q) const {
    return end < q.end;
  }
};
Indexer<int, 31111 > ranker;
FenwickTree<int, 31111 > tree;
int last[33111], arr[33000];
Query queries[200100]; //[end, start]
int ans[222000];

void solve(int test_num) {
  memset(last, 0, sizeof (last));
  int len;
  scanf("%d", &len);
  for (int i = 1; i <= len; i++) {
    scanf("%d", arr + i);
    ranker.add(arr[i]);
  }
  ranker.process();
  for (int i = 1; i <= len; i++)
    arr[i] = ranker.get(arr[i]);
  int quests;
  scanf("%d", &quests);
  for (int q = 0; q < quests; q++) {
    scanf("%d %d", &queries[q].start, &queries[q].end);
    queries[q].pos = q;
  }
  sort(queries, queries + quests);
  for (int at = 1, q = 0, uni = 0; q < quests; q++) {
    for (; at <= queries[q].end; at++) {
      if (last[arr[at]] > 0)
        tree.update(last[arr[at]], -1);
      else uni++;
      tree.update(at, 1);
      last[arr[at]] = at;
    }
    ans[queries[q].pos] = uni - tree.query(queries[q].start - 1);
  }
  for (int q = 0; q < quests; q++)
    printf("%d\n", ans[q]);
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
  DQUERY::solve();
  return 0;
}

