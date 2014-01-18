/* Solved
 * 3885. Coins Game - simple game theory
 * File:   MCOINS.cpp
 * Author: Andy Huang
 * Created on May 26, 2012, 9:40 PM
 */

#include <stdio.h>

using namespace std;

bool win[1000050];
int height[51];

void solve() {
  int k, l, games, maxheight = 0;
  scanf("%d %d %d", &k, &l, &games);
  for (int i = 0; i < games; i++){
    scanf("%d", &height[i]);
    if (height[i] > maxheight)
    maxheight = height[i];
  }
  win[0] = false;
  for (int i = 1; i <= maxheight; i++) {
    if (!win[i - 1])
      win[i] = true;
    else if (i - l >= 0 && !win[i - l])
      win[i] = true;
    else if (i - k >= 0 && !win[i - k])
      win[i] = true;
  }
  for (int i = 0; i < games; i++) {
    if (win[height[i]])
      putchar('A');
    else
      putchar('B');
  }
  puts("");
}

int main() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve();
  return 0;
}

