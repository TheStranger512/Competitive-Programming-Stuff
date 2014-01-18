/* Solved
 * 8042. Possible Friends
 * File:   SOCIALNE.cpp
 * Author: Andy Y.F. Huang
 * Created on August 17, 2012, 3:21 PM
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
namespace SOCIALNE {
int graph[55][55], len;
char str[55];

void solve(int test_num) {
  memset(graph, 0x3F, sizeof (graph));
  gets(str);
  len = strlen(str);
  for (int i = 0; i < len; i++)
    if (str[i] == 'Y')
      graph[0][i] = 1;
  for (int i = 1; i < len; i++) {
    gets(str);
    for (int j = 0; j < len; j++)
      if (str[j] == 'Y')
        graph[i][j] = 1;
  }
  for (int k = 0; k < len; k++)
    for (int i = 0; i < len; i++)
      for (int j = 0; j < len; j++)
        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
  int id = 0, ans = 0;
  for (int i = 0; i < len; i++) {
    int cnt = 0;
    for (int j = 0; j < len; j++)
      cnt += graph[i][j] == 2 && i != j;
    if (cnt > ans)
      ans = cnt, id = i;
  }
  printf("%d %d\n", id, ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d\r\n", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  SOCIALNE::solve();
  return 0;
}

