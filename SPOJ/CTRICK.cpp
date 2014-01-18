/* Solved
 * 1108. Card Trick
 * File:   CTRICK.cpp
 * Author: Andy Y.F. Huang
 * Created on August 5, 2012, 8:50 PM
 */

#include <cstdio>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

namespace CTRICK {
int arr[20010];
int tree[20010];
int N;

void update(int pos, int val) {
  for (int i = pos; i <= N; i += i&-i)
    tree[i] += val;
}

int lowerbound(int val) {
  int res = 0;
  for (int i = 1 << 15; i > 0; i >>= 1)
    if (res + i <= N && tree[res + i] < val)
      val -= tree[res += i];
  return res + 1;
}

void solve(int test_num) {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    update(i, 1);
  int prev = 1;
  for (int i = 1; i <= N; i++) {
    int rank = (prev + i - 1) % (N - i + 1) + 1;
    int next = lowerbound(rank);
    arr[next] = i;
    update(next, -1);
    prev = rank;
  }
  for (int i = 1; i <= N; i++)
    printf("%d ", arr[i]);
  putchar('\n');
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  CTRICK::solve();
  return 0;
}

