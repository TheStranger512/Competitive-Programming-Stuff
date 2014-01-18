/* Solved
 * 1684. Frequent values
 * File:   FREQUENT.cpp
 * Author: Andy Y.F. Huang
 * Created on August 16, 2012, 11:59 PM
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
namespace FREQUENT {

struct Node {
  int freq, first, last;

  Node() {
    freq = first = last = 0;
  }

  Node(const Node & n) {
    freq = n.freq;
    first = n.first;
    last = n.last;
  }

  void init(int val) {
    freq = first = last = val;
  }

  friend ostream& operator<<(ostream& out, const Node& n) {
    return out << n.freq << "," << n.first << "," << n.last;
  }
} ;

const int k_max_len = 100010;
Node tree[3 * k_max_len], identity;
int aux[k_max_len], len;

inline int max4(int a, int b, int c, int d) {
  return max(max(a, b), max(c, d));
}

void func(const Node& a, const Node& b, Node& res, int i, int j, int c, int d) {
  if (aux[i] == aux[c])
    res.first = a.first + b.first;
  else
    res.first = a.first;
  if (aux[j] == aux[d])
    res.last = a.last + b.last;
  else
    res.last = b.last;
  res.freq = max4(res.first, res.last, a.freq, b.freq);
  if (aux[j] == aux[c])
    res.freq = max(res.freq, a.last + b.first);
  //pln(a, b, res);
  //pln(i, j, c, d);
}

inline int left(int node) {
  return node << 1;
}

inline int right(int node) {
  return (node << 1) + 1;
}

Node query(int node, int start, int end, int qi, int qj) {
  if (qi > end || qj < start)
    return identity;
  if (qi <= start && end <= qj)
    return tree[node];
  else {
    int mid = (start + end) >> 1;
    Node l = query(left(node), start, mid, qi, qj);
    Node r = query(right(node), mid + 1, end, qi, qj);
    if (l.freq != 0 && r.freq != 0) {
      Node res;
      func(l, r, res, start, mid, mid + 1, end);
      return res;
    }
    else if (l.freq != 0)
      return l;
    else
      return r;
  }
}

void build(int node, int start, int end) {
  if (start == end)
    tree[node].init(1);
  else {
    int mid = (start + end) >> 1;
    build(left(node), start, mid);
    build(right(node), mid + 1, end);
    func(tree[left(node)], tree[right(node)], tree[node], start, mid, mid + 1, end);
  }
}

void solve(int test_num) {
  identity.init(0);
  int queries;
  scanf("%d", &queries);
  for (int i = 0; i < len; i++)
    scanf("%d", &aux[i]);
  build(1, 0, len - 1);
  for (int i = 0; i < queries; i++) {
    int start, end;
    scanf("%d %d", &start, &end);
    printf("%d\n", query(1, 0, len - 1, --start, --end).freq);
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (true) {
    scanf("%d", &len);
    if (len == 0)
      break;
    solve(1);
  }
}
}

int main() {
  FREQUENT::solve();
  return 0;
}

