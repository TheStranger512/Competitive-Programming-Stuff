/* Solved
 * SPOJ 16279. Escaping from escaping
 * File:   TAP2013E.cpp
 * Author: Andy Y.F. Huang
 * Created on Dec 1, 2013, 8:11:49 PM
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

using namespace std;

namespace TAP2013E {
template <size_t MAXLEN, size_t ALPHABET> struct SuffixAutomaton {

  struct Node {
    Node * child[ALPHABET], *suff, *next;
    int len, dp;
  };
  Node pool[2 * MAXLEN], *root, *nextnode, *last, *first[MAXLEN + 1];

  Node * makenode(int length) {
    memset(nextnode, 0, sizeof(Node));
    nextnode->len = length;
    return nextnode++;
  }

  void init() {
    nextnode = pool;
    last = root = makenode(0);
    memset(first, 0, sizeof(first));
  }

  void extend(int ch) {
    Node* p = last, *cur = makenode(p->len + 1);
    for (; p != NULL && p->child[ch] == NULL; p = p->suff)
      p->child[ch] = cur;
    if (p == NULL)
      cur->suff = root;
    else {
      Node* q = p->child[ch];
      if (p->len + 1 == q->len)
        cur->suff = q;
      else {
        Node* copy = makenode(p->len + 1);
        memcpy(copy->child, q->child, sizeof(q->child));
        copy->suff = q->suff;
        q->suff = cur->suff = copy;
        for (; p != NULL && p->child[ch] == q; p = p->suff)
          p->child[ch] = copy;
      }
    }
    last = cur;
  }

  void go() {
    for (Node* i = pool; i < nextnode; i++) {
      i->next = first[i->len];
      first[i->len] = i;
    }
    for (int len = MAXLEN; len >= 0; len--)
      for (Node* i = first[len]; i != NULL; i = i->next) {
        if (!i->child[0] || !i->child[1])
          i->dp = i->suff ? (i->suff->len + 2) : 1;
        else
          i->dp = MAXLEN;
        if (i->child[0])
          i->dp = min(i->dp, i->child[0]->dp);
        if (i->child[1])
          i->dp = min(i->dp, i->child[1]->dp);
        //pln(i - pool, len, i->dp);
      }
  }
};

SuffixAutomaton<111000, 2> sam;
char str[111000];

void solve(int test_num) {
  scanf("%s", str);
  const int N = strlen(str);
  sam.init();
  for (int i = 0; i < N; i++)
    sam.extend(str[i] - '0');
  sam.go();
  printf("%d\n", sam.root->dp);
  //pln(sam.root->child[0]->child[0]->child[0] == NULL);
}

void solve() {
#ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
#endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  TAP2013E::solve();
  return 0;
}
