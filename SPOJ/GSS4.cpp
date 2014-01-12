/* Solved
 * 2713. Can you answer these queries IV
 * File:   GSS4.cpp
 * Author: Andy Y.F. Huang
 * Created on February 16, 2013, 5:20 PM
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
namespace GSS4 {
typedef long long llong;

const unsigned int buffer_size = 1 << 16;
char input_buffer[buffer_size];
unsigned int bytes_read = 0;
unsigned int input_index = 0;

inline int next_char(char& c) {
  if (input_index == bytes_read) {
    bytes_read = fread(input_buffer, sizeof (char) , buffer_size, stdin);
    input_buffer[bytes_read] = '\0'; //sentinel
    input_index = 0;
    if (bytes_read == 0) return EOF;
  }
  c = input_buffer[input_index++];
  return 1;
}

inline int next_int(int& ans) {
  char c = 0;
  ans = 0;
  while (c < '-') if (next_char(c) == EOF) return EOF;
  while (c >= '0') {
    ans = (ans << 1) + (ans << 3);
    ans += c - '0';
    if (next_char(c) == EOF) return EOF;
  }
  return 1;
}

inline void nextll(llong& ans) {
  char c = 0;
  ans = 0;
  while (c < '-') next_char(c);
  while (c >= '0') {
    ans = (ans << 1) + (ans << 3);
    ans += c - '0';
    next_char(c);
  }
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

inline void write_int(llong num) {
  if (num >= 10)
    write_int(num / 10);
  write_char(num % 10 + '0');
}

struct Node {
  llong sum;
  Node *left, *right, *next;
} ;

#define lim 1000000
#define mid ((start+end)>>1)
Node pool[1 << 21], *ptr;
Node *root[7];
int from, to, len, croot;
llong aux[111000];
int sqroot[1 << 20];
const char* CASE = "Case #";

Node* nextnode() {
  return ptr++;
}

void build(Node *node, int start, int end) {
  if (start == end) {
    node->sum = aux[start];
    node->left = node->right = NULL;
    return;
  }
  node->left = nextnode();
  node->right = nextnode();
  build(node->left, start, mid);
  build(node->right, mid + 1, end);
  node->sum = node->left->sum + node->right->sum;
}

void connect(Node* a, Node* b) {
  if (a == NULL) return;
  a->next = b;
  connect(a->left, b->left);
  connect(a->right, b->right);
}

llong query(Node* node, int start, int end) {
  if (from > end || to < start) return 0LL;
  if (from <= start && end <= to) return node->sum;
  return query(node->left, start, mid) + query(node->right, mid + 1, end);
}

void update(Node* node, Node* par, int start, int end) {
  if (from > end || to < start) return;
  if (node->sum == (end - start + 1)) return;
  if (from <= start && end <= to) {
    if (par == NULL)
      root[croot] = root[croot]->next;
    else if (par->left == node)
      par->left = node->next;
    else
      par->right = node->next;
    return;
  }
  update(node->left, node, start, mid);
  update(node->right, node, mid + 1, end);
  node->sum = node->left->sum + node->right->sum;
}

void solve(int test_num) {
  ptr = pool;
  for (int i = 0; i < len; i++)
    //scanf("%lld", aux + i);
    nextll(aux[i]);
  for (int j = 0; j < 7; j++) {
    root[j] = nextnode();
    build(root[j], 0, len - 1);
    if (j == 6)
      break;
    for (int i = 0; i < len; i++) {
      if (aux[i] <= lim) aux[i] = sqroot[aux[i]];
      else aux[i] = (llong) sqrt(aux[i]);
    }
  }
  for (int j = 0; j < 6; j++)
    connect(root[j], root[j + 1]);
  //connect(root[6], root[6]);
  int quests;
  next_int(quests);
  //scanf("%d", &quests);
  //printf("Case #%d:\n", test_num);
  for (int i = 0; i < 6; i++)
    write_char(CASE[i]);
  write_int(test_num);
  write_char(':');
  write_char('\n');
  for (int q = 0, type; q < quests; q++) {
    //scanf("%d %d %d", &type, &from, &to);
    next_int(type);
    next_int(from);
    next_int(to);
    if (from > to)
      swap(from, to);
    from--, to--;
    if (type == 0)
      for (croot = 0; croot < 6; croot++)
        update(root[croot], NULL, 0, len - 1);
    else {
      llong ans = query(root[0], 0, len - 1);
      //printf("%lld\n", query(root[0], 0, len - 1));
      write_int(ans);
      write_char('\n');
    }
  }
  write_char('\n');
}

void makecase() {
  srand(time(NULL));
  freopen("input.txt", "w", stdout);
  int M = 10, Q = 10;
  printf("%d\n", M);
  for (int i = 0; i < M; i++)
    printf("%lld\n", ((1LL * rand()) << 10) + 1);
  printf("%d\n", Q);
  for (int q = 0, type, from, to; q < Q; q++) {
    type = rand() & 1;
    from = rand() % M + 1;
    to = rand() % M + 1;
    printf("%d %d %d\n", type, from, to);
  }
}

void solve() {
  #ifdef AZN
  //makecase();
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  int prev = 1;
  for (int i = 1; i <= 1000; i++) {
    int next = (i + 1) *(i + 1);
    for (int j = prev; j < next; j++)
      sqroot[j] = i;
    prev = next;
  }
  for (int i = 1; next_int(len) != EOF; i++)
    solve(i);
  write_flush();
}
}

int main() {
  GSS4::solve();
  return 0;
}

