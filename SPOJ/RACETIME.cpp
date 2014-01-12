/* Solved
 * 3261. Race Against Time
 * File:   RACETIME.cpp
 * Author: Andy Y.F. Huang
 * Created on May 12, 2013, 11:51 AM
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

namespace RACETIME {
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
  while (c >= '0') {
    ans = (ans << 1) + (ans << 3);
    ans += c - '0';
    c = next_char();
  }
  return ans;
}

inline char get_char() {
  char c = 0;
  while (c < ' ') c = next_char();
  return c;
}

char output_buffer[buffer_size];
unsigned int output_index = 0;

inline void write_flush() {
  fwrite(output_buffer, sizeof (char) , output_index, stdout);
  output_index = 0;
}

inline void write_char(char c) {
  output_buffer[output_index++] = c;
  if (output_index == buffer_size)
    write_flush();
}

inline void write_int(int num) {
  if (num >= 10)
    write_int(num / 10);
  write_char(num % 10 + '0');
}

template <class T> struct Treap {

  struct Node {
    T val;
    int pri, cnt;
    Node *left, *right;

    Node(T val) : val(val), pri(rand()), cnt(1) { }

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


  Node *root;

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

  Node * insert(Node *at, T val) {
    if (!at)
      return new Node(val);
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

  Node * erase(Node* at, T val) {
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
      else if (at->left->pri < at->right->pri) {
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

  void init() {
    srand(time(NULL));
    root = NULL;
  }

  int getlesseq(int val) {
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

  void erase(T val) {
    root = erase(root, val);
  }

  void insert(T val) {
    root = insert(root, val);
  }
} ;

#define mid ((l+r)>>1)
Treap<int> tree[333000];
int val[111000];
int len;
int L, R;
int B;

void build(int node, int l, int r) {
  for (int i = l; i <= r; i++)
    tree[node].insert(val[i]);
  if (l < r) {
    build(node << 1, l, mid);
    build(node << 1 | 1, mid + 1, r);
  }
}

int query(int node, int l, int r) {
  if (L > r || R < l) return 0;
  if (L <= l && r <= R)
    return tree[node].getlesseq(B);
  return query(node << 1, l, mid) + query(node << 1 | 1, mid + 1, r);
}

void update(int pos, int nval) {
  int node = 1, l = 1, r = len;
  while (true) {
    tree[node].erase(val[pos]);
    tree[node].insert(nval);
    if (l == r)
      break;
    if (pos <= mid) {
      node <<= 1;
      r = mid;
    }
    else {
      node = node << 1 | 1;
      l = mid + 1;
    }
  }
}

void solve(int test_num) {
  srand(time(NULL));
  len = next_int();
  int ops = next_int();
  for (int i = 1; i <= len; i++)
    val[i] = next_int();
  build(1, 1, len);
  for (int q = 0, res, nval, pos; q < ops; q++) {
    char type = get_char();
    if (type == 'C') {
      L = next_int();
      R = next_int();
      B = next_int();
      res = query(1, 1, len);
      write_int(res);
      write_char('\n');
    }
    else {
      pos = next_int();
      nval = next_int();
      update(pos, nval);
      val[pos] = nval;
    }
  }
  write_flush();
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
  RACETIME::solve();
  return 0;
}

