/* Solved
 * 3605. Minimum Rotations
 * File:   MINMOVE.cpp
 * Author: Andy Y.F. Huang
 * Created on April 16, 2013, 9:53 PM
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

namespace MINMOVE {
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
        copy->pos = q->pos;
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

char str[111000];
SuffixAutomaton<222000, 26> sam;

void solve(int test_num) {
  sam.init();
  scanf("%s", str);
  int len = strlen(str);
  for (int i = 0; i < len; i++)
    sam.extend(str[i] - 'a');
  for (int i = 0; i < len; i++)
    sam.extend(str[i] - 'a');
  SuffixAutomaton<222000, 26>::Node *at = sam.root;
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < 26; j++)
      if (at->child[j] != NULL) {
        at = at->child[j];
        break;
      }
  }
  printf("%d\n", at->pos - len + 1);
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
  MINMOVE::solve();
  return 0;
}

