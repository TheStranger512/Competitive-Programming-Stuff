/* Solved
 * 7775. Explicit Formula - simple loops;
 * File:   EXFOR.cpp
 * Author: Andy Huang
 * Created on May 7, 2012, 12:44 AM
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

using namespace std;

int arr[15];

void solve() {
  for (int i = 0; i < 10; i++)
    scanf("%d", &arr[i]);
  int cnt = 0;
  for (int i = 0; i < 10; i++){
    for (int j = i + 1; j < 10; j++){
      if (arr[i] || arr[j])
        cnt++;
      for (int k = j + 1; k < 10; k++)
        if (arr[i] || arr[j] || arr[k])
          cnt++;
    }
  }
  printf("%d\n", cnt % 2);
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

