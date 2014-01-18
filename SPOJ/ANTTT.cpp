/* Solved
 * 4465. The Ant
 * File:   ANTTT.cpp
 * Author: Andy Y.F. Huang
 * Created on August 30, 2012, 12:21 AM
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
#include <fstream>
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace ANTTT {

class DisjointSet {
  int* tree;
  int size;
public:

  DisjointSet(int size) : size(size) {
    tree = new int[size];
    memset(tree, 0xFF, sizeof (tree) * size);
  }

  ~DisjointSet() {
    delete [] tree;
  }

  void unite(int root1, int root2) {
    if (root1 == root2)
      return;
    if (tree[root1] > tree[root2])
      tree[root1] = root2;
    else {
      if (tree[root1] == tree[root2])
        tree[root1]--;
      tree[root2] = root1;
    }
  }

  int find(int node) {
    return tree[node] < 0 ? node : (tree[node] = find(tree[node]));
  }
} ;

struct Point {
  int x, y;

  friend ostream& operator<<(ostream& out, const Point * p) {
    return out << '(' << p->x << ',' << p->y << ')';
  }

} ;

struct Vector {
  const int dx, dy;

  Vector(const Point* a, const Point * b) : dx(b->x - a->x), dy(b->y - a->y) { }

  int cross(const Vector & v) const {
    return dx * v.dy - dy * v.dx;
  }

  friend ostream& operator<<(ostream& out, const Vector & v) {
    return out << "Vector: (" << v.dx << ',' << v.dy << ')';
  }
} ;

struct Segment {
  const Point *a, *b;

  Segment(const Point & a, const Point & b) : a(&a), b(&b) { }

  Segment() : a(NULL), b(NULL) { }

  bool intersects(const Segment & s) const {
    //pln(a, b, s.a, s.b);
    Vector u(a, b), v(s.a, s.b), p(a, s.a), q(a, s.b), m(s.a, a), n(s.a, b);
    //pln(u, p, q);
    int up = signum(u.cross(p)), uq = signum(u.cross(q));
    int vm = signum(v.cross(m)), vn = signum(v.cross(n));
    //colinear segments - check intersection of bounded rectangle
    if (up == uq && up == 0) {
      pair<int,int> left, right;
      if (a->x < b->x)
        left.first = a->x, left.second = b->x;
      else
        left.first = b->x, left.second = a->x;
      if (s.a->x < s.b->x)
        right.first = s.a->x, right.second = s.b->x;
      else
        right.first = s.b->x, right.second = s.a->x;
      return signum(min(left.second, right.second)
              - max(left.first, right.first)) >= 0;
    }
    return (up != uq && vm != vn);
  }

  inline int signum(int num) const {
    return (num > 0) - (num < 0);
  }
} ;

Segment segs[1010];
Point pts[2010];

void solve(int test_num) {
  int sticks, queries;
  scanf("%d %d", &sticks, &queries);
  DisjointSet dsu(sticks);
  for (int i = 0; i < sticks; i++) {
    scanf("%d %d %d %d", &pts[i].x, &pts[i].y,
          &pts[i + sticks].x, &pts[i + sticks].y);
    segs[i].a = &pts[i];
    segs[i].b = &pts[i + sticks];
  }
  for (int i = 0; i < sticks; i++)
    for (int j = i + 1; j < sticks; j++)
      if (segs[i].intersects(segs[j]))
        dsu.unite(dsu.find(i), dsu.find(j));
  for (int i = 0; i < queries; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    puts(dsu.find(--a) == dsu.find(--b) ? "YES" : "NO");
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  ANTTT::solve();
  return 0;
}

