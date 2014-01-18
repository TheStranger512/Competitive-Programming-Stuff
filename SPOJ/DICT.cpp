/* Solved
 * 10381. Search in the dictionary!
 * File:   DICT.cpp
 * Author: Andy Y.F. Huang
 * Created on December 7, 2012, 5:16 PM
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
namespace DICT {

struct Node {
  bool leaf;
  Node * next[26];
} ;

char temp[111], temp2[111];
Node pool[1 << 19];
bool fnd;

void dfs(Node* cur, int pos) {
  for (int i = 0; i < 26; i++) {
    if (cur->next[i] != NULL) {
      temp2[pos] = i + 'a';
      if (cur->next[i]->leaf) {
        fnd = true;
        temp2[pos + 1] = '\0';
        printf("%s\n", temp2);
      }
      dfs(cur->next[i], pos + 1);
    }
  }
}

void solve(int test_num) {
  Node *nextNode = pool + 1, *root = pool;
  int len;
  scanf("%d", &len);
  for (int i = 0; i < len; i++) {
    scanf("%s", temp);
    Node *cur = root;
    for (int j = 0; temp[j] > 0; j++) {
      int c = temp[j] - 'a';
      if (cur->next[c] == NULL) {
        cur->next[c] = nextNode++;
      }
      cur = cur->next[c];
    }
    cur->leaf = true;
  }
  int quests;
  scanf("%d", &quests);
  for (int q = 1; q <= quests; q++) {
    scanf("%s", temp);
    Node *cur = root;
    int pos = 0;
    bool bad = false;
    for (int j = 0; temp[j] > 0; j++, pos++) {
      temp2[pos] = temp[j];
      if (cur->next[temp[j] - 'a'] == NULL) {
        bad = true;
        break;
      }
      cur = cur->next[temp[j] - 'a'];
    }
    printf("Case #%d:\n", q);
    if (bad) {
      puts("No match.");
      continue;
    }
    fnd = false;
    dfs(cur, pos);
    if (!fnd)
      puts("No match.");
  }
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
  DICT::solve();
  return 0;
}

