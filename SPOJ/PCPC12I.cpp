/* Solved
 * 13095. peaks
 * File:   PCPC12I.cpp
 * Author: Andy Y.F. Huang
 * Created on June 21, 2013, 10:01 PM
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

namespace PCPC12I {

struct Trip {
  int a, b, c;

  Trip(int a, int b, int c) : a(a), b(b), c(c) { }

  bool operator<(const Trip & x) const {
    return a < x.a || (a == x.a && b < x.b) || (a == x.a && b == x.b && c < x.c);
  }
} ;

#define INF 0x3F3F3F3F
int arr[1 << 20];
int high[1 << 20], low[1 << 20];
int len;

void solve(int test_num) {
  Trip res(INF, -1, -1);
  int best = -1;
  for (int i = 1; i <= len; i++)
    scanf("%d", arr + i);
  high[len] = low[len] = len;
  for (int i = len - 1; i > 0; i--) {
    if (arr[i] >= arr[high[i + 1]])
      high[i] = i;
    else
      high[i] = high[i + 1];
    if (arr[i] <= arr[low[i + 1]])
      low[i] = i;
    else
      low[i] = low[i + 1];
  }
  int l = 1, h = 1;
  for (int i = 2; i < len; i++) {
    if (arr[l] <= arr[i] && arr[i] >= arr[low[i + 1]]) {
      int sum = 2 * arr[i] - arr[l] - arr[low[i + 1]];
      if (sum > best) {
        best = sum;
        res = Trip(INF, -1, -1);
      }
      if (sum == best)
        res = min(res, Trip(l, i, low[i + 1]));
    }
    if (arr[h] >= arr[i] && arr[i] <= arr[high[i + 1]]) {
      int sum = arr[h] + arr[high[i + 1]] - 2 * arr[i];
      if (sum > best) {
        best = sum;
        res = Trip(INF, -1, -1);
      }
      if (sum == best)
        res = min(res, Trip(h, i, high[i + 1]));
    }
    if (arr[i] < arr[l]) l = i;
    if (arr[i] > arr[h]) h = i;
  }
  if (res.a == INF) puts("-1");
  else printf("%d %d %d\n", res.a, res.b, res.c);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (scanf("%d", &len) != EOF)
    solve(1);
}
}

int main() {
  PCPC12I::solve();
  return 0;
}

