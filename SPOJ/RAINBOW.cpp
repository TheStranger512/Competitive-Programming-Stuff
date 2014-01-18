/* Solved
 * 3724. Rainbow Ride - connected components + knapsack
 * File:   RAINBOW.cpp
 * Author: Andy Y.F. Huang
 * Created on September 13, 2012, 7:19 PM
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
namespace RAINBOW {
int weight[1010], dp[1010][1010], comps[1010];
int dsu[1010], totalw[1010], groupsize[1010];
int ppl, cap;

void unite(int roota, int rootb) {
  if (roota == rootb)
    return;
  if (dsu[roota] < dsu[rootb])
    dsu[rootb] = roota;
  else {
    if (dsu[roota] == dsu[rootb])
      dsu[rootb]--;
    dsu[roota] = rootb;
  }
}

int find(int node) {
  return dsu[node] < 0 ? node : (dsu[node] = find(dsu[node]));
}

void solve(int test_num) {
  memset(dsu, 0xFF, sizeof (dsu));
  memset(dp, 0, sizeof (dp));
  memset(totalw, 0, sizeof (totalw));
  memset(groupsize, 0, sizeof (groupsize));
  for (int i = 0; i < ppl; i++)
    scanf("%d", &weight[i]);
  for (int i = 0; i < ppl; i++) {
    int deg;
    scanf("%d", &deg);
    while (deg--) {
      int person;
      scanf("%d", &person);
      unite(find(i), find(--person));
    }
  }
  int len = 0;
  for (int i = 0; i < ppl; i++) {
    if (find(i) == i)
      comps[++len] = i; //one-based index
    totalw[find(i)] += weight[i];
    groupsize[find(i)]++;
  }
  for (int i = 1; i <= len; i++) {
    for (int j = 1; j <= cap; j++) {
      int id = comps[i];
      if (j >= totalw[id])
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - totalw[id]] + groupsize[id]);
      else
        dp[i][j] = dp[i - 1][j];
    }
  }
  int ans = 0;
  for (int c = 0; c <= cap; c++)
    ans = max(ans, dp[len][c]);
  printf("%d\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  //freopen("C:/Users/Windows/Documents/Compsci/ACM-ICPC/2009 - KOPC/Kurukshetra 09 OPC/rainbow/rainbow.in", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  for (int i = 1; ; i++) {
    scanf("%d %d", &ppl, &cap);
    if (ppl == 0 && cap == 0)
      break;
    solve(i);
  }
}
}

int main() {
  RAINBOW::solve();
  return 0;
}

