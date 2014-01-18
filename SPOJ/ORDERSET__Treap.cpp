/* Solved
 * 3273. Order statistic set
 * using treap
 * File:   ORDERSET__Treap.cpp
 * Author: Andy Y.F. Huang
 * Created on April 30, 2013, 11:42 PM
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

namespace ORDERSET__Treap {
#define MAX 200010

struct Node {
  int val, pri, cnt;
  Node *left, *right;

  void update() {
    cnt = leftcnt() + 1 + rightcnt();
  }

  int leftcnt() {
    return left ? left->cnt : 0;
  }

  int rightcnt() {
    return right ? right->cnt : 0;
  }

} ;

Node pool[MAX], *ptr;
Node *root;

Node* make(int val) {
  ptr->val = val;
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

Node * insert(Node *at, int val) {
  if (!at)
    return make(val);
  else if (val < at->val) {
    at->left = insert(at->left, val);
    if (at->left->pri < at->pri)
      at = rotateRight(at);
  }
  else if (val > at->val) {
    at->right = insert(at->right, val);
    if (at->right->pri < at->pri)
      at = rotateLeft(at);
  }
  at->update();
  return at;
}

Node* erase(Node* at, int val) {
  if (!at)
    return NULL;
  if (val < at->val)
    at->left = erase(at->left, val);
  else if (val > at->val)
    at->right = erase(at->right, val);
  else {
    if (at->left == NULL)
      return at->right;
    else if (at->right == NULL)
      return at->left;
    else if (at->left->pri > at->right->pri) {
      Node* t = rotateRight(at);
      t->right = erase(at, val);
      at = t;
    }
    else {
      Node* t = rotateLeft(at);
      t->left = erase(at, val);
      at = t;
    }
  }
  at->update();
  return at;
}

int getkth(int K) {
  Node* at = root;
  while (at) {
    if (at->leftcnt() + 1 == K)
      return at->val;
    else if (K <= at->leftcnt())
      at = at->left;
    else {
      K -= at->leftcnt() + 1;
      at = at->right;
    }
  }
  return -1;
}

int getless(int val) {
  int res = 0;
  Node* at = root;
  while (at) {
    if (at->val < val) {
      res += at->leftcnt() + 1;
      at = at->right;
    }
    else
      at = at->left;
  }
  return res;
}

//void inorder(Node* at) {
//  if (!at) return;
//  inorder(at->left);
//  pf(at->val), pf(' ');
//  inorder(at->right);
//}

void init() {
  srand(time(NULL));
  ptr = pool;
  root = NULL;
}

void solve(int test_num) {
  init();
  //    for (int i = 0; i < 20; i++)
  //      root = insert(root, i);
  //  inorder(root);
  //  pln();
  //  for (int i = 0; i < 20; i++) {
  //    int x = rand() % 20;
  //    root = erase(root, x);
  //    dbgln(x);
  //    inorder(root);
  //    pln();
  //  }
  //pln(getkth(19));
  int quests;
  scanf("%d", &quests);
  for (int q = 0, x; q < quests; q++) {
    char type;
    scanf(" %c %d", &type, &x);
    if (type == 'I')
      root = insert(root, x);
    else if (type == 'D')
      root = erase(root, x);
    else if (type == 'K') {
      int res = getkth(x);
      if (res == -1) puts("invalid");
      else printf("%d\n", res);
    }
    else printf("%d\n", getless(x));
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
  ORDERSET__Treap::solve();
  return 0;
}

