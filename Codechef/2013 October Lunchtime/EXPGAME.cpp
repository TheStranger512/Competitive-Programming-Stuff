/* Solved
 * Codechef October Lunchtime 2013
 * Exponential Game
 * File:   EXPGAME.cpp
 * Author: Andy Y.F. Huang
 * Created on Oct 27, 2013, 1:38:27 AM
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

namespace EXPGAME {
const int moves[6] = { 1, 4, 27, 256, 3125, 46656 };
int nim[100111];

void solve(int test_num) {
  int N, xsum = 0;
  cin >> N;
  for (int i = 0, a; i < N; i++) {
    cin >> a;
    xsum ^= nim[a];
  }
  if (xsum == 0)
    cout << "Head Chef" << endl;
  else
    cout << "Little Chef" << endl;
}

void solve() {
#ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
#endif
  nim[0] = 0;
  bool vis[11];
  for (int i = 1; i <= 100000; i++) {
    memset(vis, false, sizeof(vis));
    for (int j = 0; j < 6 && moves[j] <= i; j++)
      vis[nim[i - moves[j]]] = true;
    nim[i] = 0;
    while (vis[nim[i]])
      nim[i]++;
  }
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  EXPGAME::solve();
  return 0;
}
