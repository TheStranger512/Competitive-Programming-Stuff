/* Solved
 * IOI '06 - Merida, Yucatan, Mexico
 * Pyramid
 * File:   ioi0612.cpp
 * Author: Andy Y.F. Huang
 * Created on December 20, 2012, 9:34 PM
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
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <iomanip>
#include <cassert>
#include <ctime>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace ioi0612 {
#define lim 1111

template <class T> class AznDeque {
  int front_m_, back_m_;
  T data_m_[lim];
public:

  AznDeque() {
    front_m_ = back_m_ = 0;
  }

  int size() const {
    return back_m_ - front_m_;
  }

  bool empty() const {
    return front_m_ == back_m_;
  }

  T front() const {
    return data_m_[front_m_];
  }

  T back() const {
    return data_m_[back_m_ - 1];
  }

  T pop_front() {
    return data_m_[front_m_++];
  }

  T pop_back() {
    return data_m_[--back_m_];
  }

  void push_front(T val) {
    data_m_[--front_m_] = val;
  }

  void push_back(T val) {
    data_m_[back_m_++] = val;
  }

} ;

int dp[lim][lim];
AznDeque<pair<int, int> > dq[1111];
//first: row start, second: sum

inline int getsum(int r1, int c1, int height, int width) {
  int r2 = r1 + height - 1, c2 = c1 + width - 1;
  return dp[r2][c2] - dp[r1 - 1][c2] - dp[r2][c1 - 1] + dp[r1 - 1][c1 - 1];
}

void solve(int test_num) {
  int rows, cols, a, b, c, d;
  scanf("%d %d %d %d %d %d", &cols, &rows, &b, &a, &d, &c);
  for (int r = 1; r <= rows; r++) {
    for (int c = 1; c <= cols; c++) {
      scanf("%d", &dp[r][c]);
      dp[r][c] += dp[r - 1][c] + dp[r][c - 1] - dp[r - 1][c - 1];
    }
  }
  int r1 = -1, c1 = -1, r2 = -1, c2 = -1, ans = 0;
  int y2 = 2;
  for (int y = 1; y + a - 1 <= rows; y++) {
    for ( ; y2 + c - 1 < y + a - 1; y2++) {
      for (int x = 2; x + d - 1 < cols; x++) {
        if (!dq[x].empty() && dq[x].front().first <= y)
          dq[x].pop_front();
        int sum = getsum(y2, x, c, d);
        while (!dq[x].empty() && sum < dq[x].back().second)
          dq[x].pop_back();
        dq[x].push_back(make_pair(y2, sum));
      }
    }
    //    for (int x = 1; x <= cols; x++)
    //      pf(dq[x].size()), pf(' ');
    //    pln("");
    int x2 = 2;
    AznDeque<pair<int, int> > q;
    for (int x = 1; x + b - 1 <= cols; x++) {
      for (; x2 + d - 1 < x + b - 1; x2++) {
        if (!q.empty() && q.front().first <= x)
          q.pop_front();
        while (!q.empty() && dq[x2].front().second < q.back().second )
          q.pop_back();
        q.push_back(make_pair(x2, dq[x2].front().second));
      }
      int temp = getsum(y, x, a, b) - q.front().second;
      if (temp > ans) {
        r1 = y;
        c1 = x;
        c2 = q.front().first;
        r2 = dq[q.front().first].front().first;
        ans = temp;
      }
    }
  }
  //pln(ans);
  printf("%d %d\n%d %d\n", c1, r1, c2, r2);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve(1);
}
}

int main() {
  ioi0612::solve();
  return 0;
}

