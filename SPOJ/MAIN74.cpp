/* Solved
 * 8547. Euclids algorithm revisited - fib numbers
 * File:   MAIN74.cpp
 * Author: Andy Y.F. Huang
 * Created on September 23, 2012, 12:44 AM
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
#include <fstream>
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <cassert>
#include <iomanip>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace MAIN74 {

class Matrix {
  static const int k_max_size = 2;
  int size_m_, mod_m_;
  long long data_m_[k_max_size][k_max_size];

public:

  Matrix(int size, int mod) : size_m_(size), mod_m_(mod) {
    memset(data_m_, 0, sizeof (data_m_));
  }

  long long* operator[](int row) {
    return data_m_[row];
  }

  const long long* operator[](int row) const {
    return data_m_[row];
  }

  int size() const {
    return size_m_;
  }

  Matrix operator*(const Matrix& other) const {
    Matrix ans(size_m_, mod_m_);
    for (int i = 0; i < size_m_; i++) {
      for (int j = 0; j < size_m_; j++) {
        for (int k = 0; k < size_m_; k++) {
          ans[i][j] += data_m_[i][k] * other[k][j];
          if (ans[i][j] >= mod_m_)
            ans[i][j] %= mod_m_;
        }
      }
    }
    return ans;
  }

  Matrix& operator*=(const Matrix& other) {
    return *this = *this * other;
  }

  Matrix operator^(long long exponent) const {
    Matrix ans(size_m_, mod_m_), temp = *this;
    for (int i = 0; i < size_m_; i++)
      ans[i][i] = 1;
    while (exponent > 0) {
      if (exponent & 1) ans *= temp;
      temp *= temp;
      exponent >>= 1;
    }
    return ans;
  }

  Matrix& operator^=(long long exponent) {
    return *this = *this ^ exponent;
  }

  friend ostream& operator<<(ostream& out, const Matrix& m) {
    for (int i = 0; i < m.size_m_; i++, out << "|\n") {
      out << "|";
      for (int j = 0; j < m.size_m_; j++) {
        if (j) out << ',';
        out << setw(6) << m[i][j];
      }
    }
    return out;
  }
} ;

const int k_mod = 1000000007;

void solve(int test_num) {
  long long n;
  scanf("%lld", &n);
  if (n == 0) {
    puts("0");
    return;
  }
  if (n == 1) {
    puts("2");
    return;
  }
  Matrix fib(2, k_mod);
  fib[0][0] = fib[0][1] = fib[1][0] = 1;
  fib ^= n + 2;
  printf("%lld\n", fib[0][0]);
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
  MAIN74::solve();
  return 0;
}

