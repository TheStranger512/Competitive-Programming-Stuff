/* Solved
 * 10228. Magic Grid
 * File:   AMR11A.cpp
 * Author: Andy Y.F. Huang
 * Created on July 29, 2012, 11:44 PM
 */

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <ctime>

#ifdef AZN
#include "Azn.cpp"
#endif

namespace Int_Input {
const unsigned int buffer_size = 1 << 16;
char input_buffer[buffer_size];
const unsigned int char_to_int[58] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                                      11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                                      21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
                                      31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
                                      41, 42, 43, 44, 45, 46, 47,
                                      0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
unsigned int bytes_read = 0;
unsigned int input_index = 0;

inline char next_char() {
  if (input_index == bytes_read) {
    bytes_read = fread(input_buffer, sizeof (char) , buffer_size, stdin);
    input_buffer[bytes_read] = '\0'; //sentinel
    input_index = 0;
  }
  return input_buffer[input_index++];
}

inline int next_int() {
  char c;
  do {
    c = next_char();
  } while (c < '-');
  bool neg;
  if (c == '-') {
    neg = true;
    c = next_char();
  }
  else
    neg = false;
  int ans = 0;
  while (c >= '0') {
    ans = (ans << 1) + (ans << 3);
    ans += char_to_int[c];
    c = next_char();
  }
  return neg ? -ans : ans;
}

}

using namespace std;
using namespace Int_Input;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace AMR11A {
const int k_max_size = 510;
int grid[k_max_size][k_max_size], dp[k_max_size][k_max_size];

int f(int num) {
  if (num > 0)
    return num;
  return -123456789;
}

bool check(int val, int rows, int cols) {
  dp[0][0] = val;
  for (int x = 1; x < cols; x++)
    dp[x][0] = f(dp[x - 1][0] + grid[x][0]);
  for (int y = 1; y < rows; y++) {
    dp[0][y] = f(dp[0][y - 1] + grid[0][y]);
    for (int x = 1; x < cols; x++)
      dp[x][y] = f(grid[x][y] + max(dp[x - 1][y], dp[x][y - 1]));
  }
  return dp[cols - 1][rows - 1] > 0;
}

void solve(int test_num) {
  int rows = next_int();
  int cols = next_int();
  for (int y = 0; y < rows; y++)
    for (int x = 0; x < cols; x++)
      grid[x][y] = next_int();
  int high = 1000001;
  int low = 1;
  while (low < high) {
    int mid = (low + high) >> 1;
    if (check(mid, rows, cols))
      high = mid;
    else
      low = mid + 1;
  }
  printf("%d\n", low);
}

void makeCase(int rows, int cols) {
  srand(time(NULL));
  freopen("input.txt", "w", stdout);
  puts("1");
  printf("%d %d\n", rows, cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if ((i == j && j == 0) || (i == rows - 1 && j == cols - 1))
        printf("%4d ", 0);
      else {
        int neg = rand() % 5 ? -1 : 1;
        printf("%4d ", neg * (rand() % 100));
        //printf("-1000 ");
      }
    }
    putchar('\n');
  }
}

void solve() {
  #ifdef AZN
  //makeCase(5, 5);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests = next_int();
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  AMR11A::solve();
  return 0;
}

