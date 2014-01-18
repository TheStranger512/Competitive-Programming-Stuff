/*
 * Solved
 * 4523. Binomial Coefficients
 * File:   UCI2009B.cpp
 * Author: Andy Y.F. Huang
 * Created on March 3, 2013, 12:41 AM
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

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace UCI2009B {
#define SIZE(x) (int) (x.size())
vector<pair<int, int> > factors[1001]; //(factor, cnt)
bool sieve[1001] = {false};
int num[1001], den[1001];

void printvar(char c, int expon) {
  if (expon > 0) {
    putchar(c);
    if (expon > 1)
      printf("^%d", expon);
  }
}

void printfactor(int fact, int expon) {
  printf("%d", fact);
  if (expon > 1)
    printf("^%d", expon);
  putchar('x');
}

void solve(int test_num) {
  int expon;
  scanf("%d", &expon);
  if (expon == 0) {
    puts("1");
    return;
  }
  for (int i = 0; i <= expon; i++) {
    if (i != 0) putchar('+');
    memset(num, 0, sizeof (num));
    memset(den, 0, sizeof (den));
    for (int j = 1, l = expon; j <= i; j++, l--) {
      for (int k = 0; k < SIZE(factors[j]); k++)
        den[factors[j][k].first] += factors[j][k].second;
      for (int k = 0; k < SIZE(factors[l]); k++)
        num[factors[l][k].first] += factors[l][k].second;
    }
    for (int p = 1; p <= expon; p++)
      if (num[p] - den[p] > 0)
        printfactor(p, num[p] - den[p]);
    printvar('A', expon - i);
    printvar('B', i);
  }
  putchar('\n');
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  factors[1].push_back(make_pair(1, 1));
  for (int i = 2; i < 1000; i++)
    if (!sieve[i]) {
      factors[i].push_back(make_pair(i, 1));
      for (int j = i + i; j < 1001; j += i) {
        int cnt = 0;
        for (int t = j; t % i == 0; t /= i)
          cnt++;
        factors[j].push_back(make_pair(i, cnt));
        sieve[j] = true;
      }
    }
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  UCI2009B::solve();
  return 0;
}

