/* Solved
 * 3693. Maximum Sum - segment tree
 * File:   KGSS.cpp
 * Author: Andy Huang
 * Created on May 25, 2012, 12:31 AM
 */

#include <stdio.h>
#include <iostream>
#include <math.h>
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

#ifdef AZN
#include "Azn.cpp"
#define pln(x) println(x)
#define pf(x) print(x);
#endif

using namespace std;

struct Point {
  int x;
  int y;

  Point(int x, int y) : x(x), y(y) {
  }

  Point() : x(0), y(0) {
  }

};

struct SegmentTree {
private:
  int len;
  Point* tree;
public:

  SegmentTree(const int * const array, const int& len) {
    this->len = len;
    tree = new Point[len << 2];
    build(1, 0, len - 1, array);
    //pln(Arrays::toString(tree, len << 2));
  }

  ~SegmentTree() {
    delete []tree;
  }

  Point funct(const Point& a, const Point & b)const;

  Point query(const int& i, const int& j) {
    return query(1, 0, len - 1, i, j);
  }

  void update(const int& pos, const int & val) {
    update(1, 0, len - 1, pos, val);
  }

private:

  void build(const int& node, const int& begin, const int& end, const int * const array) {
    if (begin == end) {
      tree[node] = Point(array[begin], 0);
      return;
    }
    int mid = (begin + end) >> 1;
    build(node << 1, begin, mid, array);
    build((node << 1) + 1, mid + 1, end, array);
    tree[node] = funct(tree[node << 1], tree[(node << 1) + 1]);
  }

  Point query(const int& node, const int& begin, const int& end, const int& i, const int& j) const {
    if (i > end || j < begin)
      return Point();
    else if (i <= begin && end <= j) {
      return tree[node];
    }
    int mid = (begin + end) >> 1;
    Point left = query(node << 1, begin, mid, i, j);
    Point right = query((node << 1) + 1, mid + 1, end, i, j);
    return funct(left, right);
  }

  void update(const int& node, const int& begin, const int& end,
          const int& pos, const int & val) {
    if (begin == end) {
      tree[node] = Point(val, 0);
      return;
    }
    int mid = (begin + end) >> 1;
    int leftchild = node << 1;
    int rightchild = (node << 1) + 1;
    if (pos <= mid)
      update(leftchild, begin, mid, pos, val);
    else
      update(rightchild, mid + 1, end, pos, val);
    tree[node] = funct(tree[leftchild], tree[rightchild]);
  }

};

Point SegmentTree::funct(const Point& a, const Point& b) const {
  int temp[4];
  temp[0] = a.x;
  temp[1] = a.y;
  temp[2] = b.x;
  temp[3] = b.y;
  sort(temp, temp + 4);
  return Point(temp[2], temp[3]);
}

int array[100050];

void solve() {
  int len, operations;
  scanf("%d", &len);
  for (int i = 0; i < len; i++)
    scanf("%d", &array[i]);
  SegmentTree segtree(array, len);
  scanf("%d", &operations);
  while (operations--) {
    char str[5];
    scanf("%s", str);
    if (str[0] == 'U') {
      int pos, val;
      scanf("%d %d", &pos, &val);
      segtree.update(pos - 1, val);
    }
    else {
      int i, j;
      scanf("%d %d", &i, &j);
      Point ans = segtree.query(i - 1, j - 1);
      printf("%d\n", ans.x + ans.y);
    }
  }
}

int main() {
  #ifdef AZN
  freopen("C:\\Users\\Windows\\Documents\\Compsci\\SPOJ\\Kurukshetra 09 OPC\\query\\query1.in", "r", stdin);
  //freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve();
  return 0;
}

