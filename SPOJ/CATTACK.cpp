/* Solved
 * 6805. Counter attack
 * File:   CATTACK.cpp
 * Author: Andy Y.F. Huang
 * Created on February 26, 2013, 12:12 AM
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
namespace CATTACK {
int best0[111000], best1[111000];
int pass0[111000], dribble0[111000];
int pass1[111000], dribble1[111000];

void readarr(int* arr, int len) {
  for (int i = 0; i < len; i++)
    scanf("%d", arr + i);
}

void solve(int test_num) {
  int len, long0, long1, shoot0, shoot1;
  scanf("%d %d %d %d %d", &len, &long0, &long1, &shoot0, &shoot1);
  readarr(pass0, len - 1);
  readarr(dribble0, len - 1);
  readarr(pass1, len - 1);
  readarr(dribble1, len - 1);
  best0[0] = long0;
  best1[0] = long1;
  for (int i = 0; i + 1 < len; i++) {
    best0[i + 1] = min(best0[i] + dribble0[i], best1[i] + pass1[i]);
    best1[i + 1] = min(best1[i] + dribble1[i], best0[i] + pass0[i]);
  }
  printf("%d\n", min(best0[len - 1] + shoot0, best1[len - 1] + shoot1));
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  CATTACK::solve();
  return 0;
}

