/* Solved
 * 11181. Build the Tower
 * File:   BUILDTOW.cpp
 * Author: Andy Y.F. Huang
 * Created on September 3, 2012, 11:58 AM
 */

#include <cstdio>
#include <iostream>
#include <iomanip>
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

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace BUILDTOW {

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

const int k_coefs[2][2] = {
  {1, 1},
  {1, 0}
};
const int k_mod = 1000000007;

long long absmod(long long num) {
  num %= k_mod;
  return num < 0 ? num + k_mod : num;
}

void solve(int test_num) {
  long long n;
  scanf("%lld", &n);
  if (n == 0) {
    puts("$0");
    return;
  }
  if (n == 1) {
    puts("$1");
    return;
  }
  Matrix id(2, k_mod);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      id[i][j] = k_coefs[i][j];
  id ^= n + 1;
  printf("$%lld\n", absmod(id[0][0] * id[1][0] - 1));
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
  BUILDTOW::solve();
  return 0;
}

