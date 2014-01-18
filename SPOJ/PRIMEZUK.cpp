/* Solved
 * 9587. The Prime conjecture
 * File:   PRIMEZUK.cpp
 * Author: Andy Y.F. Huang
 * Created on July 22, 2012, 6:41 PM
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
class PRIMEZUK {

  bool isPrime(int num) {
    int sq = (int) sqrt(num);
    for (int i = 2; i <= sq; i++)
      if (num % i == 0)
        return false;
    return true;
  }

  void solve(int test_num) {
    int len, num = 1;
    scanf("%d", &len);
    for (int i = 0; i < len; i++) {
      int temp;
      scanf("%d", &temp);
      num *= temp;
    }
    printf("Case #%d: ", test_num);
    num++;
    int sq = (int) sqrt(num);
    for (int i = 2; i <= sq; i++) {
      if (num % i == 0 && isPrime(num / i)) {
        printf("%d\n", num / i);
        return;
      }
    }
    printf("%d\n", num);
  }

public:

  void solve() {
    #ifdef AZN
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int tests;
    scanf("%d", &tests);
    for (int i = 1; i <= tests; i++)
      solve(i);
  }
} ;

int main() {
  PRIMEZUK solver;
  solver.solve();
  return 0;
}

