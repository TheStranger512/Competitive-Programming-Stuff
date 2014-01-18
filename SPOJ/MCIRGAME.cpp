/* Solved
 * 3932. Point Connection Game in a Circle
 * File:   MCIRGAME.cpp
 * Author: Andy Y.F. Huang
 * Created on April 19, 2013, 10:31 PM
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

namespace MCIRGAME {

template <size_t MAXLEN> class BigUInt {
  int len;
  char digits[MAXLEN];

  void addDigits(const BigUInt& a, const BigUInt& b) {
    len = max(a.len, b.len);
    int carry = 0;
    for (int i = 0; i < len; i++) {
      digits[i] = carry + a.digits[i] + b.digits[i];
      carry = digits[i] / 10, digits[i] %= 10;
    }
    if (carry > 0) digits[len++] = carry;
  }

  void subtractDigits(const BigUInt& a, const BigUInt& b) {
    len = max(a.len, b.len);
    for (int i = 0, borrow = 0; i < len; i++) {
      digits[i] = a.digits[i] - borrow - b.digits[i];
      if (digits[i] < 0) borrow = 1, digits[i] += 10;
      else borrow = 0;
    }
    normalize();
  }

  void shiftLeft(int amount) {
    if (len == 1 && digits[0] == 0) return;
    memmove(digits + len, digits + len - amount, amount);
    memset(digits, 0, amount);
    len += amount;
  }

  void shiftRight(int amount) {
    len -= amount;
    if (len <= 0) len = 1;
    memcpy(digits, digits + amount, len);
    memset(digits + len, 0, amount);
  }

  void normalize() {
    while (len > 1 && digits[len - 1] == 0) len--;
  }

public:

  BigUInt(const char* str, int _len) : len(0) {
    memset(digits, 0, MAXLEN);
    for (int i = _len - 1; i >= 0; i--)
      digits[len++] = str[i] - '0';
    normalize();
  }

  BigUInt(int num) : len(0) {
    if (num == 0) len = 1;
    memset(digits, 0, MAXLEN);
    while (num > 0) digits[len++] = num % 10, num /= 10;
  }

  BigUInt() : len(1) {
    memset(digits, 0, MAXLEN);
  }

  BigUInt(const BigUInt& x) : len(x.len) {
    memcpy(digits, x.digits, MAXLEN);
  }

  BigUInt& operator=(const BigUInt& x) {
    len = x.len, memcpy(digits, x.digits, MAXLEN);
    return *this;
  }

  bool operator<(const BigUInt& x) const {
    return compareTo(x) < 0;
  }

  int compareTo(const BigUInt& x) const {
    if (len != x.len) return len - x.len;
    for (int i = len - 1; i >= 0; i--)
      if (digits[i] != x.digits[i])
        return digits[i] - x.digits[i];
    return 0;
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

  BigUInt operator*(const BigUInt& x) const {
    return multiply(*this, x);
  }

  BigUInt& operator*=(const BigUInt& x) {
    return *this = multiply(*this, x);
  }

  static BigUInt multiply(const BigUInt& a, const BigUInt& b) {
    BigUInt ans;
    ans.len = a.len + b.len;
    for (int i = 0; i < b.len; i++) {
      for (int j = 0; j < a.len; j++) {
        ans.digits[i + j] += b.digits[i] * a.digits[j];
        ans.digits[i + j + 1] += ans.digits[i + j] / 10;
        ans.digits[i + j] %= 10;
      }
    }
    ans.normalize();
    return ans;
  }

  BigUInt operator<<(int amount) const {
    BigUInt ans(*this);
    ans.shiftLeft(amount);
    return ans;
  }

  BigUInt& operator<<=(int amount) {
    shiftLeft(amount);
    return *this;
  }

  BigUInt operator>>(int amount) const {
    BigUInt ans(*this);
    ans.shiftRight(amount);
    return ans;
  }

  BigUInt& operator>>=(int amount) {
    shiftRight(amount);
    return *this;
  }

  BigUInt operator/(const BigUInt& x) const {
    return divideAndMod(*this, x).first;
  }

  BigUInt& operator/=(const BigUInt& x) {
    return *this = divideAndMod(*this, x).first;
  }

  BigUInt operator%(const BigUInt& x) const {
    return divideAndMod(*this, x).second;
  }

  BigUInt& operator%=(const BigUInt& x) {
    return *this = divideAndMod(*this, x).second;
  }

  static pair<BigUInt, BigUInt> divideAndMod(const BigUInt& a, const BigUInt& b) {
    if (a.compareTo(b) < 0) return make_pair(BigUInt(0), a);
    pair<BigUInt, BigUInt> ans(BigUInt(0), BigUInt(0));
    BigUInt &quot = ans.first, &rem = ans.second;
    for (int i = a.len - 1; i >= 0; i--) {
      rem.shiftLeft(1), rem.digits[0] = a.digits[i];
      while (rem.compareTo(b) >= 0)
        quot.digits[i]++, rem.subtractDigits(rem, b);
    }
    quot.len = a.len, quot.normalize();
    return ans;
  }

  friend ostream& operator<<(ostream& out, const BigUInt& num)  {
    for (int i = num.len - 1; i >= 0; i--)
      out << char(num.digits[i] + '0');
    return out;
  }

  int length() const {
    return len;
  }

  int operator[](int pos) const {
    return (int) digits[pos];
  }

  void print() const {
    for (int i = len - 1; i >= 0; i--) putchar(digits[i] + '0');
  }

  void debug() const {
    cout << "Len: " << len << ": ";
    for (int i = len - 1; i >= 0; i--)
      cout << int(digits[i]) << ',';
    cout << endl;
  }

  string toString() const {
    stringstream ss;
    for (int i = len - 1; i >= 0; i--) ss << (char) (digits[i] + 0);
    return ss.str();
  }
} ;

typedef BigUInt < 1111 > Int;
Int ans[155]; //catalan number

void solve(int test_num) {
  int n;
  while (scanf("%d", &n) != EOF) {
    if (n == -1) break;
    ans[n].print();
    putchar('\n');
  }
 }

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  ans[0] = 1;
  for (int i = 1; i <= 150; i++)
    for (int j = 0; j < i; j++)
      ans[i] += ans[j] * ans[i - j - 1];
  solve(1);
}
}

int main() {
  MCIRGAME::solve();
  return 0;
}

