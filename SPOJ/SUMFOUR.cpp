/* Solved
 * 1296. 4 values whose sum is 0 - sort/ binary search
 * File:   SUMFOUR.cpp
 * Author: Andy Huang
 * Created on May 26, 2012, 11:03 AM
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

struct Sum {
  int num;
  int cnt;
};

using namespace std;

typedef long long int64;

int values[4050][5];
int moi[16005000];
Sum sums[16005000];

int binarysearch(int key, int len) {
  int high = len - 1;
  int low = 0;
  int mid;
  while (low <= high) {
    mid = (high + low) >> 1;
    int num = sums[mid].num;
    if (key > num)
      low = mid + 1;
    else if (key < num)
      high = mid - 1;
    else
      return sums[mid].cnt;
  }
  return 0;
}

void solve() {
  int len;
  int index = 0;
  scanf("%d", &len);
  for (int i = 0; i < len; i++)
    for (int j = 0; j < 4; j++)
      scanf("%d", &values[i][j]);
  for (int i = 0; i < len; i++)
    for (int j = 0; j < len; j++)
      moi[index++] = values[i][2] + values[j][3];
  sort(moi, moi + index);
  sums[0].num = moi[0];
  sums[0].cnt = 0;
  int len2 = 0;
  for (int i = 0; i < index; i++) {
    if (moi[i] == sums[len2].num)
      sums[len2].cnt++;
    else {
      len2++;
      sums[len2].num = moi[i];
      sums[len2].cnt = 1;
    }
  }
  int ans = 0;
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      int num = -(values[i][0] + values[j][1]);
      ans += binarysearch(num, len2 + 1);
    }
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

