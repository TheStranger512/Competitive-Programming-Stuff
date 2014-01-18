/* Solved
 * 31. Fast Multiplication
 * File:   MUL.cpp
 * Author: Andy Y.F. Huang
 * Created on January 6, 2013, 7:35 PM
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
namespace MUL {
const unsigned int buffer_size = 1 << 16;
char input_buffer[buffer_size];
unsigned int bytes_read = 0;
unsigned int input_index = 0;

inline char next_char() {
  if (input_index == bytes_read) {
    bytes_read = fread(input_buffer, sizeof (char) , buffer_size, stdin);
    input_buffer[bytes_read] = '\0'; //sentinel
    input_index = 0;
  }
  return input_buffer[input_index++];
}

inline char* next_str(char* str) {
  char c = 0;
  while (c <= ' ') c = next_char();
  do {
    *str++ = c;
    c = next_char();
  } while (c > ' ');
  *str = '\0';
  return str;
}

template <class T, size_t MAXSIZE> struct FFT {
  typedef complex<double> Comp;
  Comp IOTA;
  static const double PI = 3.14159265358979323846;
  Comp temp[MAXSIZE], a[MAXSIZE], b[MAXSIZE];

  void init() {
    IOTA = Comp(0, 1);
  }

  void fft(Comp *a, int len, int rev) {
    if (len == 1) return;
    for (int i = 0; i < len; i++)
      temp[i] = a[i];
    for (int i = 0; i < len; i++)
      if (i & 1)
        a[(len >> 1) + (i >> 1)] = temp[i];
      else
        a[i >> 1] = temp[i];
    Comp *a0 = a, *a1 = a + (len >> 1);
    fft(a0, len >> 1, rev);
    fft(a1, len >> 1, rev);
    Comp cur(1, 0);
    Comp step = exp(IOTA * (2 * PI * rev / len));
    for (int k = 0; k < (len >> 1); k++) {
      temp[k] = a0[k] + cur * a1[k];
      temp[k + (len >> 1)] = a0[k] - cur * a1[k];
      cur *= step;
    }
    for (int i = 0; i < len; i++)
      a[i] = temp[i];
  }

  void multiply(const T *x, const T *y, T *res, int len) {
    int size = 1;
    while (size < 2 * len)
      size <<= 1;
    for (int i = 0; i < len; i++) {
      a[i].real() = x[i];
      a[i].imag() = 0;
      b[i].real() = y[i];
      b[i].imag() = 0;
    }
    for (int i = len; i < size; i++)
      a[i] = b[i] = 0;
    fft(a, size, 1);
    fft(b, size, 1);
    for (int i = 0; i < size; i++)
      a[i] *= b[i];
    fft(a, size, -1);
    for (int i = 0; i < size; i++)
      res[i] = (T) (a[i].real() / size + 0.5);
  }

} ;

char a[11111], b[11111];
int x[5555], y[5555], out[22222];
FFT<int, 1 << 16> fft;

void solve(int test_num) {
  fft.init();
  int lena = next_str(a) - a;
  int lenb = next_str(b) - b;
  reverse(a, a + lena);
  reverse(b, b + lenb);
//  a[lena] = a[lena + 1] = a[lena + 2] = '0';
//  b[lenb] = b[lenb + 1] = b[lenb + 2] = '0';
//  int lenx = 0, leny = 0;
//  for (int i = 0; i < lena; i += 4)
//    x[lenx++] = (a[i] - '0') + (a[i + 1] - '0')*10 + (a[i + 2] - '0')*100 + (a[i + 3] - '0') * 1000;
//  for (int i = 0; i < lenb; i += 4)
//    y[leny++] = (b[i] - '0') + (b[i + 1] - '0')*10 + (b[i + 2] - '0')*100 + (b[i + 3] - '0') * 1000;
  for (int i = 0; i < lena; i++)
    x[i] = a[i] - '0';
  for (int i = 0; i < lenb; i++)
    y[i] = b[i] - '0';
  int len = max(lena, lenb);
  for (int i = lena; i < len; i++)
    x[i] = 0;
  for (int i = lenb; i < len; i++)
    y[i] = 0;
  int outlen = lena + lenb;
  //  memset(out, 0, sizeof (int) * outlen);
  //  for (int i = 0; i < lenx; i++)
  //    for (int j = 0; j < leny; j++) {
  //      out[i + j] += x[i] * y[j];
  //      if (out[i + j] > 1000000000) {
  //        out[i + j + 1] += out[i + j] / 10000;
  //        out[i + j] %= 10000;
  //      }
  //    }
  //plnarr(x, x + lena);
  //plnarr(y, y + lenb);
  fft.multiply(x, y, out, len);
  //plnarr(out, out + outlen);
  for (int i = 0; i < outlen; i++) {
    out[i + 1] += out[i] / 10;
    out[i] %= 10;
  }
  while (outlen > 1 && out[outlen - 1] == 0)
    outlen--;
  //printf("%d", out[outlen - 1]);
  for (int i = outlen - 1; i >= 0; i--)
    printf("%d", out[i]);
  putchar('\n');
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
  MUL::solve();
  return 0;
}

