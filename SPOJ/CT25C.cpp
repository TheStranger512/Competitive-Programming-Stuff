/* Solved
 * 7025. Roads in Berland
 * File:   CT25C.cpp
 * Author: Andy Y.F. Huang
 * Created on March 28, 2013, 8:16 PM
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

namespace CT25C {
int dist[301][301];

void solve(int test_num) {
  int size;
  scanf("%d", &size);
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      scanf("%d", &dist[i][j]);
  for (int k = 0; k < size; k++)
    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  int quests;
  scanf("%d", &quests);
  for (int q = 0, from, to, cost, res; q < quests; q++) {
    scanf("%d %d %d", &from, &to, &cost);
    from--, to--;
    if (cost < dist[from][to]) {
      dist[from][to] = dist[to][from] = cost;
      for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
          dist[i][j] = min(dist[i][j], dist[i][from] + dist[from][j]);
      for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
          dist[i][j] = min(dist[i][j], dist[i][to] + dist[to][j]);
    }
    res = 0;
    for (int i = 0; i < size; i++)
      for (int j = i + 1; j < size; j++)
        res += dist[i][j];
    printf("%d\n", res);
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
  CT25C::solve();
  return 0;
}

