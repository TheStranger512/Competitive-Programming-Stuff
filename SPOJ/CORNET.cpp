/* Solved
 * 264. Corporative Network
 * File:   CORNET.cpp
 * Author: Andy Y.F. Huang
 * Created on February 18, 2013, 1:20 PM
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
namespace CORNET {
int par[22222];
int dist[22222];
char str[5];

int find(int at) {
  if (par[at] == -1) return at;
  find(par[at]);
  dist[at] += dist[par[at]];
  return par[at] = find(par[at]);
}

void unite(int a, int b) {
  //a = find(a);
  par[a] = b;
  dist[a] = abs(a - b) % 1000;
}

void solve(int test_num) {
  int len;
  scanf("%d", &len);
  memset(par, -1, sizeof (par));
  memset(dist, 0, sizeof (dist));
  while (true) {
    scanf("%s", str);
    if (str[0] == 'O') break;
    if (str[0] == 'I') {
      int a, b;
      scanf("%d %d", &a, &b);
      unite(a, b);
    }
    else {
      int a;
      scanf("%d", &a);
      find(a);
      printf("%d\n", dist[a]);
    }
    //plnarr(par + 1, par + len + 1);
    //plnarr(dist + 1, dist + len + 1);
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int t = 1; t <= tests; t++)
    solve(1);
}
}

int main() {
  CORNET::solve();
  return 0;
}

