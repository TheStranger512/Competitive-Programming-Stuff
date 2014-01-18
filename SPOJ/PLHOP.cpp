/* Solved
 * 698. Plane Hopping
 * File:   PLHOP.cpp
 * Author: Andy Y.F. Huang
 * Created on January 4, 2013, 4:17 PM
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

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace PLHOP {

template <class T, size_t k_max_size> class Matrix {
  int size;
  T data[k_max_size][k_max_size];

public:

  Matrix(int size) : size(size) {
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
    Matrix<T, k_max_size> ans(size);
    memset(ans.data, 0x3F, sizeof (ans.data));
    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++)
        for (int k = 0; k < size; k++)
          ans[i][j] = min(ans[i][j], data[i][k] + other[k][j]);
    return ans;
  }

  Matrix& operator*=(const Matrix& other) {
    return *this = *this * other;
  }

  Matrix operator^(int exponent) const {
    Matrix<T, k_max_size> ans(size), temp = *this;
    memset(ans.data, 0x3F, sizeof (ans.data));
    for (int i = 0; i < size; i++)
      ans[i][i] = 0;
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

typedef long long llong;
typedef Matrix<llong, 50 > MAT;

void solve(int test_num) {
  int size, k;
  scanf("%d %d", &k, &size);
  MAT mat(size);
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      scanf("%lld", &mat[i][j]);
  for (int k = 0; k < size; k++)
    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++)
        mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
  mat ^= k;
  printf("Region #%d:\n", test_num);
  for (int i = 0; i < size; i++, putchar('\n'))
    for (int j = 0; j < size; j++)
      printf("%lld ", mat[i][j]);
  putchar('\n');
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
  PLHOP::solve();
  return 0;
}

