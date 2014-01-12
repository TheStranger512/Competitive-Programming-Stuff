/* Solved
 * 4487. Can you answer these queries VI
 * File:   GSS6.cpp
 * Author: Andy Y.F. Huang
 * Created on May 3, 2013, 12:43 AM
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

namespace GSS6 {
#define INF (1<<30)

struct Data {
  int pre, end, sub, total;

  Data() : pre(-INF), end(-INF), sub(-INF), total(0) { }

  Data(int x) : pre(x), end(x), sub(x), total(x) { }

  void operator()(const Data& l, const Data & r) {
    static Data x;
    x.pre = max(l.pre, l.total + r.pre);
    x.end = max(r.end, r.total + l.end);
    x.total = l.total + r.total;
    x.sub = max(l.end + r.pre, max(l.sub, r.sub));
    memcpy(this, &x, sizeof (Data));
  }

  friend ostream& operator<<(ostream& out, const Data & x) {
    return out << '(' << x.pre << ',' << x.end << ',' << x.sub << ',' << x.total << ')';
  }

} ;

static const Data NIL;

struct Node {
  Data data;
  int pri, cnt, val;
  Node* left, *right;

  void update() {
    cnt = (left ? left->cnt : 0) + (right ? right->cnt : 0) + 1;
    data = NIL;
    if (left) data(data, left->data);
    data(data, val);
    if (right) data(data, right->data);
  }

  int rank() const {
    return left ? left->cnt + 1 : 1;
  }

} ;

Node pool[222000], *ptr, *root;

void init() {
  srand(time(NULL));
  ptr = pool;
  root = NULL;
}

Node* rotate_left(Node* at) {
  Node* temp = at->right;
  at->right = temp->left;
  temp->left = at;
  at->update();
  return temp;
}

Node* rotate_right(Node* at) {
  Node* temp = at->left;
  at->left = temp->right;
  temp->right = at;
  at->update();
  return temp;
}

Node* make(int val) {
  ptr->cnt = 1;
  ptr->left = ptr->right = NULL;
  ptr->pri = rand();
  ptr->val = val;
  ptr->data = Data(val);
  return ptr++;
}

void replace(Node* at, int pos, int val) {
  if (at->rank() == pos)
    at->val = val;
  else if (pos < at->rank())
    replace(at->left, pos, val);
  else
    replace(at->right, pos - at->rank(), val);
  at->update();
}

void replace(int pos, int val) {
  replace(root, pos, val);
}

Node* insert(Node* at, int pos, int val) {
  if (!at)
    return make(val);
  if (pos <= at->rank()) {
    at->left = insert(at->left, pos, val);
    if (at->left->pri < at->pri)
      at = rotate_right(at);
  }
  else {
    at->right = insert(at->right, pos - at->rank(), val);
    if (at->right->pri < at->pri)
      at = rotate_left(at);
  }
  at->update();
  return at;
}

void insert(int pos, int val) {
  root = insert(root, pos, val);
}

Node* erase(Node* at, int pos) {
  if (!at) return NULL;
  if (pos < at->rank())
    at->left = erase(at->left, pos);
  else if (pos > at->rank())
    at->right = erase(at->right, pos - at->rank());
  else {
    if (at->left == NULL) return at->right;
    if (at->right == NULL) return at->left;
    if (at->left->pri < at->right->pri) {
      Node* temp = rotate_right(at);
      temp->right = erase(at, at->rank());
      at = temp;
    }
    else {
      Node* temp = rotate_left(at);
      temp->left = erase(at, at->rank());
      at = temp;
    }
  }
  at->update();
  return at;
}

void erase(int pos) {
  root = erase(root, pos);
}

Data query(Node* at, int L, int R) {
  if (!at || L > at->cnt || R < 1) return NIL;
  if (L <= 1 && at->cnt <= R) return at->data;
  Data res;
  if (L <= at->rank() && at->rank() <= R)
    res = at->val;
  res(query(at->left, L, min(R, at->rank() - 1)), res);
  res(res, query(at->right, max(L - at->rank(), 1), R - at->rank()));
  return res;
}

#ifdef AZN

void inorder(Node* at) {
  if (!at) return;
  inorder(at->left);
  pf(at->data), pf(','), pf(at->val), pf(','), pf(at->cnt), pf(' ');
  inorder(at->right);
}

void inorder() {
  inorder(root);
  pln();
}

#endif

void solve(int test_num) {
  init();
  int len, quests;
  scanf("%d", &len);
  for (int i = 1, x; i <= len; i++) {
    scanf("%d", &x);
    insert(i, x);
    //inorder();
  }
  scanf("%d", &quests);
  //pln(quests);
  for (int q = 0, x, y; q < quests; q++) {
    char type;
    scanf(" %c %d", &type, &x);
    if (type == 'D')
      erase(x);
    else {
      scanf("%d", &y);
      if (type == 'I')
        insert(x, y);
      else if (type == 'R')
        replace(x, y);
      else {
        Data res = query(root, x, y);
        printf("%d\n", res.sub);
      }
    }
    //inorder();
  }
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
  GSS6::solve();
  return 0;
}

