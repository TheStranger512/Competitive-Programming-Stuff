/* Solved
 * 15376. Running Median
 * File:   RMID.cpp
 * Author: Andy Y.F. Huang
 * Created on July 22, 2013, 1:09 PM
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

namespace RMID {

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

  bool empty() {
    return end == arr;
  }
} ;

Heap<int, 55555 > left;
Heap<int, 55555, greater<int> > right;
int n;

void solve(int test_num) {
  left.clear();
  right.clear();
  left.push(-1);
  right.push((1u << 31) - 1);
  left.push(n);
  while (true) {
    scanf("%d", &n);
    if (n == 0) break;
    if (n == -1) {
      printf("%d\n", left.top());
      left.pop();
      if (right.size() > left.size()) {
        left.push(right.top());
        right.pop();
      }
    }
    else {
      if (right.size() < left.size())
        right.push(n);
      else
        left.push(n);
      if (left.top() > right.top()) {
        int temp = left.top();
        left.pop();
        left.push(right.top());
        right.pop();
        right.push(temp);
      }
    }
  }
  puts("");
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (scanf("%d", &n) != EOF)
    solve(1);
}
}

int main() {
  RMID::solve();
  return 0;
}

