/* Solved
 * 2727. Army Strength - max of array comparison
 * File:   ARMY.cpp
 * Author: Andy Huang
 * Created on May 9, 2012, 12:16 AM
 */

#include <stdio.h>

void solve() {
  int leng, lenm;
  scanf("%d %d", &leng, &lenm);
  int maxg = -1, maxm = -1;
  for (int i = 0; i < leng; i++){
    int temp;
    scanf("%d", &temp);
    if (temp > maxg)
      maxg = temp;
  }
  for (int i = 0; i < lenm; i++){
    int temp;
    scanf("%d", &temp);
    if (temp > maxm)
      maxm = temp;
  }
  if (maxg >= maxm)
    puts("Godzilla");
  else
    puts("MechaGodzilla");
}

int main() {
  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d", &tests);
  while (tests--)
    solve();
  return 0;
}

