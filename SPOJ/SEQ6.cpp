/* Solved
 * 6650. Consecutive sequence
 * The solution is equal to 2 x (# of odd divisors of n) 
 * File:   SEQ6.cpp
 * Author: Andy Y.F. Huang
 * Created on August 31, 2012, 9:54 PM
 */

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>
#include <vector>
#include <ctime>
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
namespace SEQ6 {
bool mark[4500] = {false};
int primes[4000], len;

void init() {
  len = 0;
  for (int i = 3; i < 4500; i++) { //no need to sieve 2
    if (!mark[i] && (i & 1)) {
      primes[len++] = i;
      for (int j = i * i; j < 4500; j += i)
        mark[j] = true;
    }
  }
}

int slow(int num) {
  int cnt = 0;
  for (int a = -1000; a < 1000; a++)
    for (int n = 0; n < 2000; n++)
      if ((n * ((a << 1) + n - 1) >> 1) == num)
        cnt++;
  return cnt;
}

void solve(int test_num, int num) {
  //pln(slow(num));
  int ans = 1;
  while (!(num & 1))
    num >>= 1;
  for (int i = 0; i < len && num >= primes[i]; i++) {
    int exp = 0;
    while (num % primes[i] == 0)
      exp++, num /= primes[i];
    if (exp > 0)
      ans *= (exp + 1);
  }
  if ((num & 1) && num > 1)
    ans *= 2;
  ans <<= 1;
  printf("%d\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  init();
  while (true) {
    int num;
    scanf("%d", &num);
    if (num == 0)
      break;
    solve(1, num);
  }
}
}

int main() {
  SEQ6::solve();
  return 0;
}

