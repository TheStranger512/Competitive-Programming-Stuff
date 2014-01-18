/* Solved
 * 10112. Peer Review
 * File:   REVIEW.cpp
 * Author: Andy Y.F. Huang
 * Created on July 25, 2013, 9:26 PM
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

namespace REVIEW {
int cnt[1111];
map<string, int> hash;
int K, N;
int rev[1111][5];
int skool[1111];

void solve(int test_num) {
  if (K == 0 && N == 0) return;
  hash.clear();
  for (int i = 1; i <= N; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < K; j++)
      cin >> rev[i][j];
    sort(rev[i], rev[i] + K);
    if (!hash.count(str))
      hash[str] = hash.size();
    skool[i] = hash[str];
  }
  memset(cnt, 0, sizeof (cnt));
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < K; j++) {
      if (skool[i] == skool[rev[i][j]])
        cnt[rev[i][j]] = -1337;
      else
        cnt[rev[i][j]]++;
    }
    for (int j = 1; j < K; j++)
      if (rev[i][j] == rev[i][j - 1])
        cnt[rev[i][j]] = -1337;
  }
  int res = 0;
  for (int i = 1; i <= N; i++)
    if (cnt[i] != K)
      res++;
  if (res == 0) puts("NO PROBLEMS FOUND");
  else if (res == 1) puts("1 PROBLEM FOUND");
  else printf("%d PROBLEMS FOUND\n", res);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (cin >> K >> N)
    solve(1);
}
}

int main() {
  REVIEW::solve();
  return 0;
}

