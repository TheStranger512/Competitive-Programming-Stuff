/* Solved
 * 4681. Twice
 * File:   TWICE.cpp
 * Author: Andy Y.F. Huang
 * Created on December 25, 2012, 7:57 PM
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
namespace TWICE {

template <class T> struct SuffixArray {
  #define MAXLEN 222222
  #define MAXLOG 19

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

  int lcp(int a, int b) {
    int res = 0;
    for (int k = maxlog; k >= 0 && a < len && b < len; k--) {
      if (sa[k][a] == sa[k][b]) {
        res += 1 << k;
        a += 1 << k;
        b += 1 << k;
      }
    }
    return res;
  }
} ;

char str[200100];
SuffixArray<char> sa;

void solve(int test_num) {
  int len;
  scanf("%d%s", &len, str);
  sa.init(str, len);
  int ans = 0;
  for (int i = 0; i < len - 1; i++)
    ans = max(ans, sa.lcp(sa.order[i].pos, sa.order[i + 1].pos));
  printf("%d\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve(1);
}
}

int main() {
  TWICE::solve();
  return 0;
}

