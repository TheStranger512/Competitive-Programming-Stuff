/* Solved
 * 6377. Two Array Problem
 * File:   SAMTWARR.cpp
 * Author: Andy Y.F. Huang
 * Created on January 4, 2013, 9:12 PM
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
namespace SAMTWARR {

struct Node {
  int sum;
  Node *left, *right;
} ;

Node* nextnode() {
  static Node pool[1 << 19], *ptr = pool;
  ptr->sum = 0;
  return ptr++;
}

Node *root[2];
int from, to, pos, val;

void build(Node *cur, int start, int end) {
  if (start == end) return;
  cur->left = nextnode();
  cur->right = nextnode();
  int mid = (start + end) >> 1;
  build(cur->left, start, mid);
  build(cur->right, mid + 1, end);
}

void update(Node *cur, int start, int end) {
  if (start == end) cur->sum = val;
  else {
    int mid = (start + end) >> 1;
    if (pos <= mid)
      update(cur->left, start, mid);
    else
      update(cur->right, mid + 1, end);
    cur->sum = cur->left->sum + cur->right->sum;
  }
}

int query(const Node *cur, int start, int end) {
  if (from > end || to < start) return 0;
  if (from <= start && end <= to) return cur->sum;
  int mid = (start + end) >> 1;
  return query(cur->left, start, mid) + query(cur->right, mid + 1, end);
}

void exchange(Node *a, Node *para, Node *b, Node *parb, int start, int end) {
  if (from > end || to < start) return;
  if (from <= start && end <= to) {
    if (para == NULL)
      swap(root[0], root[1]);
    else {
      if (para->left == a)
        swap(para->left, parb->left);
      else
        swap(para->right, parb->right);
    }
    return;
  }
  int mid = (start + end) >> 1;
  exchange(a->left, a, b->left, b, start, mid);
  exchange(a->right, a, b->right, b, mid + 1, end);
  a->sum = a->left->sum + a->right->sum;
  b->sum = b->left->sum + b->right->sum;
}

void solve(int test_num) {
  int len, quests;
  scanf("%d %d", &len, &quests);
  root[0] = nextnode();
  root[1] = nextnode();
  build(root[0], 0, len - 1);
  build(root[1], 0, len - 1);
  for (int q = 0; q < quests; q++) {
    int cmd, arr;
    scanf("%d", &cmd);
    if (cmd == 0) {
      scanf("%d %d %d", &arr, &from, &to);
      printf("%d\n", query(root[arr], 0, len - 1));
    }
    else if (cmd == 1) {
      scanf("%d %d %d", &arr, &pos, &val);
      update(root[arr], 0, len - 1);
    }
    else {
      scanf("%d %d", &from, &to);
      exchange(root[0], NULL, root[1], NULL, 0, len - 1);
    }
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
  SAMTWARR::solve();
  return 0;
}

