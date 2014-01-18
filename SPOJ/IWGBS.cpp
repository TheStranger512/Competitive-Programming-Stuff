/* Solved
 * 10676. 0110SS
 * fib numbers again
 * File:   IWGBS.cpp
 * Author: Andy Y.F. Huang
 * Created on September 23, 2012, 1:01 AM
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

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace IWGBS {

class BigUInt {
  static const int k_maxlen = 2500;
  int len_m_;
  char* digits_m_;

  void addDigits(const BigUInt& a, const BigUInt& b) {
    len_m_ = max(a.len_m_, b.len_m_);
    int carry = 0;
    for (int i = 0; i < len_m_; i++) {
      digits_m_[i] = carry + a.digits_m_[i] + b.digits_m_[i];
      carry = digits_m_[i] / 10, digits_m_[i] %= 10;
    }
    if (carry > 0) digits_m_[len_m_++] = carry;
  }

public:

  BigUInt(const char* str, int len) : len_m_(0), digits_m_(new char[k_maxlen]) {
    memset(digits_m_, 0, sizeof (char) * k_maxlen);
    for (int i = len - 1; i >= 0; i--)
      digits_m_[len_m_++] = str[i] - '0';
  }

  BigUInt(int num) : len_m_(0), digits_m_(new char[k_maxlen]) {
    if (num == 0) len_m_ = 1;
    digits_m_ = new char[k_maxlen];
    memset(digits_m_, 0, sizeof (char) * k_maxlen);
    while (num > 0) digits_m_[len_m_++] = num % 10, num /= 10;
  }

  BigUInt() : len_m_(1), digits_m_(new char[k_maxlen]) {
    memset(digits_m_, 0, sizeof (char) * k_maxlen);
  }

  BigUInt(const BigUInt& x) : len_m_(x.len_m_), digits_m_(new char[k_maxlen]) {
    memcpy(digits_m_, x.digits_m_, k_maxlen);
  }

  ~BigUInt() {
    delete [] digits_m_;
  }

  BigUInt& operator=(const BigUInt& x) {
    len_m_ = x.len_m_, memcpy(digits_m_, x.digits_m_, k_maxlen);
    return *this;
  }

  bool operator<(const BigUInt& x) const {
    return compareTo(x) < 0;
  }

  int compareTo(const BigUInt& x) const {
    if (len_m_ != x.len_m_) return len_m_ - x.len_m_;
    for (int i = len_m_ - 1; i >= 0; i--)
      if (digits_m_[i] != x.digits_m_[i])
        return digits_m_[i] - x.digits_m_[i];
    return 0;
  }

  BigUInt operator+(const BigUInt& x) const {
    return add(*this, x);
  }

  BigUInt& operator+=(const BigUInt& x) {
    addDigits(*this, x);
    return *this;
  }

  static BigUInt add(const BigUInt& a, const BigUInt& b) {
    BigUInt ans;
    ans.addDigits(a, b);
    return ans;
  }

  friend ostream& operator<<(ostream& out, const BigUInt& num)  {
    for (int i = num.len_m_ - 1; i >= 0; i--)
      out << char(num.digits_m_[i] + '0');
    return out;
  }

  int length() const {
    return len_m_;
  }

  int operator[](int pos) const {
    return (int) digits_m_[pos];
  }

  void print() const {
    for (int i = len_m_ - 1; i >= 0; i--) putchar(digits_m_[i] + '0');
  }

  void debug() const {
    cout << "Len: " << len_m_ << ": ";
    for (int i = len_m_ - 1; i >= 0; i--)
      cout << int(digits_m_[i]) << ',';
    cout << endl;
  }

  string toString() const {
    stringstream ss;
    for (int i = len_m_ - 1; i >= 0; i--) ss << (char) (digits_m_[i] + 0);
    return ss.str();
  }
} ;

int n;
BigUInt fib[10010];

void solve(int test_num) {
  for (int i = 2; i <= n; i++)
    fib[i] += fib[i - 1] + fib[i - 2];
  fib[n].print();
  putchar('\n');
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  fib[0] = 1, fib[1] = 2;
  scanf("%d", &n);
  solve(1);
}
}

int main() {
  IWGBS::solve();
  return 0;
}

