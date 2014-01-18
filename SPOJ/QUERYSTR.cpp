/* Solved
 * 5301. Query Problem
 * File:   QUERYSTR.cpp
 * Author: Andy Y.F. Huang
 * Created on March 30, 2013, 10:54 PM
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

namespace QUERYSTR {

template <size_t MAXLEN, size_t ALPHABET> struct SuffixAutomaton {

  struct Node {
    Node * child[ALPHABET], *suff, *next;
    int len, ans;
  } ;
  Node pool[2 * MAXLEN], *root, *nextnode, *last, *first[MAXLEN + 1];

  Node * makenode(int length) {
    memset(nextnode, 0, sizeof (Node));
    nextnode->len = length;
    nextnode->ans = -1;
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

  void go() {
    for (Node* i = pool; i < nextnode; i++) {
      i->next = first[i->len];
      first[i->len] = i;
    }
    for (Node* i = last; i != NULL; i = i->suff)
      i->ans = i->len;
  }
} ;

#define MAX 1000100
char str[MAX];
SuffixAutomaton<MAX, 26 > sam;
SuffixAutomaton<MAX, 26 > ::Node *at;
int ans[MAX];

void solve(int test_num) {
  gets(str);
  int len = strlen(str);
  while (str[len - 1] < ' ') len--;
  sam.init();
  for (char* c = str; *c > ' '; c++)
    sam.extend(*c - 'a');
  sam.go();
  for (int L = 1; L <= len; L++)
    for (at = sam.first[L]; at != NULL; at = at->next)
      if (at->ans == -1)
        at->ans = at->suff->ans;
  at = sam.root;
  for (int i = 0; i < len; i++) {
    at = at->child[str[i] - 'a'];
    ans[i + 1] = at->ans;
  }
  int quests;
  scanf("%d", &quests);
  for (int q = 0, pos; q < quests; q++) {
    scanf("%d ", &pos);
    printf("%d\n", ans[pos]);
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  int tests;
  scanf("%d ", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  QUERYSTR::solve();
  return 0;
}

