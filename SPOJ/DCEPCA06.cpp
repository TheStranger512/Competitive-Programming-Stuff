/* Solved
 * 12912. Saving BOB
 * File:   DCEPCA06.cpp
 * Author: Andy Y.F. Huang
 * Created on April 1, 2013, 1:13 AM
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

namespace DCEPCA06 {

template <int MOD> struct Integer {
  int val;

  Integer() : val(0) { }

  Integer(long long x) : val(x % MOD) {
    if (val < 0) val += MOD;
  }

  Integer(int x) : val(x % MOD) {
    if (val < 0) val += MOD;
  }

  Integer(Integer & x) : val(x.val) { }

  Integer& operator+=(Integer & x) {
    val += x.val;
    if (val >= MOD) val -= MOD;
    return *this;
  }

  Integer operator+(Integer & x)  {
    Integer res(*this);
    return res += x;
  }

  Integer& operator-=(Integer & x) {
    val -= x.val;
    if (val < 0) val += MOD;
    return *this;
  }

  Integer operator-(Integer & x)  {
    Integer res(*this);
    return res -= x;
  }

  Integer& operator*=(Integer & x) {
    val = (long long) (val) * x.val % MOD;
    return *this;
  }

  Integer operator*(Integer & x)  {
    Integer res(*this);
    return res *= x;
  }

  Integer& operator/=(Integer & x) {
    return *this *= x.inv();
  }

  Integer operator/(Integer & x)  {
    Integer res(*this);
    return res /= x;
  }

  Integer power(long long expon)  {
    Integer ans, temp(*this);
    ans.val = 1;
    for (; expon > 0; expon >>= 1) {
      if (expon & 1) ans *= temp;
      temp *= temp;
    }
    return ans;
  }

  Integer inv()  {
    return power(MOD - 2);
  }

  friend ostream& operator<<(ostream& out, Integer & x) {
    return out << x.val;
  }

} ;

template <class T, size_t MAXSIZE> struct Matrix {
  int size;
  T data[MAXSIZE][MAXSIZE];

  Matrix(int size = MAXSIZE) : size(size) {
    memset(data, 0, sizeof (data));
  }

  T* operator[](int row) {
    return data[row];
  }

  Matrix operator*(Matrix & other) {
    Matrix ans = *this;
    ans *= other;
    return ans;
  }

  Matrix& operator*=(Matrix & other) {
    static T temp[MAXSIZE][MAXSIZE], t;
    memset(temp, 0, sizeof (temp));
    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++)
        for (int k = 0; k < size; k++)
          t = data[i][k] * other[k][j], temp[i][j] += t;
    memcpy(data, temp, sizeof (temp));
    return *this;
  }

  Matrix operator^(long long exponent) {
    Matrix ans = *this;
    ans ^= exponent;
    return ans;
  }

  Matrix& operator^=(long long expon) {
    Matrix temp = *this;
    memset(data, 0, sizeof (data));
    for (int i = 0; i < size; i++)
      data[i][i] = 1;
    for ( ; expon > 0; expon >>= 1) {
      if (expon & 1) * this *= temp;
      temp *= temp;
    }
    return *this;
  }
} ;

#define MOD 1000000007
typedef Integer<MOD> Int;
typedef Matrix<Int, 10 > Mat;

void solve(int test_num) {
  Mat mat, seed;
  int len, lim;
  scanf("%d %d", &len, &lim);
  for (int d = 1; d < 10; d++)
    seed[d][0] = 1;
  for (int d = 0; d < 10; d++)
    for (int dd = 0; dd < 10; dd++)
      if (abs(dd - d) >= lim)
        mat[d][dd] = 1;
  mat ^= len - 1;
  mat *= seed;
  Int ans(0);
  for (int d = 0; d < 10; d++)
    ans += mat[d][0];
  printf("%d\n", ans.val);
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
  DCEPCA06::solve();
  return 0;
}

