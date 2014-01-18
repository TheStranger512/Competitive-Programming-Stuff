/* Solved
 * 2826. Round-Robin Scheduling
 * File:   RRSCHED.cpp
 * Author: Andy Y.F. Huang
 * Created on May 1, 2013, 11:19 PM
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

namespace RRSCHED {

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

  int get_greatereq(T val) {
    Node* at = root;
    int res = 0;
    while (at) {
      if (at->val >= val) {
        res += at->rightcnt() + 1;
        at = at->left;
      }
      else at = at->right;
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

typedef pair<int, int> Job;
typedef long long llong;
Job jobs[111000];
llong ans[111000];
Treap<int, 111000 > vals;
int len;

void solve(int test_num) {
  scanf("%d", &len);
  vals.init();
  for (int i = 0; i < len; i++) {
    scanf("%d", &jobs[i].first);
    vals.insert(jobs[i].first);
    ans[i] = vals.get_greatereq(jobs[i].first);
    jobs[i].second = i;
  }
  sort(jobs, jobs + len);
  llong total = 0;
  for (int i = 0, j; i < len; ) {
    j = i;
    while (j < len && jobs[j].first == jobs[i].first)
      j++;
    llong temp = 0;
    for (int k = i; k < j; k++) {
      ans[jobs[k].second] += total + (len - i) * (jobs[k].first - 1LL);
      temp += jobs[k].first;
    }
    i = j;
    total += temp;
  }
  for (int i = 0; i < len; i++)
    printf("%lld\n", ans[i]);
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
  RRSCHED::solve();
  return 0;
}

