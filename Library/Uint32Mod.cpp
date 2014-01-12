#include "Azn.cpp"

template <int MOD> struct Uint32Mod {
  int val;

  Uint32Mod() : val(0) { }

  Uint32Mod(long long x) : val(x % MOD) {
    if (val < 0) val += MOD;
  }

  Uint32Mod& operator+=(const Uint32Mod & x) {
    val += x.val;
    if (val >= MOD) val -= MOD;
    return *this;
  }

  Uint32Mod operator+(const Uint32Mod & x) const {
    Uint32Mod res(*this);
    return res += x;
  }

  Uint32Mod& operator-=(const Uint32Mod & x) {
    val -= x.val;
    if (val < 0) val += MOD;
    return *this;
  }

  Uint32Mod operator-(const Uint32Mod & x) const {
    Uint32Mod res(*this);
    return res -= x;
  }

  Uint32Mod& operator*=(const Uint32Mod & x) {
    val = (long long) (val) * x.val % MOD;
    return *this;
  }

  Uint32Mod operator*(const Uint32Mod & x) const {
    Uint32Mod res(*this);
    return res *= x;
  }

  Uint32Mod& operator/=(const Uint32Mod & x) {
    return *this *= x.inv();
  }

  Uint32Mod operator/(const Uint32Mod & x)  const {
    Uint32Mod res(*this);
    return res /= x;
  }

  Uint32Mod power(long long expon) const {
    Uint32Mod ans, temp(*this);
    ans.val = 1;
    for (; expon > 0; expon >>= 1) {
      if (expon & 1) ans *= temp;
      temp *= temp;
    }
    return ans;
  }

  Uint32Mod inv() const {
    return power(MOD - 2);
  }

  friend ostream& operator<<(ostream& out, Uint32Mod & x) {
    return out << x.val;
  }

} ;
