/* Solved
 * 705. New Distinct Substrings
 * File:   SUBST1.cpp
 * Author: Andy Y.F. Huang
 * Created on August 26, 2012, 2:02 PM
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
#include <functional>
#include <sstream>
#include <deque>
#include <cassert>
#include <functional>
#include <complex>
#include <numeric>
#include <cctype>
#include <cstddef>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

template <class T, size_t MAXLEN> struct SuffixArray {
  int rank[MAXLEN], sa[MAXLEN], lcp[MAXLEN];
  int len;

  void radixsort(int order[], int id[], int buckets) {
    static int count[MAXLEN];
    memset(count, 0, sizeof (int) * buckets);
    for (int i = 0; i < len; i++)
      count[id[i]]++;
    partial_sum(count, count + buckets, count);
    for (int i = len - 1; i >= 0; i--)
      sa[--count[id[order[i]]]] = order[i];
  }

  void init(const T str[], int length) {
    static T temp[MAXLEN];
    static int order[MAXLEN], trank[2][MAXLEN];
    len = length;
    copy(str, str + len, temp);
    sort(temp, temp + len);
    int buckets = unique(temp, temp + len) - temp;
    int *cur = trank[0], *prev = trank[1];
    for (int i = 0; i < len; i++)
      cur[order[i] = i] = lower_bound(temp, temp + buckets, str[i]) - temp;
    radixsort(order, cur, buckets);
    for (int size = 1; size <= len && buckets < len; size <<= 1) {
      for (int i = 0; i < len; i++)
        order[i] = sa[i] >= size ? sa[i] - size : sa[i] - size + len;
      radixsort(order, cur, buckets);
      buckets = 0;
      swap(prev, cur);
      for (int i = 0, st1 = sa[i], st2; i < len; i++, st2 = st1, st1 = sa[i]) {
        if (i == 0 || prev[st1] != prev[st2] || prev[st1 + size] != prev[st2 + size])
          cur[st1] = buckets++;
        else cur[st1] = buckets - 1;
      }
    }
    memcpy(rank, cur, sizeof (int) * len);
    for (int i = 0, height = 0, prev; i < len - 1; i++) {
      prev = sa[rank[i] - 1];
      while (str[i + height] == str[prev + height])
        height++;
      lcp[rank[i]] = height;
      if (height > 0) height--;
    }
  }

} ;

using namespace std;

namespace SUBST1 {
char str[50010];
SuffixArray<char, 50010 > sa;

void solve(int test_num) {
  scanf("%s", str);
  int len = strlen(str);
  str[len] = '$';
  sa.init(str, len + 1);
  long long total = (len + 1LL) * (len) / 2;
  for (int i = 1; i <= len; i++)
    total -= sa.lcp[i];
  printf("%lld\n", total);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  SUBST1::solve();
  return 0;
}

