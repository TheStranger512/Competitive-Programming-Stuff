/* Solved
 * 869. Galactic Import
 * File:   IMPORT.cpp
 * Author: Andy Y.F. Huang
 * Created on December 31, 2012, 5:51 PM
 */

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <iomanip>
#include <cassert>
#include <ctime>
#include <functional>
#include <complex>
#include <numeric>
#include <cctype>
#include <cstddef>
#include <utility>
#include <valarray>
#include <cstdlib>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace IMPORT {
int size;
int dist[27][27];
double val[27];

void solve(int test_num) {
  memset(dist, 0x3F, sizeof (dist));
  for (int i = 0; i < size; i++) {
    char planet[5], adj[55];
    double temp;
    scanf("%s %lf %s", planet, &temp, adj);
    int cur = planet[0] - 'A';
    val[cur] = temp;
    for (int j = 0; adj[j] > 0; j++) {
      dist[cur][adj[j] == '*' ? 26 : adj[j] - 'A'] = 1;
      dist[adj[j] == '*' ? 26 : adj[j] - 'A'][cur] = 1;
    }
  }
  for (int k = 0; k < 27; k++)
    for (int i = 0; i < 27; i++)
      for (int j = 0; j < 27; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  int ans = 0;
  double best = 0.0;
  for (int i = 0; i < 26; i++) {
    if (dist[i][26] > 111) continue;
    double temp = pow(0.95, dist[i][26] - 1) * val[i];
    if (temp > best) {
      best = temp;
      ans = i;
    }
  }
  printf("Import from %c\n", ans + 'A');
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (scanf("%d", &size) != EOF)
    solve(1);
}
}

int main() {
  IMPORT::solve();
  return 0;
}

