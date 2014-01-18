/* Solved
 * 3591. Patting Heads
 * File:   PATHEADS.cpp
 * Author: Andy Y.F. Huang
 * Created on August 17, 2012, 4:27 PM
 */

#include <cstdio>
#include <iostream>
#include <cmath>
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
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace PATHEADS {
int pat[1000010] = {0}, nums[100010];

void solve(int test_num) {
  int len;
  scanf("%d", &len);
  for (int i = 0; i < len; i++) {
    scanf("%d", &nums[i]);
    pat[nums[i]]++;
  }
  for (int i = 500000; i >= 1; i--) {
    if (pat[i] > 0 )
      for (int j = 2 * i; j <= 1000000; j += i)
        pat[j] += pat[i];
  }
  for (int i = 0; i < len; i++)
    printf("%d\n", pat[nums[i]] - 1);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve(1);
}
}

int main() {
  PATHEADS::solve();
  return 0;
}

