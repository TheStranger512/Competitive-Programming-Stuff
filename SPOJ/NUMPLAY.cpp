/* Solved
 * 11300. Fun with numbers
 * File:   NUMPLAY.cpp
 * Author: Andy Y.F. Huang
 * Created on January 6, 2013, 10:16 PM
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

namespace NUMPLAY {

template <size_t MAXLEN> class BigUInt {
  static const int BASE = 1000000000;
  int len, digits[MAXLEN];

  void normalize() {
    while (len > 1 && digits[len - 1] == 0) len--;
  }

public:

  //TODO: make string constructor
  //  BigUInt(const char* str, int _len) : len(0) {
  //    //memset(digits, 0, MAXLEN);
  //    for (int i = _len - 1; i >= 0; i--)
  //      digits[len++] = str[i] - '0';
  //    normalize();
  //  }

  BigUInt(long long num) : len(0) {
    if (num == 0) len = 1;
    memset(digits, 0, sizeof (digits));
    for (; num > 0; num /= BASE)
      digits[len++] = num % BASE;
  }

  BigUInt(int num) : len(0) {
    if (num == 0) len = 1;
    memset(digits, 0, sizeof (digits));
    for (; num > 0; num /= BASE)
      digits[len++] = num % BASE;
  }

  BigUInt() : len(1) {
    memset(digits, 0, sizeof (digits));
  }

  BigUInt operator+(const BigUInt& x) const {
    BigUInt res = *this;
    return res += x;
  }

  BigUInt& operator+=(const BigUInt& x) {
    if (x.len > len) len = x.len;
    for (int i = 0; i < len; i++) {
      digits[i] += x.digits[i];
      if (digits[i] >= BASE) digits[i] -= BASE, digits[i + 1]++;
    }
    if (digits[len] > 0) len++;
    return *this;
  }

  BigUInt operator*(const BigUInt& x) const {
    BigUInt res = *this;
    return res *= x;
  }

  BigUInt& operator*=(const BigUInt& x) {
    static long long temp[MAXLEN];
    memset(temp, 0, sizeof (long long) * (len + x.len));
    for (int i = 0; i < len; i++) {
      for (int j = 0, m = i; j < x.len; j++, m++) {
        temp[m] += (long long) (digits[i]) * x.digits[j];
        temp[m + 1] += temp[m] / BASE;
        temp[m] %= BASE;
      }
    }
    len += x.len;
    for (int i = 0; i < len; i++)
      digits[i] = (int) temp[i];
    normalize();
    return *this;
  }

  friend ostream& operator<<(ostream& out, const BigUInt& num)  {
    out << num.digits[num.len - 1];
    for (int i = num.len - 2; i >= 0; i--)
      out << setw(9) << setfill('0') << num.digits[i];
    return out;
  }

  int length() const {
    return len;
  }

  int operator[](int pos) const {
    return digits[pos];
  }

  void print() const {
    printf("%d", digits[len - 1]);
    for (int i = len - 2; i >= 0; i--) printf("%09d", digits[i]);
  }

  void debug() const {
    cout << "Len: " << len << ": ";
    for (int i = len - 1; i >= 0; i--)
      cout << digits[i] << ',';
    cout << endl;
  }
} ;

template <class T, size_t MAXSIZE> struct Matrix {
  int size;
  T data[MAXSIZE][MAXSIZE];

  Matrix(int size = MAXSIZE) : size(size) {
    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++)
        data[i][j] = 0;
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
      for (int j = 0; j < size; j++) {
        temp[i][j] = 0;
        for (int k = 0; k < size; k++)
          temp[i][j] += data[i][k] * other.data[k][j];
      }
    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++)
        data[i][j] = temp[i][j];
    return *this;
  }

  Matrix operator^(long long exponent) const {
    Matrix ans = *this;
    return ans ^= exponent;
  }

  Matrix& operator^=(long long expon) {
    Matrix temp = *this;
    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++)
        data[i][j] = 0;
    for (int i = 0; i < size; i++) data[i][i] = 1;
    for ( ; expon > 0; expon >>= 1) {
      if (expon & 1) * this *= temp;
      temp *= temp;
    }
    return *this;
  }
} ;

typedef BigUInt < 250 > Int;
Matrix<Int, 4 > base[14];

void solve(int test_num) {
  int len;
  scanf("%d", &len);
  if (len == 0) {
    puts("0");
    return;
  }
  Matrix<Int, 4 > res;
  len--;
  for (int i = 0; i < 4; i++)
    res[i][i] = 1;
  for (int i = 0; i < 14; i++)
    if (1 << i & len)
      res *= base[i];
  //plnarr(res.data, 4, 4);
  Int ans = 0;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      ans += res[i][j];
  ans.print();
  putchar('\n');
}

void init() {
  //[1, 3, 5, 7]
  //[0, 1, 2, 3]
  /*
   * 1 -> 3
   * 3 -> 1
   * 3 -> 5
   * 5 -> 7
   * 7 -> 5
   * 7 -> 3
   */
  Int one(1);
  base[0][0][1] = one;
  base[0][1][0] = one;
  base[0][1][2] = one;
  base[0][2][3] = one;
  base[0][3][2] = one;
  base[0][3][1] = one;
  for (int i = 1; i < 14; i++)
    base[i] = base[i - 1] * base[i - 1];
  //plnarr(base[1].data, 4, 4);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
//  Int a(999999999);
//  a += 1;
//  pln(a);
  init();
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  NUMPLAY::solve();
  return 0;
}

