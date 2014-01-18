/* Solved
 * 11457. New iPad - simple ascii drawings
 * File:   VUDBOL4.cpp
 * Author: Andy Huang
 * Created on May 4, 2012, 11:10 PM
 */

#include <stdio.h>

int n;
char image[55];

void solve() {
  for (int i = 0; i < n; i++) {
    scanf("%s", image);
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < n; k++) {
        putc(image[k], stdout);
        putc(image[k], stdout);
      }
      puts("");
    }
  }
}

int main() {
  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  scanf("%d", &n);
  while (n != 0) {
    solve();
    scanf("%d", &n);
  }
  return 0;
}

