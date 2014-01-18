/* Solved
 * 13082. BINARY CHALLENGE
 * File:   GOV01.cpp
 * Author: Andy Y.F. Huang
 * Created on December 28, 2012, 6:27 PM
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
namespace GOV01 {

template <class T> class Matrix {
  static const int k_max_size = 2;
  int size;
  T data[k_max_size][k_max_size], mod;

public:

  Matrix(int size, T mod) : size(size), mod(mod) {
    memset(data, 0, sizeof (data));
  }

  T* operator[](int row) {
    return data[row];
  }

  const T* operator[](int row) const {
    return data[row];
  }

  int getSize() const {
    return size;
  }

  Matrix operator*(const Matrix& other) const {
    Matrix ans(size, mod);
    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++)
        for (int k = 0; k < size; k++)
          ans[i][j] = (ans[i][j] + data[i][k] * other[k][j]) % mod;
    return ans;
  }

  Matrix& operator*=(const Matrix& other) {
    return *this = *this * other;
  }

  Matrix operator^(int exponent) const {
    Matrix ans(size, mod), temp = *this;
    for (int i = 0; i < size; i++)
      ans[i][i] = 1;
    while (exponent > 0) {
      if (exponent & 1) ans *= temp;
      temp *= temp;
      exponent >>= 1;
    }
    return ans;
  }

  Matrix& operator^=(int exponent) {
    return *this = *this ^ exponent;
  }

  friend ostream& operator<<(ostream& out, const Matrix& m) {
    for (int i = 0; i < m.size; i++, out << "|\n") {
      out << "|";
      for (int j = 0; j < m.size; j++) {
        if (j) out << ',';
        out << setw(6) << m[i][j];
      }
    }
    return out;
  }
} ;


void solve(int test_num) {
  int n, mod;
  scanf("%d %d", &n, &mod);
  Matrix<long long> mat(2, mod);
  mat[0][0] = mat[0][1] = mat[1][0] = 1;
  mat ^= n + 3;
  printf("%lld\n", (mat[0][0] - 3 + mod) % mod);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  GOV01::solve();
  return 0;
}

