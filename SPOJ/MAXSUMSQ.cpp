/* Solved
 * 5972. Maximum Sum Sequences
 * File:   MAXSUMSQ.cpp
 * Author: Andy Y.F. Huang
 * Created on April 28, 2013, 3:35 PM
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

namespace MAXSUMSQ {
const unsigned int buffer_size = 1 << 16;
char input_buffer[buffer_size];
unsigned int bytes_read = 0;
unsigned int input_index = 0;

inline char next_char() {
  if (input_index == bytes_read) {
    bytes_read = fread(input_buffer, sizeof (char) , buffer_size, stdin);
    input_buffer[bytes_read] = '\0'; //sentinel
    input_index = 0;
  }
  return input_buffer[input_index++];
}

inline int next_int() {
  char c = 0;
  int ans = 0;
  while (c < '-') c = next_char();
  bool neg;
  if (c == '-')
    neg = true, c = next_char();
  else
    neg = false;
  while (c >= '0') {
    ans = (ans << 1) + (ans << 3);
    ans += c - '0';
    c = next_char();
  }
  return neg ? -ans : ans;
}

template <class T, size_t MAXNODES> struct Treap {

  struct Node {
    T data;
    int priority, cnt;
    Node *left, *right;
  } ;

  Node pool[MAXNODES], *ptr;
  Node *root;
  int count;

  Node * rotateRight(Node * node) {
    Node *temp = node->left;
    node->left = temp->right;
    temp->right = node;
    return temp;
  }

  Node * rotateLeft(Node * node) {
    Node *temp = node->right;
    node->right = temp->left;
    temp->left = node;
    return temp;
  }

  Node * insert(Node *at, T val) {
    if (at == NULL) {
      Node* temp = ptr++;
      temp->left = temp->right = NULL;
      temp->data = val;
      temp->priority = rand();
      temp->cnt = 1;
      return temp;
    }
    else if (val < at->data) {
      at->left = insert(at->left, val);
      if (at->left->priority < at->priority)
        at = rotateRight(at);
    }
    else if (val > at->data) {
      at->right = insert(at->right, val);
      if (at->right->priority < at->priority)
        at = rotateLeft(at);
    }
    else at->cnt++;
    return at;
  }

  void init() {
    ptr = pool;
    root = NULL;
    count = 0;
  }

  int getcount(T val) {
    Node *at = root;
    while (at != NULL) {
      if (at->data == val) return at->cnt;
      else if (val < at->data) at = at->left;
      else at = at->right;
    }
    return 0;
  }

  void insert(T val) {
    root = insert(root, val);
    count++;
  }
} ;

int arr[100100];
int sum[100100];
Treap<int, 100100 > vals;

void solve(int test_num) {
  int len = next_int();
  for (int i = 0; i < len; i++)
    arr[i] = next_int();
  int ans = *max_element(arr, arr + len);
  srand(time(NULL));
  vals.init();
  long long cnt = 0;
  for (int i = 0, cur = 0, low = 0; i < len; i++) {
    cur += arr[i];
    ans = max(ans, cur - low);
    low = min(low, cur);
    sum[i] = cur;
  }
  vals.insert(0);
  for (int i = 0; i < len; i++) {
    cnt += vals.getcount(sum[i] - ans);
    vals.insert(sum[i]);
  }
  printf("%d %lld\n", ans, cnt);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  int tests = next_int();
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  MAXSUMSQ::solve();
  return 0;
}

