/* Solved
 * 6826. Hacking
 * File:   HACKING.cpp
 * Author: Andy Y.F. Huang
 * Created on April 21, 2013, 10:06 PM
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

namespace HACKING {

template <size_t MAXLEN, size_t ALPHABET> struct SuffixAutomaton {

  struct Node {
    Node * child[ALPHABET], *suff, *next;
    int len, best;
  } ;
  Node pool[2 * MAXLEN], *root, *nextnode, *last, *first[MAXLEN + 1];

  Node * makenode(int length) {
    memset(nextnode, 0, sizeof (Node));
    nextnode->len = length;
    return nextnode++;
  }

  void init() {
    nextnode = pool;
    last = root = makenode(0);
    memset(first, 0, sizeof (first));
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
        memcpy(copy->child, q->child, sizeof (q->child));
        copy->suff = q->suff;
        q->suff = cur->suff = copy;
        for (; p != NULL && p->child[ch] == q; p = p->suff)
          p->child[ch] = copy;
      }
    }
    last = cur;
  }

  void go(int lim) {
    for (Node* i = pool; i < nextnode; i++) {
      i->next = first[i->len];
      first[i->len] = i;
    }
    for (int len = MAXLEN; len >= 0; len--) {
      for (Node* i = first[len]; i != NULL; i = i->next) {
        bool ok = false;
        for (int c = 0; c < lim; c++) {
          if (i->child[c] == NULL) {
            ok = true;
            break;
          }
        }
        if (ok) i->best = 1;
        else {
          i->best = MAXLEN;
          for (int c = 0; c < lim; c++)
            i->best = min(i->best, 1 + i->child[c]->best);
        }
      }
    }
    Node* at = root;
    while (at->best > 1) {
      for (int c = 0; c < lim; c++)
        if (at->child[c]->best + 1 == at->best) {
          at = at->child[c];
          putchar(c + 'a');
          break;
        }
    }
    for (int c = 0; c < lim; c++)
      if (at->child[c] == NULL) {
        putchar(c + 'a');
        break;
      }
    putchar('\n');
  }
} ;

SuffixAutomaton < 11111, 26 > sam;
char str[11111];

void solve(int test_num) {
  int len, most, lim;
  scanf("%d %d %d", &len, &most, &lim);
  scanf("%s", str);
  sam.init();
  for (int i = 0; i < len; i++)
    sam.extend(str[i] - 'a');
  sam.go(lim);
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
  HACKING::solve();
  return 0;
}

