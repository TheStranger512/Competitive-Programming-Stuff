/* Solved
 * 1812. Longest Common Substring II
 * File:   LCS2.cpp
 * Author: Andy Y.F. Huang
 * Created on April 3, 2013, 9:42 PM
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

namespace LCS2 {
#ifdef AZN
#define MAX 1010
#else
#define MAX 100010
#endif

struct Node {
  Node * child[26], *suff;
  int len, match[9];
} ;

Node *root, *last;
Node pool[2 * MAX], *ptr = pool;
char str[MAX];

Node* alloc() {
  memset(ptr, 0, sizeof (Node));
  return ptr++;
}

void extend(int c) {
  Node* cur = alloc(), *p = last;
  cur->len = p->len + 1;
  for (; p != NULL && p->child[c] == NULL; p = p->suff)
    p->child[c] = cur;
  if (p == NULL)
    cur->suff = root;
  else {
    Node* q = p->child[c];
    if (p->len + 1 == q->len)
      cur->suff = q;
    else {
      Node* copy = alloc();
      memcpy(copy, q, sizeof (Node));
      copy->len = p->len + 1;
      cur->suff = q->suff = copy;
      for (; p != NULL && p->child[c] == q; p = p->suff)
        p->child[c] = copy;
    }
  }
  last = cur;
}

void solve(int test_num) {
  ptr = pool;
  root = last = alloc();
  gets(str);
  for (char* p = str; *p > ' '; p++)
    extend(*p - 'a');
  int cnt = 0;
  while (gets(str) != NULL) {
    Node* at = root;
    int len = 0, c;
    for (char* p = str; *p > ' '; p++) {
      c = *p - 'a';
      while (at != root && at->child[c] == NULL) {
        at = at->suff;
        len = at->len;
        at->match[cnt] = max(at->match[cnt], len);
      }
      if (at->child[c] != NULL) {
        at = at->child[c];
        len++;
        at->match[cnt] = max(at->match[cnt], len);
      }
    }
    cnt++;
  }
  int ans = 0;
  for (Node* i = root + 1; i < ptr; i++)
    ans = max(ans, *min_element(i->match, i->match + cnt));
  printf("%d\n", ans);
}

void makecase() {
  srand(time(NULL));
  freopen("input.txt", "w", stdout);
  for (int i = 0; i < 10; i++) {
    int len = 10;
    for (int j = 0; j < len; j++)
      //putchar((j & 1) + 'a');
      putchar(rand() % 26 + 'a');
    putchar('\n');
  }
}

void solve() {
  #ifdef AZN
  //makecase();
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  solve(1);
}
}

int main() {
  LCS2::solve();
  return 0;
}

