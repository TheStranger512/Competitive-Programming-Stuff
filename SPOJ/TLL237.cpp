/* Solved
 * 11956. Addicted
 * File:   TLL237.cpp
 * Author: Andy Y.F. Huang
 * Created on August 17, 2012, 1:24 AM
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
namespace TLL237 {

struct Piggy {
  int money, id;

  Piggy(int money, int id) : money(money), id(id) {
  }

  bool operator<(const Piggy & p) const {
    return money != p.money ? money > p.money : id > p.id;
  }
} ;

priority_queue<Piggy> heap;
char seq[100010];

void solve(int test_num) {
  int banks, len;
  scanf("%d\r\n ", &banks);
  gets(seq);
  len = strlen(seq);
  for (int i = 0; i < banks; i++)
    heap.push(Piggy(0, i));
  for (int i = 0; i < len; i++) {
    Piggy a = heap.top();
    heap.pop();
    Piggy b = heap.top();
    heap.pop();
    //pln(a.id, a.money, b.id, b.money);
    if (seq[i] == '1')
      a.money++;
    else
      b.money++;
    heap.push(a);
    heap.push(b);
  }
  int a = heap.top().money;
  heap.pop();
  printf("%d %d", a, heap.top().money);
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
  TLL237::solve();
  return 0;
}

