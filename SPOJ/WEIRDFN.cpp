/* Solved
 * 5977. Weird Function
 * File:   WEIRDFN.cpp
 * Author: Andy Y.F. Huang
 * Created on May 12, 2013, 10:17 AM
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

namespace WEIRDFN {
template <class T, size_t MAX, class Comp = less<T> > struct Heap {
  T arr[MAX], *end;
  static Comp comp;

  void clear() {
    end = arr;
  }

  void push(T val) {
    *end++ = val;
    push_heap(arr, end, comp);
  }

  T top() const {
    return *arr;
  }

  void pop() {
    pop_heap(arr, end--, comp);
  }

  int size() {
    return end - arr;
  }

};

#define MOD 1000000007
typedef long long llong;
Heap<int, 111000> left;
Heap<int, 111000, greater<int> > right;

void solve(int test_num) {
  int n;
  llong a, b, c;
  scanf("%lld %lld %lld %d", &a, &b, &c, &n);
  left.clear();
  right.clear();
  left.push(1);
  long long res = 1;
  for (int i = 2, next; i <= n; i++) {
    next = int((a * left.top() + b * i + c) % MOD);
    if (next > left.top()) {
      right.push(next);
      if (i & 1) {
        left.push(right.top());
        right.pop();
      }
    }
    else {
      left.push(next);
      if (~i & 1) {
        right.push(left.top());
        left.pop();
      }
    }
    //pln(left.size(), right.size());
    res += next;
    //if (res >= MOD) res -= MOD;
  }
  cout << res << endl;
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  srand(time(NULL));
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  WEIRDFN::solve();
  return 0;
}

