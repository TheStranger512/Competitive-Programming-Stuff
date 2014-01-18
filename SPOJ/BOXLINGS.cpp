/* Solved
 * 14848. Boxlings
 * File:   BOXLINGS.cpp
 * Author: Andy Y.F. Huang
 * Created on May 11, 2013, 10:10 PM
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

namespace BOXLINGS {

struct Point {
  int x, y;

  Point(int x, int y) : x(x), y(y) { }

  Point() : x(0), y(0) { }

  bool operator<(const Point & p) const {
    return x < p.x;
  }

  friend ostream& operator<<(ostream& out, const Point & p) {
    return out << '(' << p.x << ',' << p.y << ')';
  }
} ;

struct Rect {
  Point botleft, upright;

  friend ostream& operator<<(ostream& out, const Rect & r) {
    return out << '{' << r.botleft << ':' << r.upright << '}';
  }

  void check() {
    if (botleft.x > upright.x)
      swap(botleft.x, upright.x);
    if (botleft.y > upright.y)
      swap(botleft.y, upright.y);
  }

} ;

//int* alloc(int size) {
//  static int pool[1 << 22], *ptr = pool;
//  ptr += size;
//  #ifdef AZN
//  //pln("Allocating size of:", size, "ending at", ptr - pool);
//  #endif
//  return ptr - size;
//}

#define left(x) (x << 1)
#define right(x) ((x << 1)+1)
#define mid_ ((start + end) >> 1)

struct RangeTree2D {

  struct CompareY {
    const Point* pts;

    bool operator()(int a, int b) const {
      return pts[a].y < pts[b].y;
    }

    CompareY(const Point * pts) {
      this-> pts = pts;
    }

  } ;

  struct Node {
    int* yorder, *lbridge, *rbridge;
    int length;

    void createleaf(const Point* pts, int start, int end) {
      length = end - start + 1;
      yorder = new int[length];
      lbridge = new int[length + 1];
      rbridge = new int[length + 1];
      // yorder = alloc(length);
      // lbridge = alloc(length + 1);
      // rbridge = alloc(length + 1);
      //lbridge = rbridge = NULL;
      for (int i = 0, j = start; i < length; i++, j++)
        yorder[i] = j;
      sort(yorder, yorder + length, CompareY(pts));
    }

    void mergefrom(const Point* pts, const Node& left, const Node & right) {
      //pln(left, right);
      length = left.length + right.length;
      yorder = new int[length];
      lbridge = new int[length + 1];
      rbridge = new int[length + 1];
      // yorder = alloc(length);
      // lbridge = alloc(length + 1);
      // rbridge = alloc(length + 1);
      for (int i = 0, p = 0, q = 0; i < length; i++) {
        if (q >= right.length || (p < left.length && pts[left.yorder[p]].y <= pts[right.yorder[q]].y)) {
          yorder[i] = left.yorder[p];
          lbridge[i] = p++;
          rbridge[i] = q;
        }
        else {
          yorder[i] = right.yorder[q];
          lbridge[i] = p;
          rbridge[i] = q++;
        }
      }
      lbridge[length] = left.length;
      rbridge[length] = right.length;
    }

    int lowerbound(const Point* pts, int val) const {
      int ans = length;
      for (int low = 0, high = length - 1; low <= high; ) {
        int mid = (low + high) >> 1;
        if (pts[yorder[mid]].y >= val)
          high = mid - 1, ans = min(ans, mid);
        else low = mid + 1;
      }
      return ans;
    }

    int upperbound(const Point* pts, int val) const {
      int ans = -1;
      for (int low = 0, high = length - 1; low <= high; ) {
        int mid = (low + high) >> 1;
        if (pts[yorder[mid]].y <= val)
          low = mid + 1, ans = max(ans, mid);
        else high = mid - 1;
      }
      return ans + 1;
    }

    int report(const Point* pts, int y1, int y2) const {
      int st = lowerbound(pts, y1), ed = upperbound(pts, y2);
      //pln("right:", st, ed, ed - st);
//      for (int i = st; i < ed; i++)
//        covered[yorder[i]] = true;
      return ed - st;
    }

    // int operator[](int pos) const {
    // return yorder[pos];
    // }

    // friend ostream& operator<<(ostream& out, const Node & n) {
    // out << '[';
    // for (int i = 0; i < n.length; i++) {
    // if (i) out << ',';
    // out << n.yorder[i];
    // }
    // return out << ']';
    // }

  } ;
  Node tree[666000];
  const Point* pts;
  bool covered[222000];
  Point a, b;
  int size;

  // inline int left(int node) {
  // return node << 1;
  // }
  //
  // inline int right(int node) {
  // return (node << 1) + 1;
  // }

  void build(Point* pts, int size) {
    this->pts = pts;
    this->size = size;
    build(1, 0, size - 1);
  }

  void build(int node, int start, int end) {
    if (start == end || pts[start].x == pts[end].x)
      tree[node].createleaf(pts, start, end);
    else {
      //int mid = (start + end) >> 1;
      build(left(node), start, mid_);
      build(right(node), mid_ + 1, end);
      tree[node].mergefrom(pts, tree[left(node)], tree[right(node)]);
    }
    //pln(tree[node]);
  }

  int query(Point& a, Point & b) {
    //pln("Querying", a, b);
    this->a = a;
    this->b = b;
    int from = tree[1].lowerbound(pts, a.y);
    int to = tree[1].lowerbound(pts, b.y + 1);
    return query(1, 0, size - 1, from, to);
  }

  int query(int node, int start, int end, int from, int to) {
    if (a.x > pts[end].x || b.x < pts[start].x)
      return 0;
    if (a.x <= pts[start].x && pts[end].x <= b.x) {
      //pln("mine:", from, to, to - from);
      tree[node].report(pts, a.y, b.y);
      for (int i = from; i < to; i++)
        covered[tree[node].yorder[i]] = true;
      return to - from;
    }
    else {
      //int mid = (start + end) >> 1;
      return query(left(node), start, mid_, tree[node].lbridge[from], tree[node].lbridge[to]) +
              query(right(node), mid_ + 1, end, tree[node].rbridge[from], tree[node].rbridge[to]);
    }
  }

} ;

RangeTree2D tree;
Point pts[200222];
Rect boxen[200222];

void solve(int test_num) {
  int boxencnt, ptcnt;
  scanf("%d %d", &boxencnt, &ptcnt);
  for (int i = 0; i < boxencnt; i++) {
    scanf("%d %d %d %d", &boxen[i].botleft.x, &boxen[i].botleft.y, &boxen[i].upright.x, &boxen[i].upright.y);
    boxen[i].check();
  }
  for (int i = 0; i < ptcnt; i++)
    scanf("%d %d", &pts[i].x, &pts[i].y);
  sort(pts, pts + ptcnt);
  //plnarr(pts, pts + ptcnt);
  //plnarr(boxen, boxen + boxencnt);
  tree.build(pts, ptcnt);
  for (int i = 0; i < boxencnt; i++)
    tree.query(boxen[i].botleft, boxen[i].upright);
  int res = 0;
  for (int i = 0; i < ptcnt; i++)
    res += tree.covered[i];
  //plnarr(tree.covered, tree.covered + ptcnt);
  printf("%d\n", res);
}

void solve() {
  #ifdef AZN
  freopen("azn.txt", "w", stderr);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve(1);
}
}

int main() {
  BOXLINGS::solve();
  return 0;
}

