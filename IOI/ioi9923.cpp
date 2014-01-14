/* Solved
 * IOI '99 - Antalya-Belek, Turkey
 * A Strip of Land
 * File:   ioi9923.cpp
 * Author: Andy Y.F. Huang
 * Created on May 31, 2013, 2:12 PM
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

namespace ioi9923 {

template <class T, size_t MAXSIZE> struct Deque {
  T dq[MAXSIZE];
  int head, tail;

  Deque(int initpos = 0) {
    head = tail = initpos;
  }

  void clear(int initpos = 0) {
    head = tail = initpos;
  }

  bool empty() const {
    return head == tail;
  }

  int size() const {
    return tail - head;
  }

  void push_back(T val) {
    dq[tail++] = val;
  }

  void push_front(T val) {
    dq[--head] = val;
  }

  void pop_back() {
    tail--;
  }

  void pop_front() {
    head++;
  }

  T front() {
    return dq[head];
  }

  T back() {
    return dq[tail - 1];
  }
} ;

int maxr[777], minr[777];
int arr[722][722];
Deque<int, 722 > high, low;

void solve(int test_num) {
  int rows, cols, lim;
  scanf("%d %d %d", &cols, &rows, &lim);
  for (int r = 1; r <= rows; r++)
    for (int c = 1; c <= cols; c++)
      scanf("%d", arr[r] + c);
  int a, b, c, d, best = 0;
  for (int c1 = 1; c1 <= cols; c1++) {
    memset(maxr, 0xF0, sizeof (maxr));
    memset(minr, 0x3F, sizeof (minr));
    for (int c2 = c1; c2 < c1 + 100 && c2 <= cols; c2++) {
      for (int r = 1; r <= rows; r++) {
        maxr[r] = max(maxr[r], arr[r][c2]);
        minr[r] = min(minr[r], arr[r][c2]);
      }
      if ((c2 - c1 + 1) * rows <= best) continue;
      low.clear();
      high.clear();
      int prevhigh = 1, prevlow = 1;
      for (int r = 1; r <= rows; r++) {
        while (!high.empty() && maxr[r] > maxr[high.back()])
          high.pop_back();
        high.push_back(r);
        while (!low.empty() && minr[r] < minr[low.back()])
          low.pop_back();
        low.push_back(r);
        while (!high.empty() && !low.empty() && maxr[high.front()] - minr[low.front()] > lim) {
          if (high.front() < low.front()) {
            prevhigh = high.front() + 1;
            high.pop_front();
          }
          else {
            prevlow = low.front() + 1;
            low.pop_front();
          }
        }
        int r2 = max(prevlow, prevhigh);
        if ((c2 - c1 + 1) * (r - r2 + 1) > best) {
          a = c1;
          b = r;
          c = c2;
          d = r2;
          best = (c2 - c1 + 1) * (r - r2 + 1);
        }
      }
    }
  }
  printf("%d %d %d %d\n", a, rows - b + 1, c, rows - d + 1);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  solve(1);
}
}

int main() {
  ioi9923::solve();
  return 0;
}

