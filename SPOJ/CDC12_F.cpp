/* Solved
 * 12561. Forbidden Machine
 * File:   CDC12_F.cpp
 * Author: Andy Y.F. Huang
 * Created on March 29, 2013, 11:01 PM
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

namespace CDC12_F {
vector<int> adj[111][26];
bool isfinal[111];
int good[1111][111];
char str[1111];
int len;

int rec(int pos, int state) {
  if (good[pos][state] > -1) return good[pos][state];
  int& res = good[pos][state];
  if (pos == len)
    return res = isfinal[state];
  for (int i = 0; i < (int) adj[state][str[pos] - 'a'].size(); i++)
    if (rec(pos + 1, adj[state][str[pos] - 'a'][i]))
      return res = 1;
  return res = 0;
}

void solve(int test_num) {
  memset(isfinal, false, sizeof (isfinal));
  int vertices, edges, finals, init;
  scanf("%d %d %d %d", &vertices, &edges, &finals, &init);
  for (int i = 0; i < 101; i++)
    for (int j = 0; j < 26; j++)
      adj[i][j].clear();
  for (int f = 0, end; f < finals; f++) {
    scanf("%d", &end);
    isfinal[end] = true;
  }
  for (int e = 0, a, b; e < edges; e++) {
    char c;
    scanf("%d %d %c", &a, &b, &c);
    adj[a][c - 'a'].push_back(b);
  }
  printf("Scenario #%d:\n", test_num);
  int quests;
  scanf("%d", &quests);
  for (int qq = 0; qq < quests; qq++) {
    memset(good, -1, sizeof (good));
    scanf("%s", str);
    len = strlen(str);
    printf("%s %s\n", str, rec(0, init) ? "Accepted" : "Rejected");
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  CDC12_F::solve();
  return 0;
}

