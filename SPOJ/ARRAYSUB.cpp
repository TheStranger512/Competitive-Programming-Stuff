/* Solved
 * 10582. subarrays - segment tree
 * File:   ARRAYSUB.cpp
 * Author: Andy Huang
 * Created on May 26, 2012, 10:51 AM
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

struct SegmentTree {
private:
  int len;
  int* tree;
  static const int null = -1;
public:

  SegmentTree(const int * const array, const int& len) {
    this->len = len;
    tree = new int[len << 2];
    build(1, 0, len - 1, array);
    //pln(Arrays::toString(tree, len << 2));
  }

  ~SegmentTree() {
    delete []tree;
  }

  const int & funct(const int& a, const int & b)const;

  int query(const int& i, const int& j) {
    return query(1, 0, len - 1, i, j);
  }

private:

  void build(const int& node, const int& begin, const int& end, const int * const array) {
    if (begin == end) {
      tree[node] = array[begin];
      return;
    }
    int mid = (begin + end) >> 1;
    build(node << 1, begin, mid, array);
    build((node << 1) + 1, mid + 1, end, array);
    tree[node] = funct(tree[node << 1], tree[(node << 1) + 1]);
  }

  int query(const int& node, const int& begin, const int& end, const int& i, const int& j) {
    if (i > end || j < begin)
      return null;
    else if (i <= begin && end <= j) {
      return tree[node];
    }
    int mid = (begin + end) >> 1;
    int leftchild = node << 1;
    int rightchild = (node << 1) + 1;
    int left = query(leftchild, begin, mid, i, j);
    int right = query(rightchild, mid + 1, end, i, j);
    return funct(left, right);
  }

};

using namespace std;

const int& SegmentTree::funct(const int& a, const int& b) const{
  return a >= b ? a : b;
}

int array[100050];

void solve() {
  int len, k;
  scanf("%d", &len);
  for (int i = 0; i < len; i++)
    scanf("%d", &array[i]);
  scanf("%d", &k);
  SegmentTree segtree(array, len);
  for (int i = 0; i <= len - k; i++)
    printf("%d ", segtree.query(i, i + k - 1));
  puts("");
}

int main() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve();
  return 0;
}

