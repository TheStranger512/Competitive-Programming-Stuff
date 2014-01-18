/* Solved
 * 2412. Arranging Amplifiers
 * File:   ARRANGE.cpp
 * Author: Andy Y.F. Huang
 * Created on July 24, 2013, 12:37 AM
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

namespace ARRANGE {

void solve(int test_num) {
  int N, ones = 0;
  vector<int> arr;
  scanf("%d", &N);
  for (int i = 0, x; i < N; i++) {
    scanf("%d", &x);
    if (x != 1)
      arr.push_back(x);
    else ones++;
  }
  sort(arr.begin(), arr.end(), greater<int>());
  if (arr.size() == 2u && arr[0] == 3 && arr[1] == 2)
    swap(arr[0], arr[1]);
  for (int i = 0; i < ones; i++)
    printf("%d ", 1);
  for (int i = 0; i < (int) arr.size(); i++)
    printf("%d ", arr[i]);
  puts("");
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
  ARRANGE::solve();
  return 0;
}

