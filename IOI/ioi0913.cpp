/* Solved
 * IOI '09 - Plovdiv, Bulgaria - POI
 * File:   ioi0913.cpp
 * Author: Andy Huang
 * Created on March 30, 2012, 8:49 PM
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

struct Azn{
  int pt;
  int solved;
  int id;
  Azn(int pt,int solved,int id)
  : pt(pt), solved(solved), id(id) 
  {  
  }
  
  Azn(){}
  
  Azn(const Azn& x){
    pt = x.pt;
    solved = x.solved;
    id = x.id;
  }
  
  
};

bool x[2005][2005];
int pt[2000];
Azn sc[2000];

bool cmp(const Azn& y, const Azn& x){
    if (y.pt > x.pt)
      return true;
    else if (y.pt == x.pt){
      if (y.solved > x.solved)
        return true;
      else if (y.solved == x.solved)
        return y.id < x.id;
      else
        return false;
    }
    else
      return false;
  }

void solve() {
  ms(pt,0);
  int n, t, p;
  scanf("%d %d %d",&n,&t,&p);
  p--;
  forl(i,0,n){
    forl(j,0,t){
      si(x[j][i]);
      if (x[j][i] == 0)
        pt[j] += !x[j][i];
    }
  }
  forl(i,0,n){
    Azn temp(0,0,i);
    forl(j,0,t){
      temp.pt += pt[j]*x[j][i];
      temp.solved += x[j][i];
    }
    //cout << temp.id <<","<<temp.solved<<","<<temp.pt<<endl;
    sc[i] = temp;
  }
  sort(sc,sc+n,cmp);
  forl(i,0,n){
    //cout << sc[i].id <<","<<sc[i].solved<<","<<sc[i].pt<<endl;
    if (sc[i].id == p){
      printf("%d %d",sc[i].pt,i+1);
      return;   
    }
  }
}

int main() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve();
  return 0;
}


