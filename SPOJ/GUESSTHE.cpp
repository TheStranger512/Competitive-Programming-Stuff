/*
 * 7190. Guess the Number
 * File:   GUESSTHE.cpp
 * Author: Andy Y.F. Huang
 * Created on July 22, 2012, 6:21 PM
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
class GUESSTHE {

  int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }

  void solve(int test_num, const char* line) {
    int num = 1;
    int len = strlen(line);
    for (int i = 0; i < len; i++)
      if (line[i] == 'Y')
        num = num / gcd(num, i + 1) * (i + 1);
    for (int i = 0; i < len; i++) {
      if (line[i] == 'N' && num % (i + 1) == 0) {
        puts("-1");
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
    while (true) {
      char str[25];
      gets(str);
      if (str[0] == '*')
        break;
      solve(1, str);
    }
  }
} ;

int main() {
  GUESSTHE solver;
  solver.solve();
  return 0;
}

