/* Solved
 * 867. Perfect Cubes
 * File:   CUBES.cpp
 * Author: Andy Y.F. Huang
 * Created on April 13, 2013, 2:18 PM
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

namespace CUBES {
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

Vector<int, 111> cubes;

void solve(int test_num) {
  for (int i = 2; i <= 100; i++)
    cubes.push_back(i * i * i);
  for (int i = 4; i <= 100; i++) {
    for (int j = 0; j < cubes.size(); j++)
      for (int k = j + 1; k < cubes.size(); k++) {
        int pos = lower_bound(cubes.begin() + k + 1, cubes.end(), cubes[i] - cubes[j] - cubes[k]) - cubes.begin();
        if (pos < cubes.size() && cubes[pos] == cubes[i] - cubes[j] - cubes[k])
          printf("Cube = %d, Triple = (%d,%d,%d)\n", i + 2, j + 2, k + 2, pos + 2);
      }
  }
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
  CUBES::solve();
  return 0;
}

