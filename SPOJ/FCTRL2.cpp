/* Solved
 * 24. Small factorials
 * File:   FCTRL2.cpp
 * Author: Andy Y.F. Huang
 * Created on August 29, 2012, 2:22 PM
 */

#include <cstdio>
#include <cstring>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

class BigInt {
  static const int k_maxlen = 200;
  int len_m_, signum_m_;
  char* digits_m_;

  inline void clear() {
    memset(digits_m_, 0, sizeof (char) * k_maxlen);
  }

  static BigInt multiply(const BigInt& x, const BigInt& y) {
    BigInt ans;
    if (x.signum_m_ == 0 || y.signum_m_ == 0) return ans;
    ans.signum_m_ = x.signum_m_ == y.signum_m_ ? 1 : -1;
    ans.len_m_ = x.len_m_ + y.len_m_;
    for (int i = 0; i < y.len_m_; i++) {
      for (int j = 0; j < x.len_m_; j++) {
        ans.digits_m_[i + j] += y.digits_m_[i] * x.digits_m_[j];
        ans.digits_m_[i + j + 1] += ans.digits_m_[i + j] / 10;
        ans.digits_m_[i + j] %= 10;
      }
    }
    while (ans.digits_m_[ans.len_m_ - 1] == 0) ans.len_m_--;
    return ans;
  }

public:

  BigInt(int num) : len_m_(0), signum_m_((num > 0) - (num < 0)) {
    if (num == 0) len_m_ = 1;
    digits_m_ = new char[k_maxlen], num = abs(num);
    clear();
    while (num > 0) digits_m_[len_m_++] = num % 10, num /= 10;
  }

  BigInt() : len_m_(1), signum_m_(0), digits_m_(new char[k_maxlen]) {
    clear();
  }

  BigInt(const BigInt& x) : len_m_(x.len_m_), signum_m_(x.signum_m_) {
    digits_m_ = new char[k_maxlen], memcpy(digits_m_, x.digits_m_, k_maxlen);
  }

  ~BigInt() {
    delete [] digits_m_;
  }

  BigInt& operator=(const BigInt& x) {
    len_m_ = x.len_m_, signum_m_ = x.signum_m_;
    memcpy(digits_m_, x.digits_m_, k_maxlen);
    return *this;
  }

  BigInt operator*(const BigInt& x) const {
    return multiply(*this, x);
  }

  BigInt& operator*=(const BigInt& x) {
    return *this = multiply(*this, x);
  }

  void print() const {
    if (signum_m_ == -1) putchar('-');
    for (int i = len_m_ - 1; i >= 0; i--)
      putchar(digits_m_[i] + '0');
    putchar('\n');
  }

  void debug() const {
    cout << "Signum: " <<  signum_m_ << ", Len: " << len_m_ << ": ";
    for (int i = 10; i >= 0; i--)
      cout << int(digits_m_[i]) << ',';
    cout << endl;
  }
} ;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace FCTRL2 {
BigInt fact[101];

void init() {
  fact[0] = 1;
  for (int i = 1; i <= 100; i++)
    fact[i] = fact[i - 1] * i;
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  init();
  int tests, n;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++) {
    scanf("%d", &n);
    fact[n].print();
  }
}
}

int main() {
  FCTRL2::solve();
  return 0;
}

