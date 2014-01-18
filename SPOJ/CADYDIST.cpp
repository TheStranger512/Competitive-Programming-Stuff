/* Solved
 * 10442. Candy Distribution
 * File:   CADYDIST.cpp
 * Author: Andy Huang
 * Created on April 9, 2012, 9:16 PM
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
#define pln(x) cout << (x) << '\n'
#define ve(x) vector<x>
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define ms(x,n) memset(x,n,sizeof(x))
#define si(x) scanf("%d",&x)
#define ull unsigned long long

using namespace std;

ull c[100005];
ull p[100005];
int n;

void solve() {
  int i = 0;
  while(i < n){
    scanf("%lld",&c[i]);
    i++;
  }
  i = 0;
  while(i < n){
    scanf("%lld",&p[i]);
    i++;
  }
  sort(c,c+n);
  sort(p,p+n);
  i = 0;
  ull ans = 0;
  while(i < n){
    ans += c[i]*p[n-i-1];
    i++;
  }
  pln(ans);
}

int main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  si(n);
  while(n){
    solve();
    si(n);
  }
  return 0;
}

