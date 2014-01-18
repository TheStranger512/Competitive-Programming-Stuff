/* Solved
 * 9861. Hotels Along the Croatian Coast - two pointers
 * File:   HOTELS.cpp
 * Author: Andy Huang
 * Created on June 3, 2012, 12:19 AM
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
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#define pln(x) println(x)
#define pf(x) print(x)
#define plnarr(i, j) println(i, j)
#endif

using namespace std;

#define max_size 300050

int array[max_size];

void solve() {
  int size, limit, ans = 0;
  scanf("%d %d", &size, &limit);
  for (int i = 0; i < size; i++) {
    scanf("%d", &array[i]);
    if (array[i] <= limit && array[i] > ans)
      ans = array[i];
  }
  int i = 0;
  int j = 0;
  long long sum = 0;
  while (j < size) {
    int orig = j;
    while (j < size && sum + array[j] <= limit)
      sum += array[j++];
    if (sum > ans)
      ans = sum;
    if (j >= size)
      break;
    while (i < j && sum + array[j] > limit)
      sum -= array[i++];
    if (j == orig)
      j++;
  }
  printf("%d\n", ans);
}

int main() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve();
  return 0;
}

