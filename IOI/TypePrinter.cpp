/* Solved
 * IOI 2008 Day 1
 * File:   TypePrinter.cpp
 * Author: Andy Y.F. Huang
 * Created on December 16, 2012, 9:41 PM
 */

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <iomanip>
#include <cassert>
#include <ctime>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace TypePrinter {

struct Node {
  bool end, marked;
  Node * child[26];
} ;

Node* nextnode() {
  static Node pool[1 << 19], *ptr = pool;
  return ptr++;
}

char longest[22];
char word[22];
char ans[1 << 20];
Node *root;
int anslen;

void dfs(Node* cur) {
  if (cur->end)
    ans[anslen++] = 'P';
  int last = -1;
  for (int i = 0; i < 26; i++) {
    if (cur->child[i] != NULL) {
      if (cur->child[i]->marked)
        last = i;
      else {
        ans[anslen++] = i + 'a';
        dfs(cur->child[i]);
      }
    }
  }
  if (last == -1)
    ans[anslen++] = '-';
  else {
    ans[anslen++] = last + 'a';
    dfs(cur->child[last]);
  }
}

void solve(int test_num) {
  root = nextnode();
  int longestlen = 0, len;
  anslen = 0;
  scanf("%d", &len);
  for (int i = 0; i < len; i++) {
    scanf("%s", word);
    int temp = strlen(word);
    if (temp > longestlen) {
      memcpy(longest, word, sizeof (word));
      longestlen = temp;
    }
    Node* cur = root;
    for (int j = 0; j < temp; j++) {
      char c = word[j] - 'a';
      if (cur->child[c] == NULL)
        cur->child[c] = nextnode();
      cur = cur->child[c];
    }
    cur->end = true;
  }
  //pln(longest);
  Node *cur = root;
  for (int i = 0; i < longestlen; i++) {
    cur->marked = true;
    cur = cur->child[longest[i] - 'a'];
  }
  cur->marked = true;
  dfs(root);
  while (ans[anslen - 1] == '-')
    anslen--;
  printf("%d\n", anslen);
  for (int i = 0; i < anslen; i++)
    putchar(ans[i]), putchar('\n');
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve(1);
}
}

int main() {
  TypePrinter::solve();
  return 0;
}

