/* Solved
 * 15259. Large Knapsack
 * File:   LKS.cpp
 * Author: Andy Y.F. Huang
 * Created on July 21, 2013, 11:38 PM
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

namespace LKS {
pair<int, int> item[555];//(weight, value)
int dp[2000001];

void solve(int test_num) {
  int B, N;
  cin >> B >> N;
  for (int i = 0; i < N; i++)
    cin >> item[i].second >> item[i].first;
  sort(item, item + N);
  memset(dp, 0xC0, sizeof (dp));
  dp[0] = 0;
  int high = 0;
  for (int i = 0; i < N; i++) {
    if (item[i].first > B) continue;
    for (int j = min(high, B - item[i].first); j >= 0; j--)
      dp[j + item[i].first] = max(dp[j + item[i].first], dp[j] + item[i].second);
    high += item[i].first;
  }
  printf("%d\n", *max_element(dp, dp + B + 1));
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
  LKS::solve();
  return 0;
}

