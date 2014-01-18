/*
 * Solved
 * 3033. Help the soldier
 * File:   SOLDIER.cpp
 * Author: Andy Y.F. Huang
 * Created on January 12, 2013, 9:41 PM
 */

#include <algorithm>
#include <cstdio>
#include <vector>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace SOLDIER {
vector<pair<int, int> > items[6];
vector<int> vals;

void solve(int test_num) {
  vals.clear();
  for (int i = 0; i < 6; i++)
    if (items[i].size())
      items[i].clear();
  int itemcnt, budget;
  scanf("%d %d", &itemcnt, &budget);
  for (int i = 0; i < itemcnt; i++) {
    int type, price, value;
    scanf("%d %d %d", &type, &price, &value);
    items[--type].push_back(make_pair(value, price));
    vals.push_back(value);
  }
  sort(vals.begin(), vals.end());
  vals.erase(unique(vals.begin(), vals.end()), vals.end());
  for (int i = (int) vals.size() - 1; i >= 0; i--) {
    int tobuy = 0;
    for (int j = 0; j < 6; j++) {
      bool got = false;
      for (int k = 0; k < (int) items[j].size(); k++)
        if (items[j][k].first >= vals[i]) {
          tobuy += items[j][k].second;
          got = true;
          break;
        }
      if (!got) tobuy += 1 << 20;
    }
    if (tobuy <= budget) {
      printf("%d\n", vals[i]);
      return;
    }
  }
  puts("0");
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  solve(1);
}
}

int main() {
  SOLDIER::solve();
  return 0;
}

