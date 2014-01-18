/* Solved
 * 1043. Can you answer these queries I
 * File:   GSS1.cpp
 * Author: Andy Y.F. Huang
 * Created on August 15, 2012, 9:13 PM
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
namespace GSS1 {

struct Node {
  int prefix, suffix, total, subvector;

  void init(int val) {
    prefix = suffix = total = subvector = val;
  }

  Node() {
    total = 0;
    prefix = suffix = subvector = -1243456789;
  }

  Node (const Node & n) {
    prefix = n.prefix;
    suffix = n.suffix;
    total = n.total;
    subvector = n.subvector;
  }
} ;

const int k_max_len = 50010, inf = 123456789;
Node tree[3 * k_max_len];
int aux[k_max_len];

void func(const Node& a, const Node& b, Node& res) {
  res.total = a.total + b.total;
  res.prefix = max(a.prefix, a.total + b.prefix);
  res.suffix = max(a.suffix + b.total, b.suffix);
  res.subvector = max(a.suffix + b.prefix, max(a.subvector, b.subvector));
}

inline int left(int node) {
  return node << 1;
}

inline int right(int node) {
  return (node << 1) + 1;
}

Node query(int node, int start, int end, int qi, int qj) {
  if (qi > end || qj < start)
    return Node();
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
  int len, queries;
  scanf("%d", &len);
  for (int i = 0; i < len; i++)
    scanf("%d", &aux[i]);
  build(1, 0, len - 1);
  scanf("%d", &queries);
  for (int i = 0; i < queries; i++) {
    int start, end;
    scanf("%d %d", &start, &end);
    printf("%d\n", query(1, 0, len - 1, --start, --end).subvector);
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
  GSS1::solve();
  return 0;
}

