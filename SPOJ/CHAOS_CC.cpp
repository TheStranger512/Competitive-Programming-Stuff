/*
 * Solved
 * 13806. Chaos In Arkham
 * File:   CHAOS_CC.cpp
 * Author: Andy Y.F. Huang
 * Created on February 18, 2013, 4:10 PM
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

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace CHAOS_CC {
#define MAX 3400
int nimber[3555];
bool mex[3555];

void solve(int test_num) {
  int n;
  scanf("%d", &n);
  if (nimber[n] == 0) puts("Bane");
  else puts("Joker");
}

void init() {
  nimber[0] = 0;
  nimber[1] = 1;
  for (int i = 2; i <= MAX; i++) {
    memset(mex, false, sizeof (mex));
    //pln("at", i);
    for (int j = 0; j < i; j++) {
      mex[nimber[max(0, j - 2)] ^ nimber[max(0, i - j - 3)]] = true;
      //pln(max(0, j - 2), max(0, i - j - 3));
    }
    nimber[i] = 0;
    while (mex[nimber[i]])
      nimber[i]++;
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  init();
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  CHAOS_CC::solve();
  return 0;
}

