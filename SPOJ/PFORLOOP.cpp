/* Solved
 * 13002. For Loops Challenge
 * File:   PFORLOOP.cpp
 * Author: Andy Y.F. Huang
 * Created on July 26, 2013, 6:07 PM
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

namespace PFORLOOP {

void solve(int test_num) {
  vector<int> arr;
  for (int x; scanf("%d", &x) != EOF; )
    arr.push_back(x);
  sort(arr.begin(), arr.end());
  for (int i = 0, j = i; i < arr.size(); i = j) {
    for (j = i + 1; j < arr.size() && arr[j] == arr[j - 1] + 1; )
      j++;
    printf("for (int i = %d; i <= %d; i++) cout << i << \" \";\n", arr[i], arr[j - 1]);
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
  PFORLOOP::solve();
  return 0;
}

