/* Solved
 * 12540. It is Super Effective
 * File:   EFFECTIV.cpp
 * Author: Andy Y.F. Huang
 * Created on October 27, 2012, 12:20 PM
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
namespace EFFECTIV {

struct Comp {

  bool operator()(const char* a, const char* b) const {
    return strcmp(a, b) < 0;
  }
} ;

const int atk[15][15] = {
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0},
  {0, 2, 2, 0, 1, 1, 0, 0, 0, 0, 0, 1, 2, 0, 2},
  {0, 1, 2, 0, 2, 0, 0, 0, 1, 0, 0, 0, 1, 0, 2},
  {0, 0, 1, 2, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 2},
  {0, 2, 1, 0, 2, 0, 0, 2, 1, 2, 0, 2, 1, 0, 2},
  {0, 0, 2, 0, 1, 2, 0, 0, 0, 1, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 1, 0, 2, 0, 2, 2, 2, 1, 0, 0},
  {0, 0, 0, 0, 1, 0, 0, 2, 2, 0, 0, 1, 2, 2, 0},
  {0, 1, 0, 1, 2, 0, 0, 1, 0, 0, 0, 2, 1, 0, 0},
  {0, 0, 0, 2, 1, 0, 1, 0, 0, 0, 0, 1, 2, 0, 0},
  {0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 0, 0, 0, 0},
  {0, 2, 0, 0, 1, 0, 2, 1, 0, 2, 1, 0, 0, 2, 0},
  {0, 1, 0, 0, 0, 1, 2, 0, 2, 1, 0, 1, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
};
char names[155][55];
char temp[155][55];
int len;
map<const char*, int, Comp> hash;
char a[55], b[55];

int gettype(const char* str) {
  if (strcmp(str, "Normal") == 0)
    return 0;
  else if (strcmp(str, "Fire") == 0)
    return 1;
  else if (strcmp(str, "Water") == 0)
    return 2;
  else if (strcmp(str, "Electric") == 0)
    return 3;
  else if (strcmp(str, "Grass") == 0)
    return 4;
  else if (strcmp(str, "Ice") == 0)
    return 5;
  else if (strcmp(str, "Fighting") == 0)
    return 6;
  else if (strcmp(str, "Poison") == 0)
    return 7;
  else if (strcmp(str, "Ground") == 0)
    return 8;
  else if (strcmp(str, "Flying") == 0)
    return 9;
  else if (strcmp(str, "Psychic") == 0)
    return 10;
  else if (strcmp(str, "Bug") == 0)
    return 11;
  else if (strcmp(str, "Rock") == 0)
    return 12;
  else if (strcmp(str, "Ghost") == 0)
    return 13;
  else
    return 14;
}

void solve(int test_num) {
  hash.clear();
  for (int i = 0; i < len; i++) {
    scanf("%s %s", names[i], temp[i]);
    hash[names[i]] = gettype(temp[i]);
  }
  //plnarr(hash.begin(), hash.end());
  int quests;
  scanf("%d", &quests);
  for (int q = 0; q < quests; q++) {
    scanf("%s %s", a, b);
    //assert(hash.count(a) && hash.count(b));
    int t = atk[hash[a]][hash[b]];
    if (t == 0)
      puts("Regular Attack.");
    else if (t == 1)
      puts("It's super effective!");
    else
      puts("It's not very effective...");
  }
  putchar('\n');
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (true) {
    scanf("%d", &len);
    if (len == 0)
      break;
    solve(1);
  }
}
}

int main() {
  EFFECTIV::solve();
  return 0;
}

