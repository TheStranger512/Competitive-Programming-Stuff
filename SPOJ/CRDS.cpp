/* Solved
 * 10509. Cards
 * File:   CRDS.cpp
 * Author: Andy Huang
 * Created on March 13, 2012, 2:47 PM
 */

#include <stdio.h>
#include <iostream>
#include <math.h>
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

#define forl(a,b,c) for (int a=b;a<c;a++)
#define ford(a,b,c) for (int a=b;a>=c;a--)
#define gl(s) getline(cin,s)
#define pln(x) cout << x << endl
#define ve(x) vector<x>
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define ms(x,n) memset(x,n,sizeof(x))
#define si(x) scanf("%lld",&x)

using namespace std;

const unsigned long long MOD = 1000007uLL;

void solve() {
  unsigned long long n;
  si(n);
  printf("%lld\n", (n*(3*n + 1)/ 2)%MOD);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  unsigned long long t;
  si(t);
  while (t--)
    solve();
  return 0;
}

