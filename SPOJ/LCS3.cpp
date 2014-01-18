/* Solved
 * 9098. Long Common Subsequence
 * File:   LCS3.cpp
 * Author: Andy Y.F. Huang
 * Created on March 24, 2013, 4:31 PM
 */

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

namespace LCS3 {
vector<int> pos[10001];
vector<int>::const_iterator it;
int ans[11];
int seq[11], temp[11];

void solve(int test_num) {
  int len;
  scanf("%d", &len);
  for (int i = 0, num; i < len; i++) {
    scanf("%d", &num);
    pos[num].push_back(i);
  }
  int quests;
  scanf("%d", &quests);
  for (int q = 0; q < quests; q++) {
    int qlen, anslen = 0;
    scanf("%d", &qlen);
    for (int i = 0; i < qlen; i++)
      scanf("%d", seq + i);
    for (int mask = (1 << qlen) - 1; mask >= 0; mask--) {
      int cpos = 0, templen = 0;
      for (int bit = 0, num; bit < qlen; bit++) {
        num = seq[bit];
        if (!(1 << bit & mask)) continue;
        temp[templen++] = num;
        it = lower_bound(pos[num].begin(), pos[num].end(), cpos);
        if (it == pos[num].end()) {
          templen = -1;
          break;
        }
        cpos = (*it) + 1;
      }
      if (templen > anslen) {
        anslen = templen;
        memcpy(ans, temp, sizeof (ans));
      }
      else if (templen == anslen && lexicographical_compare(temp, temp + templen, ans, ans + anslen))
        memcpy(ans, temp, sizeof (ans));
    }
    printf("%d", anslen);
    for (int i = 0; i < anslen; i++)
      printf(" %d", ans[i]);
    putchar('\n');
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  solve(1);
}
}

int main() {
  LCS3::solve();
  return 0;
}

