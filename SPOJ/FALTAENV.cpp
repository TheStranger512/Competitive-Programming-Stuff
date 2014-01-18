/* Solved
 * 7189. Falta Envido
 * File:   FALTAENV.cpp
 * Author: Andy Y.F. Huang
 * Created on September 25, 2012, 11:06 PM
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
#include <fstream>
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace FALTAENV {
const char* k_suits[4] = {"espada", "basto", "copa", "oro"};
int cards[3][2];
char suit[3][10];
bool used[15][4];

int decode(const char* str) {
  for (int i = 0; i < 4; i++)
    if (strcmp(str, k_suits[i]) == 0)
      return i;
  assert(false);
}

int getscore(int card1, int card2, int deckv, int decks) {
  int ans = 0;
  int val[3] = {cards[card1][0], cards[card2][0], deckv};
  int suit[3] = {cards[card1][1], cards[card2][1], decks};
  for (int i = 0; i < 3; i++) {
    if (val[i] <= 7)
      ans = max(ans, val[i]);
    else
      val[i] = 0;
  }
  for (int i = 0; i < 3; i++)
    for (int j = i + 1; j < 3; j++)
      if (suit[i] == suit[j])
        ans = max(ans, val[i] + val[j] + 20);
  return ans;
}

void solve(int test_num) {
  memset(used, false, sizeof (used));
  for (int i = 0; i < 3; i++) {
    cards[i][1] = decode(suit[i]);
    used[cards[i][0]][cards[i][1]] = true;
  }
  int ans = 0, orig = getscore(0, 1, cards[2][0], cards[2][1]);
  for (int a = 0; a < 3; a++) {
    for (int b = a + 1; b < 3; b++) {
      for (int val = 1; val <= 12; val++) {
        for (int s = 0; s < 4; s++) {
          if (used[val][s])
            continue;
          ans = max(ans, getscore(a, b, val, s));
        }
        if (val == 7)
          val = 9;
      }
    }
  }
  printf("%d\n", ans - orig);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (true) {
    for (int i = 0; i < 3; i++)
      scanf("%d %s", &cards[i][0], suit[i]);
    if (cards[0][0] == -1)
      break;
    solve(1);
  }
}
}

int main() {
  FALTAENV::solve();
  return 0;
}

