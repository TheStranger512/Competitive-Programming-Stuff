/* Solved
 * 9761. Dolls
 * File:   SCPC11H.cpp
 * Author: Andy Y.F. Huang
 * Created on March 29, 2013, 8:00 PM
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

namespace SCPC11H {
const int k_max_len = 505;
int matchRight[k_max_len];
bool seen[k_max_len];
int graph[k_max_len][k_max_len], degree[k_max_len];
int len, a[555], b[555], c[555];

bool canMatch(int guy) {
  for (int i = 0; i < degree[guy]; i++) {
    if (seen[graph[guy][i]])
      continue;
    int girl = graph[guy][i];
    seen[girl] = true;
    if (matchRight[girl] < 0 || canMatch(matchRight[girl])) {
      matchRight[girl] = guy;
      return true;
    }
  }
  return false;
}

int maxMatching(int guys) {
  memset(matchRight, -1, sizeof (matchRight));
  int matches = 0;
  for (int i = 0; i < guys; i++) {
    memset(seen, false, sizeof (seen));
    matches += canMatch(i);
  }
  return matches;
}

void solve(int test_num) {
  memset(degree, 0, sizeof (degree));
  for (int i = 0; i < len; i++)
    scanf("%d %d %d", a + i, b + i, c + i);
  for (int i = 0; i < len; i++)
    for (int j = 0 ; j < len; j++)
      if (a[i] > a[j] && b[i] > b[j] && c[i] > c[j])
        graph[i][degree[i]++] = j;
  printf("%d\n", len - maxMatching(len));
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (scanf("%d", &len) != EOF)
    if (len > 0)
      solve(1);
}
}

int main() {
  SCPC11H::solve();
  return 0;
}

