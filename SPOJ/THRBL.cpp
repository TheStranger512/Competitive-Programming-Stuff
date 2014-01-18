/* Solved
 * 8952. Catapult that ball - rmq
 * File:   THRBL.cpp
 * Author: Andy Huang
 * Created on June 8, 2012, 11:26 PM
 */

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <fstream>
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#define pln(x) println(x)
#define pf(x) print(x)
#define plnarr(i, j) println(i, j)
#endif

template<typename Type, typename Associative_Functor> struct SegmentTree {
private:
  typedef const Type * const const_array;
  typedef const Type& const_ref;
  typedef const int& pos_t;

  int len;
  Type* tree;
  Type null;
  Associative_Functor function;

  inline const int leftchild(pos_t node) const {
    return node << 1;
  }

  inline const int rightchild(pos_t node) const {
    return (node << 1) + 1;
  }

  void build(pos_t node, pos_t begin, pos_t end, const_array array) {
    if (begin == end) {
      tree[node] = array[begin];
      return;
    }
    int mid = (begin + end) >> 1;
    build(leftchild(node), begin, mid, array);
    build(rightchild(node), mid + 1, end, array);
    tree[node] = function(tree[leftchild(node)], tree[rightchild(node)]);
  }

  Type query(pos_t node, pos_t begin, pos_t end, pos_t i, pos_t j) const {
    if (i > end || j < begin)
      return null;
    else if (i <= begin && end <= j)
      return tree[node];
    int mid = (begin + end) >> 1;
    int left = query(leftchild(node), begin, mid, i, j);
    int right = query(rightchild(node), mid + 1, end, i, j);
    return function(left, right);
  }

public:

  SegmentTree() {
  }

  void init(const_array array, const int& len, const_ref nullvalue) {
    this->len = len;
    null = nullvalue;
    tree = new Type[len << 2];
    build(1, 0, len - 1, array);
  }

  ~SegmentTree() {
    delete []tree;
  }

  Type query(const int& from, const int& to) const {
    return query(1, 0, len - 1, from, to);
  }

} ;

using namespace std;

#define max_len 50050
#define neginf -1337

struct greaterint{
  int operator()(const int& a, const int& b) const {
    return a > b ? a : b;
  }
};

int array[max_len];

void solve() {
  int len, queries;
  scanf("%d %d", &len, &queries);
  SegmentTree<int, greaterint> segtree;
  for (int i = 0; i < len; i++) 
    scanf("%d", &array[i]);
  segtree.init(array, len, neginf);
  int ans = 0;
  while (queries--) {
    int start, end;
    scanf("%d %d", &start, &end);
    start--;
    end--;
    ans += segtree.query(start + 1, end - 1) <= array[start];
  }
  printf("%d\n", ans);
}

int main() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve();
  return 0;
}

