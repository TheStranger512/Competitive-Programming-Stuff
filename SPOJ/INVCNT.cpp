/* Solved
 * 6256. Inversion Count - mergesort
 * File:   INVCNT.cpp
 * Author: Andy Huang
 * Created on June 2, 2012, 11:30 PM
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

#define max_size 200050

typedef long long int64;

int array[max_size];
int temp[max_size];

int64 merge(const int& left, const int& mid, const int& right) {
  int i = left;
  int j = mid + 1;
  int index = left;
  int64 ans = 0;
  while (i <= mid && j <= right) {
    if (array[i] <= array[j])
      temp[index++] = array[i++];
    else {
      temp[index++] = array[j++];
      ans += mid - i + 1;
    }
  }
  while (i <= mid)
    temp[index++] = array[i++];
  while (j <= right)
    temp[index++] = array[j++];
  for (int k = left; k <= right; k++)
    array[k] = temp[k];
  return ans;
}

int64 mergesort(const int& left, const int& right) {
  if (left < right) {
    int64 ans = 0LL;
    int mid = (left + right) >> 1;
    ans += mergesort(left, mid);
    ans += mergesort(mid + 1, right);
    ans += merge(left, mid, right);
    return ans;
  }
  return 0LL;
}

void solve() {
  int size;
  scanf("%d", &size);
  for (int i = 0; i < size; i++)
    scanf("%d", &array[i]);
  printf("%lld\n", mergesort(0, size - 1));
}

int main() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d", &tests);
  while (tests--)
    solve();
  return 0;
}

