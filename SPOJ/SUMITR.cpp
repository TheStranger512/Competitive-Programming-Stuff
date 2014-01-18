/* 
 * 237. Sums in a Triangle - simple dp;
 * File:   SUMITR.cpp
 * Author: Andy Huang
 * Created on May 21, 2012, 6:52 PM
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

int a[110][110];


int main() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int t,n,x;
  scanf("%d", &t);
  while (t--){
    x = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= i; j++){
        scanf("%d", &a[j][i]);
        a[j][i] += max(a[j][i - 1], a[j - 1][i - 1]);
        x = max(x, a[j][i]);
      }   
    printf("%d\n", x);
  }
  
  return 0;
}

