/* Solved
 * 8545. Subset sum
 * File:   MAIN72.cpp
 * Author: Andy Huang
 * Created on March 13, 2012, 3:04 PM
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
#define si(x) scanf("%d",&x)

using namespace std;

bool dp[100001];
int x[100];

void solve() {
  int n, ans = 0, maxi = 0;
  si(n);
  ms(dp,false);
  ms(x,0);
  forl(i,0,n)
    si(x[i]);
  dp[0] = true;
  sort(x,x+n);
  forl(i,0,n){
    ford(j,maxi,0){
      if (dp[j]){
        dp[j+x[i]] = true;
        if (j+x[i] > maxi)
          maxi = j+x[i];
      }
    }
//    forl(i,0,8)
//      cout << dp[i] << ' ';
//    cout << endl;
  }

  forl(i,0,maxi+1)
    if(dp[i])
      ans += i;
  printf("%d\n", ans);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t;
  si(t);
  while (t--)
    solve();
  return 0;
}

