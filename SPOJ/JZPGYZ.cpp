/* Solved
 * 8093. Sevenk Love Oimaster
 * File:   JZPGYZ.cpp
 * Author: Andy Y.F. Huang
 * Created on April 1, 2013, 10:57 PM
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

namespace JZPGYZ {
#define ALPHA 96

struct Node {
  Node *fail, *next[ALPHA];
  int pos;

} ;
//static Node pool[333333], *ptr = pool;

Node* nextnode() {
  Node* ptr = new Node();
  ptr->pos = 62000;
  return ptr;
}

int last[66000], ans[66000];
int same[66000];
char buf[55];
char str[111000];
char qstr[360123];
queue<Node*> q;

void solve(int test_num) {
  memset(last, -1, sizeof (last));
  memset(same, -1, sizeof (same));
  Node *root = nextnode();
  int len, quests, total = 0;
  gets(buf);
  sscanf(buf, "%d %d", &len, &quests);
  for (int i = 0; i < len; i++) {
    gets(str + total);
    total += strlen(str + total) + 1;
  }
  //  plnarr(str, str + total);
  //  pln(total);
  for (int qq = 0; qq < quests; qq++) {
    gets(qstr);
    Node* at = root;
    for (int i = 0, c; qstr[i] > '\r'; i++) {
      c = qstr[i] - 32;
      if (at->next[c] == NULL)
        at->next[c] = nextnode();
      at = at->next[c];
    }
    if (at->pos < 62000) same[qq] = at->pos;
    else at->pos = qq;
  }
  q.push(root);
//  for (int i = 0; i < ptr - pool; i++)
//    pln(pool[i].pos);
  for (Node* at, *ch, *fa; !q.empty(); q.pop()) {
    at = q.front();
    for (int i = 0; i < ALPHA; i++) {
      if (at->next[i] == NULL) continue;
      ch = at->next[i];
      fa = at->fail;
      while (fa != NULL && fa->next[i] == NULL)
        fa = fa->fail;
      if (fa == NULL)
        ch->fail = root;
      else
        ch->fail = fa->next[i];
      q.push(ch);
    }
  }
  Node *at = root, *suf;
  for (int i = 0, cur = 0, c; i < total; i++) {
    if (str[i] == 0) {
      cur++;
      at = root;
      continue;
    }
    c = str[i] - 32;
    while (at != NULL && at->next[c] == NULL)
      at = at->fail;
    if (at == NULL)
      at = root;
    else {
      at = at->next[c];
      for (suf = at; suf != root; suf = suf->fail) {
        if (last[suf->pos] < cur) {
          ans[suf->pos]++;
          last[suf->pos] = cur;
        }
      }
    }
  }
  for (int i = 0; i < quests; i++) {
    if (same[i] > -1) printf("%d\n", ans[same[i]]);
    else printf("%d\n", ans[i]);
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
  JZPGYZ::solve();
  return 0;
}

