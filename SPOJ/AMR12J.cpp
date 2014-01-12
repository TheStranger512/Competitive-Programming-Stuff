/*
 * Solved
 * 13048. Escape from the Mines
 * File:   AMR12J.cpp
 * Author: Andy Y.F. Huang
 * Created on January 25, 2013, 6:07 PM
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
namespace AMR12J {
#define size 222222

/**
 * update: l, r, val - set max [l, r] to val
 * query: l, r get max[l, r]
 */
struct Tree {
  //lch - left child, rch - right child
  #define lch(x) (x + x)
  #define rch(x) (x + x + 1)
  #define mid(l, r) ((l + r) >> 1)
  int lazy[3 * size], tree[3 * size];
  int from, to, val, len;

  void init(int len) {
    memset(lazy, 0xF0, sizeof (lazy));
    memset(tree, -1, sizeof (tree));
    this->len = len;
  }

  void update(int from, int to, int val) {
    this->from = from;
    this->to = to;
    this->val = val;
    _update(1, 0, len - 1);
  }

  int query(int from, int to) {
    this->from = from;
    this->to = to;
    return query(1, 0, len - 1);
  }

private:

  void prog(int node) {
    if (lazy[node] < -1) return;
    lazy[lch(node)] = lazy[rch(node)] = lazy[node];
    tree[lch(node)] = tree[rch(node)] = lazy[node];
    lazy[node] = -12345;
  }

  void _update(int node, int start, int end) {
    if (from > end || to < start) return;
    if (from <= start && end <= to) {
      tree[node] = val;
      lazy[node] = val;
      return;
    }
    prog(node);
    _update(lch(node), start, mid(start, end));
    _update(rch(node), mid(start, end) + 1, end);
    tree[node] = max(tree[lch(node)], tree[rch(node)]);
  }

  int query(int node, int start, int end) {
    if (from > end || to < start) return -12345;
    if (from <= start && end <= to) return tree[node];
    prog(node);
    return max(query(lch(node), start, mid(start, end)),
               query(rch(node), mid(start, end) + 1, end));
  }

} ;

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

struct Room {
  int x1, y1, x2, y2, pos;

  bool operator<(const Room & r) const {
    return x1 < r.x1;
  }
} ;

struct Cmp {
  bool operator()(int a, int b) const;
} ;

Tree rmq;
Indexer<int, size> comp;
int ans[size >> 1];
Room rooms[size >> 1];
priority_queue<int, vector<int>, Cmp> heap;

bool Cmp::operator ()(int a, int b) const {
  return rooms[a].x2 > rooms[b].x2;
}

void solve(int test_num) {
  int len;
  scanf("%d", &len);
  for (int i = 0; i < len; i++) {
    scanf("%d %d %d %d", &rooms[i].x1, &rooms[i].y1, &rooms[i].x2, &rooms[i].y2);
    rooms[i].pos = i;
    comp.add(rooms[i].y1);
    comp.add(rooms[i].y2);
  }
  sort(rooms, rooms + len);
  comp.process();
  rmq.init(comp.len);
  for (int i = 0; i < len; i++) {
    rooms[i].y1 = comp.get(rooms[i].y1);
    rooms[i].y2 = comp.get(rooms[i].y2);
    while (!heap.empty() && rooms[heap.top()].x2 <= rooms[i].x1) {
      int done = heap.top();
      rmq.update(rooms[done].y1, rooms[done].y2, ans[rooms[done].pos]);
      heap.pop();
    }
    ans[rooms[i].pos] = rmq.query(rooms[i].y1, rooms[i].y2);
    rmq.update(rooms[i].y1, rooms[i].y2, i);
    heap.push(i);
  }
  for (int i = 0; i < len; i++)
    printf("%d\n", ans[i] == -1 ? -1 : rooms[ans[i]].pos);
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
  AMR12J::solve();
  return 0;
}

