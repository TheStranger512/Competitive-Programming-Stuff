/* Solved
 * 3881. Majstor
 * File:   MAJSTOR.cpp
 * Author: Andy Y.F. Huang
 * Created on July 28, 2012, 11:46 PM
 */

#include <cstdio>

#ifdef AZN
#include "Azn.cpp"
#define pln(x) println(x)
#define pf(x) print(x)
#define plnarr(i, j) println(i, j)
#endif

int main() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int r, n, i, j, round, temp[3], score = 0, m = 0;
  char user[99], hands[99][99];
  scanf("%d%s%d", &r, user, &n);
  for (i = 0; i < n; i++)
    scanf("%s", hands[i]);
  for (i = 0; i < r; i++) {
    round = 0;
    for (j = 0; j < 3; j++)
      temp[j] = 0;
    for (j = 0; j < n; j++) {
      char c = hands[j][i];
      if (c == 'R') {
        temp[0]++;
        temp[1] += 2;
      }
      else if (c == 'P') {
        temp[1]++;
        temp[2] += 2;
      }
      else {
        temp[2]++;
        temp[0] += 2;
      }
    }
    for (j = 0; j < 3; j++)
      if (temp[j] > round)
        round = temp[j];
    m += round;
    char c = user[i];
    if (c == 'R')
      score += temp[0];
    else if (c == 'P')
      score += temp[1];
    else
      score += temp[2];
  }
  printf("%d\n%d", score, m);
  return 0;
}

