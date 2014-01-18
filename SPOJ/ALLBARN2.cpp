/* Solved
 * 12107. All Possible Barns
 * File:   ALLBARN2.cpp
 * Author: Andy Y.F. Huang
 * Created on August 27, 2012, 10:20 PM
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
namespace ALLBARN2 {

struct Vector {
  int vx, vy, scalar;

  bool operator<(const Vector & v) const {
    if (vx != v.vx)
      return vx < v.vx;
    if (vy != v.vy)
      return vy < v.vy;
    return scalar < v.scalar;
  }

  bool operator==(const Vector & v) const {
    return vx == v.vx && vy == v.vy && scalar == v.scalar;
  }
} ;

Vector vectors[1000100];
int x[1010], y[1010];

void solve(int test_num) {
  int len = 0, pts;
  long long ans = 0;
  scanf("%d", &pts);
  for (int i = 0; i < pts; i++)
    scanf("%d %d", &x[i], &y[i]);
  for (int i = 0; i < pts; i++) {
    for (int j = 0; j < pts; j++) {
      int vx = x[i] - x[j], vy = y[i] - y[j];
      if (vx >= 0 && vy > 0) {
        vectors[len].vx = vx, vectors[len].vy = vy;
        vectors[len++].scalar = vx * x[j] + vy * y[j];
      }
    }
  }
  sort(vectors, vectors + len);
  for (int i = 0; i < len; ) {
    Vector cur = vectors[i];
    int j = i, cnt = 0;
    while (j < len && vectors[j] == cur)
      j++, cnt++;
    if (cnt >= 2)
      ans += 1LL * cnt * (cnt - 1) / 2;
    i = j;
  }
  printf("%lld\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  for (int i = 1; i <= 10; i++)
    solve(i);
}
}

int main() {
  ALLBARN2::solve();
  return 0;
}

