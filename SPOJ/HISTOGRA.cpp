/* Solved
 * 1805. Largest Rectangle in a Histogram
 * File:   HISTOGRA.cpp
 * Author: Andy Y.F. Huang
 * Created on August 3, 2012, 1:34 AM
 */

#include <cstdio>
#include <algorithm>
#include <stack>
#include <set>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace HISTOGRA {
const int k_max_len = 100010;
long long heights[k_max_len];
stack<int> s;
stack<int> l;

void solve(int test_num, int len) {
  for (int i = 0; i < len; i++)
    scanf("%lld", &heights[i]);
  long long ans = 0;
  for (int i = 0; i < len; i++) {
    long long cur = heights[i];
    if (s.empty() || cur > heights[s.top()]) {
      s.push(i);
      l.push(i);
    }
    else if (cur == heights[s.top()])
      continue;
    int j = i;
    while (!s.empty() && cur < heights[s.top()]) {
      long long h = heights[s.top()];
      s.pop();
      j = l.top();
      l.pop();
      ans = max(ans, h * (i - j));
    }
    s.push(i);
    l.push(j);
  }
  while (!s.empty()) {
    ans = max(ans, heights[s.top()] * (len - l.top()));
    s.pop();
    l.pop();
  }
  printf("%lld\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (true) {
    int len;
    scanf("%d", &len);
    if (!len)
      break;
    solve(1, len);
  }
}
}

int main() {
  HISTOGRA::solve();
  return 0;
}

