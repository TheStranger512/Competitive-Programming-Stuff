/* Solved
 * 14859. Scrivener - IOI 2012
 * File:   SCRIVIOI.cpp
 * Author: Andy Y.F. Huang
 * Created on May 31, 2013, 9:42 PM
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

namespace SCRIVIOI {

struct Node {
  Node * ch[26], *par[20];
  int pos;
  char let;
} ;

#define MAXLOG 19
Node* state[1 << 20];
Node* last;
int size;

void solve(int test_num) {
  last = state[0] = new Node();
  last->pos = -1;
  for (int i = 0; i <= MAXLOG; i++)
    last->par[i] = last;
  size++;
  int quests;
  scanf("%d", &quests);
  for (int q = 0, cnt, ch, pos; q < quests; q++) {
    char type, let;
    scanf(" %c", &type);
    Node* next;
    if (type == 'T') {
      scanf(" %c", &let);
      ch = let - 'a';
      if (last->ch[ch] == NULL) {
        next = last->ch[ch] = new Node();
        next->let = let;
        next->pos = last->pos + 1;
        next->par[0] = last;
        for (int i = 1; i <= MAXLOG; i++)
          next->par[i] = next->par[i - 1]->par[i - 1];
      }
      else
        next = last->ch[ch];
      state[size++] = last = next;
    }
    else if (type == 'U') {
      //undo
      scanf("%d", &cnt);
      state[size] = last = state[size - cnt - 1];
      size++;
    }
    else {
      //print
      scanf("%d", &pos);
      Node* at = last;
      for (int i = MAXLOG; i >= 0; i--)
        if (at->par[i]->pos >= pos)
          at = at->par[i];
      printf("%c\n", at->let);
    }
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
  SCRIVIOI::solve();
  return 0;
}

