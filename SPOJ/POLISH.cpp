/* Solved
 * 10419. Polish Language
 * File:   POLISH.cpp
 * Author: Andy Y.F. Huang
 * Created on December 31, 2012, 8:36 PM
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
namespace POLISH {

template <class T> struct SuffixArray {
  #define MAXLEN 111111
  int n;
  int m[2][MAXLEN];
  int sa[MAXLEN];

  void indexSort(int sa[], int ord[], int id[], int nId) { //ord is the ordering get from prev stage
    static int cnt[MAXLEN];
    memset(cnt, 0, sizeof (0) * nId);
    for (int i = 0; i < n; ++i)
      cnt[id[i]]++;
    partial_sum(cnt, cnt + nId, cnt);
    for (int i = n - 1; i >= 0; --i)
      sa[--cnt[id[ord[i]]]] = ord[i];
  }

  int*id, *oId;

  void init(T s[], int _n) { //s[n] == 0
    n = _n;
    assert(s[n - 1] == *min_element(s, s + n));
    static char w[MAXLEN];
    memcpy(w, s, sizeof (int) * n);
    sort(w, w + n);
    int nId = unique(w, w + n) - w;
    id = m[0], oId = m[1];
    for (int i = 0; i < n; ++i)
      id[i] = lower_bound(w, w + nId, s[i]) - w;
    static int ord[MAXLEN];
    for (int i = 0; i < n; ++i)
      ord[i] = i;
    indexSort(sa, ord, id, nId);
    for (int k = 1; k <= n && nId < n; k <<= 1) {
      //get the prev order
      // k -> k*2
      int cur = 0;
      for (int i = n - k; i < n; ++i)
        ord[cur++] = i;
      for (int i = 0; i < n; ++i)
        if (sa[i] >= k)
          ord[cur++] = sa[i] - k;
      indexSort(sa, ord, id, nId);
      //get new id
      cur = 0;
      swap(oId, id);
      for (int i = 0; i < n; ++i) {
        int c = sa[i], p = i ? sa[i - 1] : 0;
        id[c] = (i == 0 || oId[c] != oId[p] || oId[c + k] != oId[p + k]) ? cur++ : cur - 1;
      }
      nId = cur;
    }
  }
} ;


#define mod 1000000007
int tree[1 << 17];
char str[1 << 17];
SuffixArray<char> sa;

void solve(int test_num) {
  int len = strlen(str);
  sa.init(str, len + 1);
  memset(tree, 0, sizeof (tree));
  int ans = 0;
  for (int i = 1; i <= len; i++) {
    int size = len - sa.sa[i];
    int temp = 1;
    for (int j = size - 1; j > 0; j -= j&-j) {
      temp += tree[j];
      if (temp >= mod) temp -= mod;
    }
    ans += temp;
    if (ans >= mod) ans -= mod;
    for (int j = size; j <= len; j += j&-j) {
      tree[j] += temp;
      if (tree[j] >= mod) tree[j] -= mod;
    }
  }
  printf("%d\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (scanf("%s", str) != EOF)
    solve(1);
}
}

int main() {
  POLISH::solve();
  return 0;
}

