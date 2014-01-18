/* Solved
 * 6830. Soccer Bets - easy
 * File:   SBETS.cpp
 * Author: Andy Y.F. Huang
 * Created on August 31, 2012, 2:13 AM
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
namespace SBETS {
char a[20][5], b[20][5];

struct Compare {

  bool operator()(const char* x, const char* y) const {
    return strcmp(x, y) < 0;
  }
} ;

void solve(int test_num) {
  bool lost[20] = {0};
  map<const char*, int, Compare> hash;
  int curhash = 0;
  for (int i = 0; i < 16; i++) {
    int goalsa, goalsb;
    scanf("%s %s %d %d", a[i], b[i], &goalsa, &goalsb);
    if (!hash.count(a[i]))
      hash[a[i]] = curhash++;
    if (!hash.count(b[i]))
      hash[b[i]] = curhash++;
    if (goalsa < goalsb)
      lost[hash[a[i]]] = true;
    else
      lost[hash[b[i]]] = true;
  }
  for (int i = 0; i < 16; i++) {
    if (!lost[hash[a[i]]]) {
      puts(a[i]);
      break;
    }
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  SBETS::solve();
  return 0;
}

