/* Solved
 * 13707. SHAHBAG
 * File:   SHAHBG.cpp
 * Author: Andy Y.F. Huang
 * Created on February 12, 2013, 9:07 PM
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
namespace SHAHBG {
int pos[22222];

void solve(int test_num) {
  int len, cnt = 0;
  scanf("%d", &len);
  memset(pos, -1, sizeof (pos));
  for (int i = 0; i < len; i++) {
    int at;
    scanf("%d", &at);
    pos[at] = 1;
    cnt++;
    if (at > 0 && pos[at - 1] > 0) cnt--;
    if (pos[at + 1] > 0) cnt--;
    printf("%d\n", cnt);
  }
  puts("Justice");
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
  SHAHBG::solve();
  return 0;
}

