/*
 * 31. Fast Multiplication (using FFT version)
 * File:   MUL__FFT.cpp
 * Author: Andy Y.F. Huang
 * Created on April 25, 2013, 1:56 AM
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

namespace MUL__FFT {
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

char a[11111], b[11111];
int x[5555], y[5555];
long long out[22222];

void solve(int test_num) {
  //123456789LL * 987654321LL = 121932631112635269
  int lena = next_str(a) - a;
  int lenb = next_str(b) - b;
  reverse(a, a + lena);
  reverse(b, b + lenb);
  while (lena % 5 != 0) a[lena++] = '0';
  while (lenb % 5 != 0) b[lenb++] = '0';
  int lenx = 0, leny = 0;
  for (int i = 0; i < lena; i++) a[i] -= '0';
  for (int i = 0; i < lenb; i++) b[i] -= '0';
  for (int i = 0; i < lena; i += 5)
    x[lenx++] = a[i] + 10 * a[i + 1] + 100 * a[i + 2] + 1000 * a[i + 3] + 10000 * a[i + 4];// + 100000 * a[i + 5];
  for (int i = 0; i < lenb; i += 5)
    y[leny++] = b[i] + 10 * b[i + 1] + 100 * b[i + 2] + 1000 * b[i + 3] + 10000 * b[i + 4];// + 100000 * b[i + 5];
  int len = max(lenx, leny);
  for (int i = lenx; i < len; i++) x[i] = 0;
  for (int j = leny; j < len; j++) y[j] = 0;
  FFT::multiply(x, y, out, len);
  len <<= 1;
  //plnarr(out, out + len);
  for (int i = 0; i < len; i++) {
    assert(out[i] >= 0);
    out[i + 1] += out[i] / 100000;
    out[i] %= 100000;
  }
  while (len > 1 && out[len - 1] == 0)
    len--;
  printf("%d", (int) out[len - 1]);
  for (int i = len - 2; i >= 0; i--)
    printf("%05d", (int) out[i]);
  putchar('\n');
  //pln(123456789LL * 987654321LL);
  //pln(1342535599LL *25222);//33861432877978
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  FFT::init();
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  MUL__FFT::solve();
  return 0;
}

