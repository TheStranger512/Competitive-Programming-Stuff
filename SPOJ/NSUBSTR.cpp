/* Solved
 * 8222. Substrings
 * File:   NSUBSTR.cpp
 * Author: Andy Y.F. Huang
 * Created on April 18, 2013, 8:56 PM
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

namespace NSUBSTR {

template <size_t MAXLEN, size_t ALPHABET> struct SuffixAutomaton {

  struct Node {
    Node * child[ALPHABET], *suff, *next;
    int len, cnt;
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
    cur->cnt = 1;
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

  void go() {
    for (Node* i = pool; i < nextnode; i++) {
      i->next = first[i->len];
      first[i->len] = i;
    }
    for (int len = MAXLEN; len > 0; len--)
      for (Node* i = first[len]; i != NULL; i = i->next)
        i->suff->cnt += i->cnt;
  }

} ;

SuffixAutomaton < 255000, 26 > sam;
typedef SuffixAutomaton < 255000, 26 > ::Node Node;
int ans[255000];
char str[255000];

void solve(int test_num) {
  sam.init();
  scanf("%s", str);
  int len = 0;
  for (; str[len] > 0; len++)
    sam.extend(str[len] - 'a');
  sam.go();
  for (Node *i = sam.pool; i != sam.nextnode; i++)
    ans[i->len] = max(ans[i->len], i->cnt);
  for (int i = len - 1; i > 0; i--)
    ans[i] = max(ans[i], ans[i + 1]);
  for (int i = 1; i <= len; i++)
    printf("%d\n", ans[i]);
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
  NSUBSTR::solve();
  return 0;
}

