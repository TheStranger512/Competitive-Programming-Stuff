/* Solved
 * 48. Glass Beads
 * File:   BEADS.cpp
 * Author: Andy Y.F. Huang
 * Created on December 25, 2012, 7:47 PM
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
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <iomanip>
#include <cassert>
#include <ctime>
#include <functional>
#include <complex>
#include <numeric>
#include <cctype>
#include <cstddef>
#include <utility>
#include <valarray>
#include <cstdlib>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace BEADS {

template <class T> struct SuffixArray {
  #define MAXLEN 22222
  #define MAXLOG 16

  struct Entry {
    int first, second, pos;

    bool operator<(const Entry & e) const {
      return first < e.first || (first == e.first && second < e.second);
    }

    friend ostream& operator<<(ostream& out, const Entry & e) {
      return out << '(' << e.first << ',' << e.second << ',' << e.pos << ')';
    }
  } ;

  Entry order[MAXLEN];
  int sa[MAXLOG][MAXLEN];
  int len, maxlog;

  void init(const T *string, int length) {
    len = length;
    for (int i = 0; i < len; i++)
      sa[0][i] = string[i] - 'a';
    maxlog = 0;
    while ((1 << maxlog) <= len) maxlog++;
    for (int step = 1, size = 1; step <= maxlog; size <<= 1, step++) {
      for (int i = 0; i < len; i++) {
        order[i].pos = i;
        order[i].first = sa[step - 1][i];
        order[i].second = i + size < len ? sa[step - 1][i + size] : -1;
      }
      sort(order, order + len);
      sa[step][order[0].pos] = 0;
      for (int i = 1; i < len; i++)
        if (!(order[i - 1] < order[i]))
          sa[step][order[i].pos] = sa[step][order[i - 1].pos];
        else
          sa[step][order[i].pos] = i;
    }
  }
} ;

char str[22222];
SuffixArray<char> sa;

void solve(int test_num) {
  scanf("%s", str);
  int len = strlen(str);
  for (int i = 0; i < len; i++)
    str[i + len] = str[i];
  str[2 * len] = 'z' + 1;
  sa.init(str, 2 * len + 1);
  printf("%d\n", sa.order[0].pos + 1);
}

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
}

int main() {
  BEADS::solve();
  return 0;
}

