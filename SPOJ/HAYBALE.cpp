/* Solved
 * 10500. Haybale stacking - difference array
 * File:   HAYBALE.cpp
 * Author: Andy Huang
 * Created on June 14, 2012, 11:03 PM
 */

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <fstream>
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#define pln(x) println(x)
#define pf(x) print(x)
#define plnarr(i, j) println(i, j)
#endif

using namespace std;

#define max_len 1000010

int arr[max_len];

void solve() {
  memset(arr, 0, sizeof (arr));
  int len, k;
  scanf("%d %d", &len, &k);
  while (k--) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    arr[a]++;
    arr[b + 1]--;
  }
  for (int i = 1; i < len; i++)
    arr[i] += arr[i - 1];
  sort(arr, arr + len);
  printf("%d\n", arr[len >> 1]);
}

int main() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve();
  return 0;
}

