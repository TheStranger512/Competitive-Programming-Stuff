/* Solved
 * 1811. Longest Common Substring
 * File:   LCS.cpp
 * Author: Andy Y.F. Huang
 * Created on March 30, 2013, 8:36 PM
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

namespace LCS {

template <size_t MAXLEN, size_t ALPHABET> struct SuffixAutomaton {
  static const int NIL = -1;

  struct Node {
    Node * next[ALPHABET], *suff;
    int len;
  } ;
  Node pool[2 * MAXLEN], *root, *last, *nextnode;

  Node * makenode(int length) {
    memset(nextnode->next, 0, sizeof (nextnode->next));
    nextnode->suff = NULL;
    nextnode->len = length;
    return nextnode++;
  }

  void init() {
    nextnode = pool;
    last = root = makenode(0);
  }

  void extend(int ch) {
    Node* p = last, *cur = makenode(p->len + 1);
    for (; p != NULL && p->next[ch] == NULL; p = p->suff)
      p->next[ch] = cur;
    if (p == NULL)
      cur->suff = root;
    else {
      Node* q = p->next[ch];
      if (p->len + 1 == q->len)
        cur->suff = q;
      else {
        Node* copy = makenode(p->len + 1);
        memcpy(copy->next, q->next, sizeof (q->next));
        copy->suff = q->suff;
        q->suff = cur->suff = copy;
        for (; p != NULL && p->next[ch] == q; p = p->suff)
          p->next[ch] = copy;
      }
    }
    last = cur;
  }

} ;

SuffixAutomaton < 255000, 26 > sam;
char str1[255000], str2[255000];

void solve(int test_num) {
  sam.init();
  gets(str1);
  gets(str2);
  for (int i = 0; str1[i] > ' '; i++)
    sam.extend(str1[i] - 'a');
  int res = 0;
  SuffixAutomaton < 255000, 26 > ::Node* at = sam.root;
  for (int i = 0, len = 0, ch; str2[i] > ' '; i++) {
    ch = str2[i] - 'a';
    while (at != sam.root && at->next[ch] == NULL) {
      at = at->suff;
      len = at->len;
    }
    if (at->next[ch] != NULL) {
      at = at->next[ch];
      len++;
    }
    res = max(res, len);
  }
  printf("%d\n", res);
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
  LCS::solve();
  return 0;
}

