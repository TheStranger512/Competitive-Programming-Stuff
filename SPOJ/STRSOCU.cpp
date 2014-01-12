/* Solved
 * 12713. Strings
 * File:   STRSOCU.cpp
 * Author: Andy Y.F. Huang
 * Created on April 18, 2013, 8:16 PM
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

namespace STRSOCU {
template <size_t MAXLEN, size_t ALPHABET> struct SuffixAutomaton {

  struct Node {
    Node * child[ALPHABET], *suff, *next;
    int len, cnt;
  } ;
  Node pool[2 * MAXLEN], *root, *nextnode, *last, *first[MAXLEN + 1];
  queue<pair<Node*, Node*> > q;

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

  int solve(const SuffixAutomaton& sam, int K) {
    int res = 0;
    Node* at, *cur;
    q.push(make_pair(root, sam.root));
    for (; !q.empty(); q.pop()) {
      at = q.front().first;
      cur = q.front().second;
      if (at != root && cur->cnt == K)
        res++;
      for (int c = 0; c < 26; c++)
        if (at->child[c] != NULL && cur->child[c] != NULL)
          q.push(make_pair(at->child[c], cur->child[c]));
    }
    return res;
  }
} ;

SuffixAutomaton < 8888, 26 > sam, sam2;
char A[8888], B[8888];

void solve(int test_num) {
  int K;
  sam.init();
  sam2.init();
  scanf("%s %s %d", A, B, &K);
  int lenA = strlen(A), lenB = strlen(B);
  for (int i = 0; i < lenA; i++)
    sam.extend(A[i] - 'a');
  for (int i = 0; i < lenB; i++)
    sam2.extend(B[i] - 'a');
  sam2.go();
  printf("Case #%d:\n", test_num);
  printf("%d\n", sam.solve(sam2, K));
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
  STRSOCU::solve();
  return 0;
}

