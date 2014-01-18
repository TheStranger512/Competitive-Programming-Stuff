/* Solved
 * 15414. MAKE ME
 * File:   ABZDEFGH.cpp
 * Author: Andy Y.F. Huang
 * Created on July 22, 2013, 12:33 PM
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

namespace ABZDEFGH {
int deg[26];
bool adj[26][26], need[26];

void solve(int test_num) {
  memset(need, false, sizeof (need));
  memset(deg, 0, sizeof (deg));
  memset(adj, false, sizeof (adj));
  int N;
  string str;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> str;
    for (size_t a = 0; a < str.size(); a++)
      for (size_t b = a + 1; b < str.size(); b++)
        adj[str[a] - 'a'][str[b] - 'a'] = true;
    for (size_t a = 0; a < str.size(); a++)
      need[str[a] - 'a'] = true;
  }
  for (int a = 0; a < 26; a++)
    for (int b = 0; b < 26; b++)
      if (adj[a][b])
        deg[b]++;
  while (true) {
    int next = -1;
    for (int i = 0; i < 26 && next == -1; i++)
      if (need[i] && deg[i] == 0)
        next = i;
    if (next == -1) break;
    need[next] = false;
    putchar(next + 'a');
    for (int b = 0; b < 26; b++)
      if (adj[next][b]) deg[b]--;
  }
  putchar('\n');
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
  ABZDEFGH::solve();
  return 0;
}

