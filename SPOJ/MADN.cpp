/* Solved
 * 13078. The Mad Numerologist
 * File:   MADN.cpp
 * Author: Andy Y.F. Huang
 * Created on April 23, 2013, 8:59 PM
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

namespace MADN {

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

  T * begin() {
    return dq + head;
  }

  T * end() {
    return dq + tail;
  }
} ;
char ans[255];

bool vowel(char c) {
  return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

void solve(int test_num) {
  Deque<char, 555 > vows, cons;
  int n;
  scanf("%d", &n);
  printf("Case %d: ", test_num);
  for (int i = 0; i < n; i++) {
    if (i & 1) cons.push_back(ans[i]);
    else vows.push_back(ans[i]);
  }
  sort(vows.begin(), vows.end());
  sort(cons.begin(), cons.end());
  for (int i = 0; i < n; i++) {
    if (i & 1) {
      putchar(cons.front());
      cons.pop_front();
    }
    else {
      putchar(vows.front());
      vows.pop_front();
    }
  }
  putchar('\n');
}

int val(char c) {
  return (c - 'A') % 9 + 1;
}

bool cmp(char a, char b) {
  if (val(a) != val(b)) return val(a) < val(b);
  else return a < b;
}

void init() {
  Deque <char, 555 > vows, cons;
  for (int i = 0; i < 21; i++) {
    vows.push_back('A');
    vows.push_back('E');
    vows.push_back('I');
    vows.push_back('O');
    vows.push_back('U');
  }
  for (int i = 0; i < 5; i++)
    for (char c = 'B'; c <= 'Z'; c++)
      if (!vowel(c))
        cons.push_back(c);
  sort(vows.begin(), vows.end(), cmp);
  sort(cons.begin(), cons.end(), cmp);
  for (int i = 0; ; i++) {
    if (i & 1) {
      if (cons.empty())
        break;
      ans[i] = cons.front();
      cons.pop_front();
    }
    else {
      if (vows.empty())
        break;
      ans[i] = vows.front();
      vows.pop_front();
    }
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  init();
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  MADN::solve();
  return 0;
}

