/* Solved
 * 2905. Not a Triangle - sorting - binary search
 * File:   NOTATRI.cpp
 * Author: Andy Huang
 * Created on June 8, 2012, 11:39 PM
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

#define max_n 2050

int nums[max_n];
int len;

int binarysearch(int key) {
  int high = len - 1;
  int low = 0;
  while (low < high) {
    int mid = (low + high) >> 1;
    if (nums[mid] <= key)
      low = mid + 1;
    else
      high = mid;
  }
  if (nums[high] <= key)
    return 0;
  if (nums[low] > key)
    return len - low;
  return len - high;
}

void solve() {
  for (int i = 0; i < len; i++)
    scanf("%d", &nums[i]);
  sort(nums, nums + len);
  int ans = 0;
  for (int i = 0; i < len; i++) 
    for (int j = i + 1; j < len; j++) 
      ans += binarysearch(nums[i] + nums[j]);   
  printf("%d\n", ans);
}

int main() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (true) {
    scanf("%d", &len);
    if (len)
      solve();
    else
      break;
  }
  return 0;
}

