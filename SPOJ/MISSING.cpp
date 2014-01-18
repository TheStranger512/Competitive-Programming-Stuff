/*
 * Solved
 * 13995. Missing Number
 * File:   MISSING.cpp
 * Author: Andy Y.F. Huang
 * Created on March 4, 2013, 10:04 PM
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
namespace MISSING {

void solve(int test_num) {
  bitset<10111000> have;
  int len, start;
  scanf("%d %d", &len, &start);
  long long num;
  for (int i = 1; i < len; i++) {
    scanf("%lld", &num);
    have[num - start] = true;
  }
  for (int i = 0; i < len; i++) {
    if (!have[i]) {
      printf("%lld\n", 0LL + start + i);
      break;
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
  MISSING::solve();
  return 0;
}

