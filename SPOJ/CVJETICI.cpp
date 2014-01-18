/* Solved
 * 3877. Cvjetici
 * File:   CVJETICI.cpp
 * Author: Andy Y.F. Huang
 * Created on September 23, 2012, 6:49 PM
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
namespace CVJETICI {
const int k_lim = 100100;
int bit[k_lim + 20] = {0};

int query(int pos) {
  int ans = 0;
  for (int i = pos; i > 0; i -= i&-i)
    ans += bit[i];
  return ans;
}

int update(int pos, int val) {
  for (int i = pos; i < k_lim; i += i&-i)
    bit[i] += val;
  return val;
}

void solve(int test_num) {
  int plants;
  scanf("%d", &plants);
  for (int i = 0; i < plants; i++) {
    int left, right;
    scanf("%d %d", &left, &right);
    int cntleft = query(left), cntright = query(right);
    printf("%d\n", cntleft + cntright);
    update(left, -cntleft);
    update(left + 1, cntleft);
    update(right, -cntright);
    update(right + 1, cntright);
    update(left + 1, 1);
    update(right, -1);
    //    for (int j = 1; j <= 10; j++)
    //      printf("%d ", query(j));
    //    putchar('\n');
  }
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
  CVJETICI::solve();
  return 0;
}

