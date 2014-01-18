/* Solved
 * 11373. Coke madness - min prefix sum in array
 * File:   RPLC.cpp
 * Author: Andy Huang
 * Created on May 6, 2012, 10:30 PM
 */

#include <stdio.h>

typedef long long ll;

struct Long{
  const static long long max_value = 9223372036854775807LL;
  const static long long min_value = -9223372036854775807LL;
  
};

void solve() {
  int n;
  ll sum = 0, ans = Long::max_value;
  scanf("%d", &n);
  while (n--){
    int temp;
    scanf("%d", &temp);
    sum += temp;
    if (sum < ans)
      ans = sum;
  }
  if (ans < 0)
    ans *= -1;
  else
    ans = 0;
  printf("%lld\n", ans + 1);
}

int main() {
  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++){
    printf("Scenario #%d: ", i);
    solve();
  }
  return 0;
}

