/*
 * 27. Sorting Bank Accounts
 * File:   SBANK.cpp
 * Author: Andy Y.F. Huang
 * Created on July 21, 2012, 2:57 PM
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
class SBANK {

  struct Cmp {

    bool operator()(const char* a, const char* b) const {
      return strcmp(a, b) < 0;
    }
  } ;

  void solve(int test_num) {
    static char str[100010][40];
    map<char*, int, Cmp> order;
    int accounts;
    scanf("%d\r\n", &accounts);
    for (int i = 0; i < accounts; i++) {
      gets(str[i]);
      str[i][31] = '\0';
      order[str[i]]++;
    }
    map<char*, int>::iterator it;
    for (it = order.begin(); it != order.end(); ++it)
      printf("%s %d\n", it->first, it->second);
    puts("");
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
  SBANK solver;
  solver.solve();
  return 0;
}

