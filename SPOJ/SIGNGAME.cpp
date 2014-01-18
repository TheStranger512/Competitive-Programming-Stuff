/* Solved
 * 8317. Red Balls
 * File:   SIGNGAME.cpp
 * Author: Andy Y.F. Huang
 * Created on February 15, 2013, 9:25 PM
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
namespace SIGNGAME {

struct Node {
  Node *left, *right;
  int pre, suff, sum, sub;

  Node() {
    fill(0);
  }

  Node(const Node& x) {
    pre = x.pre;
    suff = x.suff;
    sum = x.sum;
    sub = x.sub;
    left = right = NULL;
  }

  void fill(int x) {
    pre = suff = sum = sub = x;
  }

  void f(const Node& a, const Node& b) {
    pre = max(a.pre, a.sum + b.pre);
    suff = max(b.suff, b.sum + a.suff);
    sum = a.sum + b.sum;
    sub = max(max(a.sub, b.sub), a.suff + b.pre);
  }
} ;

#define inf 999888999
#define lch(x) (x<<1)
#define rch(x) ((x<<1)+1)
#define mid ((start + end)>>1)
Node pool[777777], *root1, *root2, null;
int nextnode;
int aux[111111], from, to;

Node* next() {
  return &pool[nextnode++];
}

void build(Node* node, int start, int end) {
  if (start == end) {
    node->fill(aux[start]);
    return;
  }
  node->left = next();
  node->right = next();
  build(node->left, start, mid);
  build(node->right, mid + 1, end);
  node->f(*node->left, *node->right);
}

Node query(Node* node, int start, int end) {
  if (from > end || to < start) return null;
  if (from <= start && end <= to) return *node;
  Node res;
  res.f(query(node->left, start, mid), query(node->right, mid + 1, end));
  return res;
}

void update(Node* a, Node* b, Node* para, Node* parb, int start, int end) {
  if (from > end || to < start) return;
  if (from <= start && end <= to) {
    if (para == NULL) {
      swap(root1, root2);
      return;
    }
    if (para->left == a)
      swap(para->left, parb->left);
    else
      swap(para->right, parb->right);
    return;
  }
  update(a->left, b->left, a, b, start, mid);
  update(a->right, b->right, a, b, mid + 1, end);
  a->f(*a->left, *a->right);
  b->f(*b->left, *b->right);
}

void solve(int test_num) {
  nextnode = 0;
  int len;
  scanf("%d", &len);
  for (int i = 0; i < len; i++)
    scanf("%d", aux + i);
  root1 = next();
  root2 = next();
  build(root1, 0, len - 1);
  for (int i = 0; i < len; i++)
    aux[i] = -aux[i];
  build(root2, 0, len - 1);
  int quests;
  scanf("%d", &quests);
  for (int q = 0; q < quests; q++) {
    int type;
    scanf("%d %d %d", &type, &from, &to);
    if (type == 0)
      update(root1, root2, NULL, NULL, 0, len - 1);
    else
      printf("%d\n", query(root1, 0, len - 1).sub);
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  null.fill(-inf);
  null.sum = 0;
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  SIGNGAME::solve();
  return 0;
}

