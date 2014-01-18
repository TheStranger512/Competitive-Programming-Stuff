/* Solved
 * 2. Prime Generator - fast Sieve of Eratosthenes
 * File:   PRIME1.cpp
 * Author: Andy Huang
 * Created on March 22, 2012, 6:35 PM
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

namespace Int_Output {
const char digit_to_char[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
const int buffer_size = 1 << 20; //make sure its big enough
char output_buffer[buffer_size];
unsigned int output_index = 0;

inline void write_flush() {
  fwrite(output_buffer, sizeof (char) , output_index, stdout);
  output_index = 0;
}

inline void write_char(char c) {
  output_buffer[output_index++] = c;
}

inline void write_int(int num) {
  if (num >= 10)
    write_int(num / 10);
  write_char(digit_to_char[num % 10]);
}

}

bool sieve[5000010];
int primes[3405];
bool mark[31650];

void init() {
  mark[0] = true;
  mark[1] = true;
  int index = 0;
  for (int i = 2; i < 31650; i++) {
    if (!mark[i]) {
      primes[index++] = i;
      for (int j = i * i; j < 31650; j += i)
        mark[j] = true;
    }
  }
}

void solve() {
  memset(sieve, false, sizeof (sieve));
  int start, end;
  scanf("%d %d", &start, &end);
  int len = end - start + 1;
  if (start == 1)
    sieve[0] = true;
  int sq = (int) sqrt(end);
  for (int i = 0; i < 3404; i++) {
    int prime = primes[i];
    if (prime > sq)
      break;
    int mul = (int) ceil((double) (start) / prime);
    if (mul == 1)
      mul = 2;
    for (int j = mul * prime - start; j < len; j += prime) {
      sieve[j] = true;
    }
  }
  for (int i = 0; i < len; i++)
    if (!sieve[i]) {
      Int_Output::write_int(i + start);
      Int_Output::write_char('\n');
    }
  Int_Output::write_char('\n');
}

int main() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  init();
  int tests;
  scanf("%d", &tests);
  while (tests--)
    solve();
  Int_Output::write_flush();
  return 0;
}


