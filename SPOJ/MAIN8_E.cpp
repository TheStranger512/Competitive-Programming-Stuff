/* Solved
 * 8758. Cover the string
 * File:   MAIN8_E.cpp
 * Author: Andy Y.F. Huang
 * Created on April 17, 2013, 11:49 PM
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

namespace MAIN8_E {
template <class T, size_t MAXSIZE> struct Vector {
  T arr[MAXSIZE + 1], *last;

  Vector() : last(arr) { }

  void clear() {
    last = arr;
  }

  int size() {
    return last - arr;
  }

  void push_back(const T & val) {
    *last++ = val;
  }

  void pop_back() {
    last--;
  }

  T * begin() {
    return arr;
  }

  T * end() {
    return last;
  }

  T& operator[](size_t pos) {
    return arr[pos];
  }

  T & front() {
    return *arr;
  }

  T & back() {
    return *(last - 1);
  }

} ;

char A[22222], B[111];
Vector<int, 22222> pos[26];

void solve(int test_num) {
  scanf("%s %s", A, B);
  int lenA = strlen(A), lenB = strlen(B);
  int ans = lenA + 1;
  for (int c = 0; c < 26; c++)
    pos[c].clear();
  for (int i = 0; i < lenA; i++)
    pos[A[i] - 'a'].push_back(i);
  for (int i = 0; i < lenA; i++) {
    if (A[i] != B[0]) continue;
    int at = i + 1;
    for (int j = 1; j < lenB; j++) {
      int c = B[j] - 'a';
      int next = lower_bound(pos[c].begin(), pos[c].end(), at) - pos[c].begin();
      if (next == pos[c].size()) {
        at = -1;
        break;
      }
      at = pos[c][next] + 1;
    }
    if (at > i)
      ans = min(ans, at - i);
  }
  printf("%d\n", ans > lenA ? -1 : ans);
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
  MAIN8_E::solve();
  return 0;
}

