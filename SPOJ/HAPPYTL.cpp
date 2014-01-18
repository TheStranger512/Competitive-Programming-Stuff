/* Solved
 * 10078. Happy Telephones
 * File:   HAPPYTL.cpp
 * Author: Andy Y.F. Huang
 * Created on August 3, 2012, 12:43 AM
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
#include <fstream>
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace HAPPYTL {
const int k_max_calls = 10010;
int start[k_max_calls], end[k_max_calls];

void solve(int test_num, int calls, int queries) {
  for (int i = 0; i < calls; i++) {
    int source, dest;
    scanf("%d %d %d %d", &source, &dest, &start[i], &end[i]);
    end[i] += start[i];
  }
  for (int i = 0; i < queries; i++) {
    int qx, qy, cnt = 0;
    scanf("%d %d", &qx, &qy);
    qy += qx;
    for (int j = 0; j < calls; j++)
      if (qx < end[j] && start[j] < qy)
        cnt++;
    printf("%d\n", cnt);
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (true) {
    int calls, queries;
    scanf("%d %d", &calls, &queries);
    if (calls == 0 && queries == 0)
      break;
    solve(1, calls, queries);
  }
}
}

int main() {
  HAPPYTL::solve();
  return 0;
}

