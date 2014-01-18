/* Solved
 * 1329. Matrix
 * File:   KPMATRIX.cpp
 * Author: Andy Y.F. Huang
 * Created on May 1, 2013, 9:58 PM
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

namespace KPMATRIX {
template <class T, size_t MAXNODES> struct Treap {

  struct Node {
    T val;
    int pri, cnt;
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

  Node pool[MAXNODES], *ptr;
  Node *root;

  Node * make(int val) {
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
    else {
      at->right = insert(at->right, val);
      if (at->right->pri < at->pri)
        at = rotateLeft(at);
    }
    at->update();
    return at;
  }

  int getlesseq(T val) {
    Node* at = root;
    int res = 0;
    while (at) {
      if (at->val <= val) {
        res += at->leftcnt() + 1;
        at = at->right;
      }
      else at = at->left;
    }
    return res;
  }

  void init() {
    ptr = pool;
    root = NULL;
  }

  void insert(T val) {
    root = insert(root, val);
  }
} ;
int sum[255][255];
//int vals[255], valcnt;
//int fenw[255];
Treap<int, 255> vals;
int rows, cols;

inline int getsum(int c, int r1, int r2) {
  return sum[r2][c] - sum[r1 - 1][c];
}

void solve(int test_num) {
  int ans = 0;
  scanf("%d %d", &rows, &cols);
  for (int r = 1; r <= rows; r++)
    for (int c = 1; c <= cols; c++) {
      scanf("%d", sum[r] + c);
      sum[r][c] += sum[r - 1][c];
    }
  //plnarr(sum, rows + 1, cols + 1);
  int A, B;
  scanf("%d %d", &A, &B);
  for (int r1 = 1; r1 <= rows; r1++) {
    for (int r2 = r1; r2 <= rows; r2++) {
      int cur = 0;
      vals.init();
      vals.insert(cur);
      for (int c = 1; c <= cols; c++) {
        cur += getsum(c, r1, r2);
        ans += vals.getlesseq(cur - A) - vals.getlesseq(cur - B - 1);
        vals.insert(cur);
      }
    }
  }
  printf("%d\n", ans);
}

void makecase() {
  srand(time(NULL));
  freopen("input.txt", "w", stdout);
  int R = 25, C = 25;
  printf("%d %d\n", R, C);
  for (int r = 0; r < R; r++, putchar('\n'))
    for (int c = 0; c < C; c++)
      printf("%d ", rand() & 1023);
  int A = -1000000000, B = 1000000000;
  printf("%d %d\n", A, B);
}

void solve() {
  #ifdef AZN
  //makecase();
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  memset(sum, 0, sizeof (sum));
  solve(1);
}
}

int main() {
  KPMATRIX::solve();
  return 0;
}

