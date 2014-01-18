/* Solved
 * 6898. Substring Problem
 * File:   SUB_PROB.cpp
 * Author: Andy Y.F. Huang
 * Created on April 21, 2013, 9:38 PM
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

namespace SUB_PROB {
template <size_t MAXLEN, size_t ALPHABET> struct SuffixAutomaton {

  struct Node {
    Node * child[ALPHABET], *suff;
    int len;
  } ;
  Node pool[2 * MAXLEN], *root, *nextnode, *last;

  Node * makenode(int length) {
    memset(nextnode, 0, sizeof (Node));
    nextnode->len = length;
    return nextnode++;
  }

  void init() {
    nextnode = pool;
    last = root = makenode(0);
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
} ;

SuffixAutomaton<100100, 62> sam;
char str[111000], temp[2222];

int get(char c) {
  if (isdigit(c)) return c - '0' + 52;
  if (islower(c)) return c - 'a';
  return c - 'A' + 26;
}

void solve(int test_num) {
  sam.init();
  scanf("%s", str);
  for (char* i = str; *i > 0; i++)
    sam.extend(get(*i));
  int cnt;
  scanf("%d", &cnt);
  for (int i = 0; i < cnt; i++) {
    scanf("%s", temp);
    SuffixAutomaton<100100, 62>::Node *at = sam.root;
    bool ok = true;
    for (char* j = temp; *j > 0; j++) {
      int c = get(*j);
      if (at->child[c] == NULL) {
        ok = false;
        break;
      }
      at = at->child[c];
    }
    puts(ok ? "Y" : "N");
  }
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
  SUB_PROB::solve();
  return 0;
}

