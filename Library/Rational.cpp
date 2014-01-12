

template <class T> struct Rational {
  T num, den;

  Rational(T a = 0, T b = 1) : num(a), den(b) {
    normalize();
  }

  void normalize() {
    T g = __gcd(num, den);
    num /= g;
    den /= g;
    if (den < 0) {
      num = -num;
      den = -den;
    }
    if (den == 0) num /= den;
    if (num == 0) den = 1;
  }

  double val() const {
    return double(num) / den;
  }

  bool operator<(const Rational & x) const {
    return num * x.den < den * x.num;
  }

  bool operator==(const Rational & x) const {
    return num * x.den == den * x.num;
  }

  Rational operator*(const Rational & x) const {
    return Rational(num * x.num, den * x.den);
  }

  Rational operator/(const Rational & x) const {
    return Rational(num * x.den, den * x.num);
  }

  Rational operator-(const Rational & x) const {
    return Rational(num * x.den - den * x.num, den * x.den);
  }

  Rational operator+(const Rational & x) const {
    return Rational(num * x.den + den * x.num, den * x.den);
  }

  friend ostream& operator<<(ostream& out, const Rational & x) {
    return out << '(' << x.num << '/' << x.den << ')';
  }
} ;