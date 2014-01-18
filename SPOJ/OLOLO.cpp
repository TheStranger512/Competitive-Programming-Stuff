/* Solved
 * 7742. Onotole needs your help - Xor operation
 *  if many pairs of numbers are present Xor will remove them
 *  leaving the unique number (only works for unsigned)
 * File:   OLOLO.cpp
 * Author: Andy Huang
 * Created on May 26, 2012, 8:31 PM
 */

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <fstream>
#include <set>
#include <map>
#include <sstream>
#include <deque>

#ifdef AZN
#include "Azn.cpp"
#define pln(x) println(x)
#define pf(x) print(x);
#endif

using namespace std;

void solve() {
  int n, ans = 0;
  scanf("%d", &n);
  while (n--){
    int temp;
    scanf("%d", &temp);
    ans ^= temp;
  }
  printf("%d", ans);
}

int main() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve();
  return 0;
}

