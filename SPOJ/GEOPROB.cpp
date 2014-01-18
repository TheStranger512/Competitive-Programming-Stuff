/* Solved
 * 2901. One Geometry Problem
 * File:   GEOPROB.cpp
 * Author: Andy Y.F. Huang
 * Created on January 3, 2013, 11:00 PM
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
namespace GEOPROB {

template <size_t k_maxlen> class BigUInt {
  int len_m_;
  char digits_m_[k_maxlen];

  void addDigits(const BigUInt& a, const BigUInt& b) {
    len_m_ = max(a.len_m_, b.len_m_);
    int carry = 0;
    for (int i = 0; i < len_m_; i++) {
      digits_m_[i] = carry + a.digits_m_[i] + b.digits_m_[i];
      carry = digits_m_[i] / 10, digits_m_[i] %= 10;
    }
    if (carry > 0) digits_m_[len_m_++] = carry;
  }

  void subtractDigits(const BigUInt& a, const BigUInt& b) {
    len_m_ = max(a.len_m_, b.len_m_);
    for (int i = 0, borrow = 0; i < len_m_; i++) {
      digits_m_[i] = a.digits_m_[i] - borrow - b.digits_m_[i];
      if (digits_m_[i] < 0) borrow = 1, digits_m_[i] += 10;
      else borrow = 0;
    }
    normalize();
  }

  void normalize() {
    while (len_m_ > 1 && digits_m_[len_m_ - 1] == 0) len_m_--;
  }

public:

  BigUInt(const char* str, int len) : len_m_(0) {
    memset(digits_m_, 0, k_maxlen);
    for (int i = len - 1; i >= 0; i--)
      digits_m_[len_m_++] = str[i] - '0';
    normalize();
  }

  BigUInt(int num) : len_m_(0) {
    if (num == 0) len_m_ = 1;
    memset(digits_m_, 0, k_maxlen);
    while (num > 0) digits_m_[len_m_++] = num % 10, num /= 10;
  }

  BigUInt() : len_m_(1) {
    memset(digits_m_, 0, k_maxlen);
  }

  BigUInt(const BigUInt& x) : len_m_(x.len_m_) {
    memcpy(digits_m_, x.digits_m_, k_maxlen);
  }

  BigUInt& operator=(const BigUInt& x) {
    len_m_ = x.len_m_, memcpy(digits_m_, x.digits_m_, k_maxlen);
    return *this;
  }

  BigUInt operator+(const BigUInt& x) const {
    return add(*this, x);
  }

  BigUInt& operator+=(const BigUInt& x) {
    return *this = add(*this, x);
  }

  static BigUInt add(const BigUInt& a, const BigUInt& b) {
    BigUInt ans;
    ans.addDigits(a, b);
    return ans;
  }

  BigUInt operator-(const BigUInt& x) const {
    return subtract(*this, x);
  }

  BigUInt& operator-=(const BigUInt& x) {
    return *this = subtract(*this, x);
  }

  static BigUInt subtract(const BigUInt& a, const BigUInt& b) {
    BigUInt ans;
    ans.subtractDigits(a, b);
    return ans;
  }

  void print() const {
    for (int i = len_m_ - 1; i >= 0; i--) putchar(digits_m_[i] + '0');
  }
} ;

typedef BigUInt < 300 > Int;
char x[222], y[222], z[222];
Int b, c, d;

void solve(int test_num) {
  scanf("%s %s %s", x, y, z);
  b = Int(x, strlen(x));
  c = Int(y, strlen(y));
  d = Int(z, strlen(z));
  ((c - b) + (c - d)).print();
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
  GEOPROB::solve();
  return 0;
}

