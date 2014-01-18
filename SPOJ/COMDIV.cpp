/* Solved
 * 7718. Number of common divisors
 * File:   COMDIV.cpp
 * Author: Andy Y.F. Huang
 * Created on August 16, 2012, 12:30 PM
 */

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#endif

namespace COMDIV {
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

inline int next_int() {
  char c;
  int ans = 0;
  while (c < '0')
    c = next_char();
  while (c >= '0') {
    ans = (ans << 1) + (ans << 3);
    ans += c - '0';
    c = next_char();
  }
  return ans;
}

const int max_n = 1000;
bool prime[max_n];
int primes[max_n >> 2], pcount;

void sieve() {
  memset(prime, true, sizeof (prime));
  int i;
  pcount = 0;
  for (i = 2; i * i < max_n; i++) {
    if (prime[i]) {
      primes[pcount++] = i;
      for (int j = i * i; j < max_n; j += i)
        prime[j] = false;
    }
  }
  for (; i < max_n; i++)
    if (prime[i])
      primes[pcount++] = i;
}

int gcd(int a, int b) {
  while (b != 0) {
    int t = a % b;
    a = b;
    b = t;
  }
  return a;
}

void solve(int test_num) {
  int a = next_int(), b = next_int();
  int ans = 1, x = gcd(a, b);
  for (int i = 0; i < pcount && primes[i] * primes[i] <= x; i++) {
    int cnt = 0;
    while (x % primes[i] == 0) {
      cnt++;
      x /= primes[i];
    }
    if (cnt > 0)
      ans *= cnt + 1;
  }
  if (x > 1) ans <<= 1;
  printf("%d\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  sieve();
  int tests = next_int();
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  COMDIV::solve();
  return 0;
}

