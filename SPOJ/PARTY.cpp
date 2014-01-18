/* Solved
 * 97. Party Schedule
 * File:   PARTY.cpp
 * Author: Andy Huang
 * Created on March 13, 2012, 1:18 PM
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

int m, n;
int f[100];
int c[100];
int dp[501][101];

void solve() {
  ms(dp,0);
  forl(i,0,n){
    si(c[i]);
    si(f[i]);
  }
  forl(i,1,n+1){
    forl(j,1,m+1){
      if (j-c[i-1] >=0 )
        dp[j][i] = max(dp[j][i-1],f[i-1]+dp[j-c[i-1]][i-1]);
      else
        dp[j][i] = dp[j][i-1];
    }
  }
  int mfun = -1;
  int mbud = 1000;
  forl(i,0,m+1){
    if (dp[i][n] > mfun){
      mfun = dp[i][n];
      mbud = i;
    }
  }
  printf("%d %d\n",mbud, mfun);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  si(m);
  si(n);
  while (m){
    solve();
    si(m);
    si(n);
  }
  return 0;
}

