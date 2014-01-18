/* Solved
 * 4350. Giá trị lớn nhất 3
 * File:   QMAX3VN__treap.cpp
 * Author: Andy Y.F. Huang
 * Created on May 2, 2013, 11:42 PM
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

namespace QMAX3VN__treap {
#define NIL -(1<<30)

struct Node {
  int val, high;
  int pri, cnt;
  Node *left, *right;

  void update() {
    high = max(val, max(leftmax(), rightmax()));
    cnt = leftcnt() + rightcnt() + 1;
  }

  int rank() {
    return leftcnt() + 1;
  }

  int leftcnt() {
    return left ? left->cnt : 0;
  }

  int rightcnt() {
    return right ? right->cnt : 0;
  }

  int leftmax() {
    return left ? left->high : NIL;
  }

  int rightmax() {
    return right ? right->high : NIL;
  }
} ;

Node pool[111000], *ptr;
Node *root;

void init() {
  srand(time(NULL));
  ptr = pool;
  root = NULL;
}

Node * make(int val) {
  ptr->val = ptr->high = val;
  ptr->cnt = 1;
  ptr->pri = rand();
  ptr->left = ptr->right = NULL;
  return ptr++;
}

Node * rotateRight(Node * node) {
  Node *temp = node->left;
  node->left = temp->right;
  temp->right = node;
  node->update();
  return temp;
}

Node * rotateLeft(Node * node) {
  Node *temp = node->right;
  node->right = temp->left;
  temp->left = node;
  node->update();
  return temp;
}

Node * insert(Node *at, int val, int pos) {
  if (!at)
    return make(val);
  else if (pos <= at->rank()) {
    at->left = insert(at->left, val, pos);
    if (at->left->pri < at->pri)
      at = rotateRight(at);
  }
  else {
    at->right = insert(at->right, val, pos - at->rank());
    if (at->right->pri < at->pri)
      at = rotateLeft(at);
  }
  at->update();
  return at;
}

void insert(int val, int pos) {
  root = insert(root, val, pos);
}

int query(Node* at, int L, int R) {
  if (!at || L > at->cnt || R < 1) return NIL;
  if (L <= 1 && at->cnt <= R) return at->high;
  if (L <= at->rank() && at->rank() <= R) {
    int res = at->val;
    res = max(res, query(at->left, L, at->rank() - 1));
    res = max(res, query(at->right, 1, R - at->rank()));
    return res;
  }
  return max(query(at->left, L, R), query(at->right, L - at->rank(), R - at->rank()));
}

#ifdef AZN

void inorder(Node* at) {
  if (!at) return;
  inorder(at->left);
  pf('('), pf(at->cnt), pf(','), pf(at->val), pf(','), pf(at->high), pf(") ");
  inorder(at->right);
}

void inorder() {
  inorder(root);
  pln();
}
#endif

void solve(int test_num) {
  init();
  //  insert(99, 1);
  //  insert(88, 1);
  //  insert(77, 2);
  //  inorder();
  //  pln(query(root, 2, 2));
  int quests;
  scanf("%d", &quests);
  for (int q = 0, x, y; q < quests; q++) {
    char type;
    scanf(" %c %d %d", &type, &x, &y);
    if (type == 'A')
      insert(x, y);
    else
      printf("%d\n", query(root, x, y));
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
  QMAX3VN__treap::solve();
  return 0;
}

