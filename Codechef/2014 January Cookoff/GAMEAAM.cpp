/* Solved
 * Codechef 2014 January Challenge
 * Subtraction Game
 * File:   GAMEAAM.cpp
 * Author: Andy Y.F. Huang (azneye)
 * Created on Jan 19, 2014, 11:27:19 AM
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

namespace GAMEAAM {

int go(int a, int b) {
  //pln(a, b);
  //a > b
  if (b > a)
    swap(a, b);
  if (a == b)
    return 0;
  const int steps = (a - 1) / b;
  const int nim = go(b, a - steps * b);
  if (steps == 1)
    return nim == 0 ? 1 : 0;
  else
    return nim < steps ? steps : steps - 1;
}

void solve(int test_num) {
  int N, nim = 0;
  cin >> N;
  for (int i = 0, a, b; i < N; i++) {
    cin >> a >> b;
    nim ^= go(a, b);
  }
  if (nim)
    cout << "YES";
  else
    cout << "NO";
  cout << endl;
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
  GAMEAAM::solve();
  return 0;
}
