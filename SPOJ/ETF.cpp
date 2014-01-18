/* Solved
 * 4141. Euler Totient Function
 * File:   ETF.cpp
 * Author: Andy Y.F. Huang
 * Created on July 22, 2012, 11:03 PM
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
#define pln(x) println(x)
#define pf(x) print(x)
#define plnarr(i, j) println(i, j)
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
class ETF {
  int* ans;

  void init() {
    const int k_max_n = 1000010;
    bool* sieve = new bool[k_max_n];
    ans = new int[k_max_n];
    for (int i = 0; i < k_max_n; i++)
      ans[i] = i;
    for (int i = 2; i < k_max_n; i++) {
      if (!sieve[i]) {
        ans[i]--;
        for (int j = 2 * i; j < k_max_n; j += i) {
          sieve[j] = true;
          ans[j] = ans[j] / i * (i - 1);
        }
      }
    }
    delete [] sieve;
  }

public:

  void solve() {
    #ifdef AZN
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int tests;
    init();
    scanf("%d", &tests);
    for (int i = 1; i <= tests; i++) {
      int n;
      scanf("%d", &n);
      printf("%d\n", ans[n]);
    }
    delete [] ans;
  }
} ;

int main() {
  ETF solver;
  solver.solve();
  return 0;
}

