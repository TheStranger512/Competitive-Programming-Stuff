/*
 * Solved
 * 8895. Power Crisis
 * File:   POCRI.cpp
 * Author: Andy Y.F. Huang
 * Created on February 18, 2013, 5:10 PM
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
namespace POCRI {
const int ans[] = {1, 18, 10, 11, 7, 17, 11, 15, 29, 5, 21,
                   13, 26, 14, 11, 23, 22, 9, 73, 17, 42, 7, 98, 15, 61, 22,
                   84, 24, 30, 9, 38, 15, 54, 27, 9, 61, 38, 22, 19, 178, 38,
                   53, 79, 68, 166, 20, 9, 22, 7, 21, 72, 133, 41, 10, 82, 92,
                   64, 129, 86, 73, 67, 19, 66, 115, 52, 24, 22, 176, 10, 57,
                   137, 239, 41, 70, 60, 116, 81, 79, 55, 102, 49, 5, 22, 54,
                   52, 113, 15};
int size;

int sim(int k) {
  deque<int> cities;
  for (int i = 1; i <= size; i++)
    cities.push_back(i);
  while (cities.size() > 1) {
    cities.pop_front();
    for (int i = 1; i < k; i++) {
      cities.push_back(cities.front());
      cities.pop_front();
    }
  }
  return cities.front();
}

void solve(int test_num) {
  printf("%d\n", ans[size - 13]);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (true) {
    scanf("%d", &size);
    if (size == 0) break;
    solve(1);
  }
}
}

int main() {
  POCRI::solve();
  return 0;
}

