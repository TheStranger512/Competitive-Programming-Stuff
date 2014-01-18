/* Solved
 * 5511. Heavy Sequences
 * File:   HSEQ.cpp
 * Author: Andy Y.F. Huang
 * Created on April 28, 2013, 5:00 PM
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

namespace HSEQ {
#ifdef AZN
#define MAX 1000
#else
#define MAX 100100
#endif

struct Node;
typedef map<int, Node*> BST_t;
typedef long long llong;

struct Node {
  BST_t child;
  Node* suff, *next;
  int len, cnt;
  bool yes;

  llong weight() {
    return cnt == 1 ? 0 : (llong) (len) * cnt;
  }

} ;

Node* first[MAX], *last, *root, pool[2 * MAX], *ptr = pool;
int len;
BST_t::iterator it;

Node* alloc() {
  ptr->cnt = ptr->len = ptr->yes = 0;
  return ptr++;
}

void extend(int c) {
  Node* cur = alloc(), *p = last;
  cur->len = p->len + 1;
  cur->cnt = 1;
  for (; p != NULL && !p->child.count(c); p = p->suff)
    p->child[c] = cur;
  if (p == NULL)
    cur->suff = root;
  else {
    Node* q = p->child[c];
    if (p->len + 1 == q->len)
      cur->suff = q;
    else {
      Node* copy = alloc();
      copy->child = q->child;
      copy->len = p->len + 1;
      copy->suff = q->suff;
      q->suff = cur->suff = copy;
      for (; p != NULL && p->child[c] == q; p = p->suff)
        p->child[c] = copy;
    }
  }
  last = cur;
}

void solve(int test_num) {
  ptr = pool;
  root = last = alloc();
  scanf("%d", &len);
  for (int i = 0, num; i < len; i++) {
    scanf("%d", &num);
    extend(num);
  }
  for (Node* i = root; i < ptr; i++) {
    i->next = first[i->len];
    first[i->len] = i;
  }
  llong best = 0;
  for (int l = len; l > 0; l--)
    for (Node* i = first[l]; i != NULL; i = i->next) {
      i->suff->cnt += i->cnt;
      best = max(best, i->weight());
    }
  for (Node* i = root; i < ptr; i++)
    if (i->weight() == best)
      i->yes = true;
  for (int l = len; l >= 0; l--) {
    for (Node* i = first[l]; i != NULL; i = i->next) {
      if (i->yes) continue;
      for (it = i->child.begin(); it != i->child.end(); ++it) {
        if (it->second->yes) {
          i->yes = true;
          break;
        }
      }
    }
  }
  if (best == 0) {
    puts("-1");
    return;
  }
  int cnt = 0;
  for (Node* at = root; at->weight() != best; ) {
    for (it = at->child.begin(); it != at->child.end(); ++it)
      if (it->second->yes && at->len + 1 == it->second->len) {
        cnt++;
        printf("%d ", it->first);
        at = it->second;
        assert(cnt == at->len);
        break;
      }
  }
  putchar('\n');
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
  HSEQ::solve();
  return 0;
}

