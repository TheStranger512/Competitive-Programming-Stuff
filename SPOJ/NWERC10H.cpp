/* Solved
 * 8629. Stock Prices
 * File:   NWERC10H.cpp
 * Author: Andy Y.F. Huang
 * Created on April 17, 2013, 11:08 PM
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

namespace NWERC10H {
typedef pair<int, int> Order; //(price, count)
priority_queue<Order, vector<Order>, greater<Order> > sells;
priority_queue<Order> buys;
char str[11];

void solve(int test_num) {
  while (!buys.empty()) buys.pop();
  while (!sells.empty()) sells.pop();
  int len, stock = -1;
  scanf("%d", &len);
  for (int i = 0; i < len; i++) {
    int ask = -1, bid = -1;
    int amount, price;
    scanf("%s %d shares at %d", str, &amount, &price);
    if (str[0] == 'b')
      buys.push(Order(price, amount));
    else
      sells.push(Order(price, amount));
    while (!buys.empty() && !sells.empty()) {
      Order buy = buys.top(), sell = sells.top();
      if (buy.first >= sell.first) {
        buys.pop(), sells.pop();
        int am = min(buy.second, sell.second);
        buy.second -= am;
        sell.second -= am;
        stock = sell.first;
        if (buy.second > 0)
          buys.push(buy);
        if (sell.second > 0)
          sells.push(sell);
      }
      else break;
    }
    if (!buys.empty())
      bid = buys.top().first;
    if (!sells.empty())
      ask = sells.top().first;
    if (ask == -1) printf("- ");
    else printf("%d ", ask);
    if (bid == -1) printf("- ");
    else printf("%d ", bid);
    if (stock == -1) printf("-\n");
    else printf("%d\n", stock);
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
  NWERC10H::solve();
  return 0;
}

