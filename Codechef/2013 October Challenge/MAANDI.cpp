/* Solved
 * Codechef 2013 October Challenge
 * Maxim and Dividers
 * File:   MAANDI.cpp
 * Author: Andy Y.F. Huang
 * Created on Oct 4, 2013, 3:47:56 PM
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

using namespace std;

namespace MAANDI {

bool overlucky(int x) {
  stringstream ss;
  ss << x;
  string s;
  ss >> s;
  return count(s.begin(), s.end(), '4') + count(s.begin(), s.end(), '7');
}

void solve(int test_num) {
  int N, res = 0;
  cin >> N;
  for (int i = 1; i * i <= N; i++) {
    if (N % i == 0) {
      res += overlucky(i);
      if (i * i != N)
        res += overlucky(N / i);
    }
  }
  cout<<res<<endl;
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
  MAANDI::solve();
  return 0;
}
