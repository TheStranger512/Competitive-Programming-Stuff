/* Solved
 * 11521. Dominant Strings
 * File:   DOMINST.cpp
 * Author: Andy Y.F. Huang
 * Created on April 21, 2013, 7:40 PM
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

namespace DOMINST {
typedef long long llong;

struct String {
  char str[11];

  bool operator<(const String & s) const {
    return strcmp(str, s.str) < 0;
  }
} ;

String str[15011];
vector<int> hashes;
char temp[11];
int len[15011];

void insort(int len) {
  for (int i = 1; i < len; i++)
    for (int j = i - 1; j >= 0 && temp[j] > temp[j + 1]; j--)
      swap(temp[j], temp[j + 1]);
}

void solve(int test_num) {
  int cnt = 0;
  while (scanf("%s", str[cnt].str) != EOF)
    cnt++;
  sort(str, str + cnt);
  for (int i = 0; i < cnt; i++) {
    memcpy(temp, str[i].str, sizeof (temp));
    len[i] = strlen(temp);
    insort(len[i]);
    for (int mask = (1 << len[i]) - 2; mask > 0; mask--) {
      llong hash = 0;
      for (int j = 0; j < len[i]; j++)
        if (1 << j & mask)
          hash = hash * 27 + temp[j] - 'a' + 1;
      hashes.push_back(hash);
    }
  }
  sort(hashes.begin(), hashes.end());
  hashes.erase(unique(hashes.begin(), hashes.end()), hashes.end());
  //pln(hashes);
  for (int i = 0; i < cnt; i++) {
    memcpy(temp, str[i].str, sizeof (temp));
    insort(len[i]);
    llong hash = 0;
    for (int j = 0; j < len[i]; j++)
      hash = hash * 27 + temp[j] - 'a' + 1;
    if (!binary_search(hashes.begin(), hashes.end(), hash))
      printf("%s\n", str[i].str);
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
  DOMINST::solve();
  return 0;
}

