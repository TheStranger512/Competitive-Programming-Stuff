/* Solved
 * 10079. Stammering Aliens
 * File:   STAMMER.cpp
 * Author: Andy Y.F. Huang
 * Created on April 21, 2013, 6:41 PM
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

namespace STAMMER {

template <size_t MAXLEN, size_t ALPHABET> struct SuffixAutomaton {

  struct Node {
    Node * child[ALPHABET], *suff, *next;
    int len, pos, cnt;
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
    root->pos = -1;
    memset(first, 0, sizeof (first));
  }

  void extend(int ch) {
    Node* p = last, *cur = makenode(p->len + 1);
    cur->cnt = 1;
    cur->pos = cur->len - 1;
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
        copy->pos = q->pos;
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
    for (int len = MAXLEN; len > 0; len--)
      for (Node* i = first[len]; i != NULL; i = i->next) {
        i->suff->cnt += i->cnt;
        i->suff->pos = max(i->suff->pos, i->pos);
      }
  }

  void solve(int need) {
    int best = 0, pos = 0;
    for (Node* i = pool; i < nextnode; i++) {
      if (i->cnt >= need) {
        if (i->len > best) {
          best = i->len;
          pos = i->pos - i->len + 1;
        }
        if (i->len == best)
          pos = max(pos, i->pos - i->len + 1);
      }
    }
    if (best == 0) puts("none");
    else printf("%d %d\n", best, pos);
  }
} ;


int need;
char str[40100];
SuffixAutomaton < 40100, 26 > sam;

void solve(int test_num) {
  sam.init();
  scanf("%s", str);
  for (int i = 0; str[i] > 0; i++)
    sam.extend(str[i] - 'a');
  sam.go();
  sam.solve(need);

}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (scanf("%d", &need) != EOF)
    if (need > 0)
      solve(1);
}
}

int main() {
  STAMMER::solve();
  return 0;
}

