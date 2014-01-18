/* Solved
 * 9430. The game of 31
 * File:   GAME31.cpp
 * Author: Andy Y.F. Huang
 * Created on February 10, 2013, 1:04 AM
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

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace GAME31 {
bool moi[5][5][5][5][5][5];
char str[55];

void solve(int test_num) {
  int cnt[7] = {0};
  int len = strlen(str);
  for (int i = 0; i < len; i++)
    cnt[str[i] - '0']++;
  bool win = moi[cnt[1]][cnt[2]][cnt[3]][cnt[4]][cnt[5]][cnt[6]];
  if (win)
    printf("%s %c\n", str, len % 2 == 0 ? 'A' : 'B');
  else
    printf("%s %c\n", str, len % 2 == 1 ? 'A' : 'B');
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  for (int i = 4; i >= 0; i--) {
    for (int j = 4; j >= 0; j--) {
      for (int k = 4; k >= 0; k--) {
        for (int l = 4; l >= 0; l--) {
          for (int m = 4; m >= 0; m--) {
            for (int n = 4; n >= 0; n--) {
              int sum = i * 1 + j * 2 + k * 3 + l * 4 + m * 5 + n * 6;
              if (sum > 31)
                moi[i][j][k][l][m][n] = true;
              if (moi[i][j][k][l][m][n])
                continue;
              if (i != 0)
                moi[i - 1][j][k][l][m][n] = true;
              if (j != 0)
                moi[i][j - 1][k][l][m][n] = true;
              if (k != 0)
                moi[i][j][k - 1][l][m][n] = true;
              if (l != 0)
                moi[i][j][k][l - 1][m][n] = true;
              if (m != 0)
                moi[i][j][k][l][m - 1][n] = true;
              if (n != 0)
                moi[i][j][k][l][m][n - 1] = true;
            }
          }
        }
      }
    }
  }
  while (scanf("%s", str) != EOF)
    solve(1);
}
}

int main() {
  GAME31::solve();
  return 0;
}

