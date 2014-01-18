/* Solved
 * 7406. Beehive Numbers - OEIS A003215
 * File:   BEENUMS.cpp
 * Author: Andy Y.F. Huang
 * Created on August 8, 2012, 4:12 PM
 */

#include <cstdio>
#include <cmath>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace BEENUMS {

void solve(int test_num, int num) {
  int sq;
  if (--num % 3) {
    puts("N");
    return;
  }
  num /= 3;
  sq = (int) sqrt(num);
  if (sq * (sq + 1) == num || (sq + 1) * (sq + 2) == num)
    puts("Y");
  else
    puts("N");
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (true) {
    int num;
    scanf("%d", &num);
    if (num == -1)
      break;
    solve(1, num);
  }
}
}

int main() {
  BEENUMS::solve();
  return 0;
}

