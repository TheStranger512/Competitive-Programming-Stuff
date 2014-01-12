#include "Azn.cpp"

namespace FFT {
typedef complex<double> Comp;
const Comp IOTA(0, 1);
const double PI = acos(-1.0);
Comp temp[8888], a[8888], b[8888];
Comp roots[14][4444], roots2[14][4444];

void init() {
  for (int i = 1; i < 14; i++) {
    Comp step = exp(IOTA * (2 * PI / (1 << i)));
    Comp step2 = exp(IOTA * (2 * PI / -(1 << i)));
    roots[i][0] = Comp(1, 0);
    roots2[i][0] = Comp(1, 0);
    for (int j = 1; j < (1 << i) / 2; j++) {
      roots[i][j] = roots[i][j - 1] * step;
      roots2[i][j] = roots2[i][j - 1] * step2;
    }
  }
}

void fft(Comp *a, int len, int lg, int dir) {
  if (len == 1) return;
  for (int i = 0; i < len; i++)
    temp[i] = a[i];
  for (int i = 0, j = 0; i < len; i += 2, j++) {
    a[j] = temp[i];
    a[(len >> 1) + j] = temp[i + 1];
  }
  fft(a, len >> 1, lg - 1, dir);
  fft(a + (len >> 1), len >> 1, lg - 1, dir);
  //pln(len, dir, step);
  if (dir == 1)
    for (int k = 0, half = (len >> 1); k < half; k++) {
      temp[k] = a[k] + roots[lg][k] * a[half + k];
      temp[k + half] = a[k] - roots[lg][k] * a[half + k];
    }
  else
    for (int k = 0, half = (len >> 1); k < half; k++) {
      temp[k] = a[k] + roots2[lg][k] * a[half + k];
      temp[k + half] = a[k] - roots2[lg][k] * a[half + k];
    }
  for (int i = 0; i < len; i++)
    a[i] = temp[i];
}

void multiply(const int *x, const int *y, long long *res, int len) {
  int size = 1, lg = 0;
  while (size < 2 * len)
    size <<= 1, lg++;
  for (int i = 0; i < len; i++) {
    a[i].real() = x[i];
    a[i].imag() = 0;
    b[i].real() = y[i];
    b[i].imag() = 0;
  }
  for (int i = len; i < size; i++)
    a[i] = b[i] = 0;
  fft(a, size, lg, 1);
  fft(b, size, lg, 1);
  for (int i = 0; i < size; i++)
    a[i] *= b[i];
  fft(a, size, lg, -1);
  for (int i = 0; i < size; i++)
    res[i] = (long long) (a[i].real() / size + 0.5);
}

}

namespace FFT2 {
//faster version

struct Complex {
  double r, i;

  Complex(double r = 0, double i = 0) : r(r), i(i) { }

  Complex operator+(const Complex & x)const {
    return Complex(r + x.r, i + x.i);
  }

  Complex operator-(const Complex & x)const {
    return Complex(r - x.r, i - x.i);
  }

  Complex operator*(const Complex & x)const {
    return Complex(r * x.r - i * x.i, r * x.i + i * x.r);
  }

  Complex operator/(double d) const {
    return Complex(r / d, i / d);
  }

  friend ostream& operator<<(ostream& out, const Complex & x) {
    return out << '(' << x.r << ',' << x.i << "i)";
  }

} ;

void fft(Complex* arr, int N, bool invert) {
  const double PI = acos(-1.0);
  static Complex roots[1 << 20];
  //N is power of 2
  for (int i = 1, j = 0; i < N; i++) {
    int bit = N >> 1;
    for (; j >= bit; bit >>= 1) j -= bit;
    j += bit;
    if (i < j) swap(arr[i], arr[j]);
  }
  for (int d = 2; d <= N; d <<= 1) {
    int half = d >> 1, i, j, m;
    double angle = 2 * PI / d * (invert ? -1 : 1);
    Complex wlen(cos(angle), sin(angle)), u, v;
    roots[0] = Complex(1, 0);
    for (int j = 1; j < half; j++)
      roots[j] = roots[j - 1] * wlen;
    for (i = 0; i < N; i += d) {
      for (j = 0, m = i + half; j < half; j++, m++) {
        u = arr[i + j];
        v = roots[j] * arr[m];
        arr[i + j] = u + v;
        arr[m] = u - v;
      }
    }
  }
}

}