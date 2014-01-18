/* Solved
 * 11573. A Famous ICPC Team
 * File:   TEAM2.cpp
 * Author: Andy Y.F. Huang
 * Created on August 25, 2012, 3:02 PM
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
namespace TEAM2 {

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int arr[4], test_num = 1;
  while (scanf("%d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3]) != EOF) {
    sort(arr, arr + 4);
    printf("Case %d: %d\n", test_num++, arr[2] + arr[3]);
  }
}
}

int main() {
  TEAM2::solve();
  return 0;
}

