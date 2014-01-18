/* Solved
 * 3394. Lagrange’s Four-Square Theorem
 * File:   LAGRANGE.cpp
 * Author: Andy Y.F. Huang
 * Created on September 4, 2012, 1:49 PM
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
namespace LAGRANGE {
const int k_max = 183, k_lim = 1 << 15;
int sq[k_max], ans[1 << 16] = {0};

void init() {
  for (int i = 0; i < k_max; i++) {
    sq[i] = i * i;
    ans[sq[i]]++;
  }
  for (int i = 1; i < k_max; i++) {
    for (int j = i; j < k_max; j++) {
      int temp = sq[i] + sq[j];
      if (temp <= k_lim)
        ans[temp]++;
      else
        break;
    }
  }
  for (int i = 1; i < k_max; i++) {
    for (int j = i; j < k_max; j++) {
      for (int k = j; k < k_max; k++) {
        int temp = sq[i] + sq[j] + sq[k];
        if (temp <= k_lim)
          ans[temp]++;
        else
          break;
      }
    }
  }
  for (int i = 1; i < k_max; i++) {
    for (int j = i; j < k_max; j++) {
      for (int k = j; k < k_max; k++) {
        for (int l = k; l < k_max; l++) {
          int temp = sq[i] + sq[j] + sq[k] + sq[l];
          if (temp <= k_lim)
            ans[temp]++;
          else
            break;
        }
      }
    }
  }
}

void solve(int test_num, int n) {
  printf("%d\n", ans[n]);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  init();
  for (int n; ; ) {
    scanf("%d", &n);
    if (n == 0)
      break;
    solve(1, n);
  }
}
}

int main() {
  LAGRANGE::solve();
  return 0;
}

