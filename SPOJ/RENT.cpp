/* Solved
 * 130. Rent your airplane and make money
 * File:   RENT.cpp
 * Author: Andy Y.F. Huang
 * Created on January 12, 2013, 9:53 PM
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
namespace RENT {

struct Order {
  int start, end, money;

  Order() { }

  Order(int end, int money) : start(0), end(end), money(money) { }

  bool operator<(const Order & o) const {
    return start < o.start;
  }
} ;

struct CmpPrice {

  bool operator()(const Order& a, const Order & b) const {
    return a.money < b.money;
  }
} ;

struct CmpEnd {

  bool operator()(const Order& a, const Order & b) const {
    return a.end > b.end;
  }
} ;

Order orders[11111];

void solve(int test_num) {
  int len;
  scanf("%d", &len);
  for (int i = 0; i < len; i++) {
    scanf("%d %d %d", &orders[i].start, &orders[i].end, &orders[i].money);
    orders[i].end += orders[i].start;
  }
  sort(orders, orders + len);
  priority_queue<Order, vector<Order>, CmpPrice> ended;
  priority_queue<Order, vector<Order>, CmpEnd> notended;
  for (int i = 0; i < len; i++) {
    while (!notended.empty() && notended.top().end <= orders[i].start) {
      ended.push(notended.top());
      notended.pop();
    }
    if (ended.empty())
      notended.push(orders[i]);
    else
      notended.push(Order(orders[i].end, orders[i].money + ended.top().money));
  }
  for (;!notended.empty(); notended.pop())
    ended.push(notended.top());
  printf("%d\n", ended.top().money);
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
  RENT::solve();
  return 0;
}

