/* Solved
 * IOI '13 - Brisbane, Australia
 * Robots
 * File:   ioi1322.cpp
 * Author: Andy Y.F. Huang
 * Created on July 28, 2013, 4:31 PM
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

namespace ioi1322 {
const unsigned int buffer_size = 1 << 16;
char input_buffer[buffer_size];
unsigned int bytes_read = 0;
unsigned int input_index = 0;

inline char next_char() {
  if (input_index == bytes_read) {
    bytes_read = fread(input_buffer, sizeof (char) , buffer_size, stdin);
    input_buffer[bytes_read] = '\0'; //sentinel
    input_index = 0;
  }
  return input_buffer[input_index++];
}

inline int next_int() {
  char c = 0;
  int ans = 0;
  while (c < '-') c = next_char();
  for (; c >= '0'; c = next_char()) ans = (ans << 1) + (ans << 3) + c - '0';
  return ans;
}

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

typedef pair<int, int> Toy; //(weight, size)
int A, B, T;
int x[50555], y[50555];
Toy t[1000111];
Heap<int, 1000111> heap;

bool poss(int S) {
  heap.clear();
  //each robot at most S toys
  int j = 0;
  for (int i = 0; i < A; i++) {
    int cnt = 0;
    for ( ; j < T && t[j].first < x[i]; j++)
      heap.push(t[j].second);
    while (!heap.empty() && cnt < S) {
      //pln(heap.top());
      heap.pop();
      cnt++;
    }
    //pln();
  }
  for (; j < T; j++)
    heap.push(t[j].second);
  for (int i = B - 1; i >= 0; i--) {
    int cnt = 0;
    while (!heap.empty() && cnt < S && heap.top() < y[i]) {
      heap.pop();
      cnt++;
    }
  }
  return heap.empty();
}

void solve(int test_num) {
  A = next_int();
  B = next_int();
  T = next_int();
  for (int i = 0; i < A; i++)
    x[i] = next_int();
  for (int i = 0; i < B; i++)
    y[i] = next_int();
  for (int i = 0; i < T; i++) {
    t[i].first = next_int();
    t[i].second = next_int();
  }
  sort(x, x + A);
  sort(y, y + B);
  sort(t, t + T);
  int res = -1;
  for (int l = 1, h = T, m; l <= h; ) {
    m = (l + h) >> 1;
    if (poss(m)) {
      res = m;
      h = m - 1;
    }
    else l = m + 1;
  }
  printf("%d\n", res);
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
  ioi1322::solve();
  return 0;
}

