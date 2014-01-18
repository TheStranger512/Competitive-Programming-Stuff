/* Solved
 * 1716. Can you answer these queries III
 * File:   GSS3.cpp
 * Author: Andy Y.F. Huang
 * Created on August 15, 2012, 11:13 PM
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
namespace GSS3 {

struct Node {
  int prefix, suffix, total, subvector;

  Node() {
    total = 0;
    prefix = suffix = subvector = -123456789;
  }

  Node(const Node & n) {
    total = n.total;
    prefix = n.prefix;
    suffix = n.suffix;
    subvector = n.subvector;
  }

  void init(int val) {
    prefix = suffix = total = subvector = val;
  }
} ;

const int k_max_len = 50010;
Node tree[3 * k_max_len], identity;
int aux[k_max_len];

inline void func(const Node& a, const Node& b, Node& res) {
  res.prefix = max(a.prefix, a.total + b.prefix);
  res.suffix = max(a.suffix + b.total, b.suffix);
  res.total = a.total + b.total;
  res.subvector = max(max(a.subvector, b.subvector), a.suffix + b.prefix);
}

inline int left(int node) {
  return node << 1;
}

inline int right(int node) {
  return (node << 1) + 1;
}

void update(int node, int start, int end, int pos) {
  if (start == end)
    tree[node].init(aux[pos]);
  else {
    int mid = (start + end) >> 1;
    if (pos <= mid)
      update(left(node), start, mid, pos);
    else
      update(right(node), mid + 1, end, pos);
    func(tree[left(node)], tree[right(node)], tree[node]);
  }
}

Node query(int node, int start, int end, int qi, int qj) {
  if (qi > end || qj < start)
    return identity;
  if (qi <= start && end <= qj)
    return Node(tree[node]);
  else {
    int mid = (start + end) >> 1;
    Node l = query(left(node), start, mid, qi, qj);
    Node r = query(right(node), mid + 1, end, qi, qj);
    Node ans;
    func(l, r, ans);
    return ans;
  }
}

void build(int node, int start, int end) {
  if (start == end)
    tree[node].init(aux[start]);
  else {
    int mid = (start + end) >> 1;
    build(left(node), start, mid);
    build(right(node), mid + 1, end);
    func(tree[left(node)], tree[right(node)], tree[node]);
  }
}

void solve(int test_num) {
  int len, ops;
  scanf("%d", &len);
  for (int i = 0; i < len; i++)
    scanf("%d", &aux[i]);
  build(1, 0, len - 1);
  scanf("%d", &ops);
  while (ops--) {
    int type, x, y;
    scanf("%d %d %d", &type, &x, &y);
    if (type == 0) {
      aux[--x] = y;
      update(1, 0, len - 1, x);
    }
    else
      printf("%d\n", query(1, 0, len - 1, --x, --y).subvector);
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve(1);
}
}

int main() {
  GSS3::solve();
  return 0;
}

