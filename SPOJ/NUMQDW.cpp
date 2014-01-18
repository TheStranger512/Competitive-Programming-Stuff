/* Solved
 * 411. Number of quite different words
 * File:   NUMQDW.cpp
 * Author: Andy Y.F. Huang
 * Created on April 28, 2013, 1:55 PM
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

namespace NUMQDW {
#define MOD 4242

template <class T, size_t MAXSIZE> struct Matrix {
  int size;
  T data[MAXSIZE][MAXSIZE];

  Matrix(int size = MAXSIZE) : size(size) {
    memset(data, 0, sizeof (data));
  }

  T* operator[](int row) {
    return data[row];
  }

  Matrix operator*(const Matrix & other) const {
    Matrix ans = *this;
    return ans *= other;
  }

  Matrix& operator*=(const Matrix & other) {
    static T temp[MAXSIZE][MAXSIZE];
    for (int i = 0; i < size; i++)
      for (int j = 0, k; j < size; j++)
        for (k = 0, temp[i][j] = 0; k < size; k++)
          temp[i][j] += data[i][k] * other.data[k][j];
    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++)
        data[i][j] = temp[i][j] % MOD;
    return *this;
  }

  Matrix operator^(long long exponent) const {
    Matrix ans = *this;
    return ans ^= exponent;
  }

  Matrix& operator^=(long long expon) {
    Matrix temp = *this;
    memset(data, 0, sizeof (data));
    for (int i = 0; i < size; i++) data[i][i] = 1;
    for ( ; expon > 0; expon >>= 1) {
      if (expon & 1) * this *= temp;
      temp *= temp;
    }
    return *this;
  }
} ;

typedef Matrix<int, 64 > Mat;
char str[11111];
bool bad[6][6];

void solve(int test_num) {
  int len, alpha;
  scanf("%d %d %s", &len, &alpha, str);
  int size = 1 << alpha;
  Mat mat(size);
  memset(bad, false, sizeof (bad));
  for (int i = 0, mask = 0; str[i] > 0; i++) {
    int c = str[i] - 'A';
    for (int j = 0; j < alpha; j++)
      if (1 << j & mask)
        bad[j][c] = true;
    mask |= 1 << c;
  }
  for (int st = 0; st < size; st++) {
    for (int c = 0; c < alpha; c++) {
      bool ok = true;
      for (int a = 0; a < alpha; a++)
        if ((1 << a & st) && bad[a][c])
          ok = false;
      if (ok)
        mat[st][1 << c | st]++;
    }
  }
  //plnarr(mat.data, size, size);
  mat ^= len;
  //plnarr(mat.data, size, size);
  int ans = 0;
  for (int j = 0; j < size; j++) {
    ans += mat[0][j];
    if (ans >= MOD) ans -= MOD;
  }
  cout << ans << endl;
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
  NUMQDW::solve();
  return 0;
}

