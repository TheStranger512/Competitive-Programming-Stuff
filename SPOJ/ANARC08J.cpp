/* Solved
 * 4559. A Day at the Races - string processing
 * File:   ANARC08J.cpp
 * Author: Andy Huang
 * Created on May 12, 2012, 5:58 PM
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

using namespace std;

template <typename Type> inline void pln(Type x) {
  cout << x << endl;
}

struct String{
  static string trim(const string& str){
    int st = 0;
    int len = str.length();
    while (st < len && str[st] <= ' ')
      st++;
    while (st < len && str[len - 1] <= ' ')
      len--;
    return str.substr(st,len - st);
  }
};

struct Driver {
  string last;
  string name;
  int pts;
  int leads[8];

  Driver() {
  }

  Driver(string name, string last, int pts, int pos) {
    this->name = name;
    this->last = last;
    this->pts = pts;
    for (int i = 0; i < 8; i++) {
      leads[i] = 0;
    }
    leads[pos] = 1;
  }

  bool operator<(const Driver & other)const {
    if (pts != other.pts)
      return pts > other.pts;
    for (int i = 0; i < 8; i++)
      if (leads[i] != other.leads[i])
        return leads[i] > other.leads[i];
    if (last != other.last)
      return last.compare(other.last) <= 0;
    else
      return name.compare(other.name) <= 0;
  }

};

bool operator==(const string& a, const string& b) {
  int lena = a.length();
  int lenb = b.length();
  if (lena != lenb)
    return false;
  for (int i = 0; i < lena; i++) {
    if (a[i] != b[i])
      return false;
  }
  return true;
}

struct Team {
  string name;
  int pts;

  Team() {
  }

  Team(string name, int pts) {
    this->name = name;
    this->pts = pts;
  }

  bool operator<(const Team & other)const {
    if (pts != other.pts)
      return pts > other.pts;
    else
      return name.compare(other.name) <= 0;
  }

};

const int pts[] = {10, 8, 6, 5, 4, 3, 2, 1};
Team teams[600];
Driver drivers[600];
int races;
string team;

void solve() {
  for (int i = 0; i < 600; i++) {
    teams[i] = Team();
    drivers[i] = Driver();
  }
  int index1 = 0;
  int index2 = 0;
  getline(cin, team); //newline after number of races;
  while (races--) {
    getline(cin, team); //race title;
    getline(cin, team); //labels
    for (int z = 0; z < 8; z++) {
      int pos;
      string name, last;
      scanf("%d", &pos);
      pos--;
      cin >> name >> last;
      getline(cin, team);
      team = String::trim(team);
      team.erase(team.size() - 1);
      bool fnd = false;
      for (int i = 0; i < index1 && !fnd; i++) {
        if (drivers[i].name == name && drivers[i].last == last) {
          drivers[i].pts += pts[pos];
          drivers[i].leads[pos]++;
          fnd = true;
        }
      }
      if (!fnd)
        drivers[index1++] = Driver(name, last, pts[pos], pos);
      fnd = false;
      for (int i = 0; i < index2 && !fnd; i++) {
        if (teams[i].name == team) {
          teams[i].pts += pts[pos];
          fnd = true;
        }
      }
      if (!fnd)
        teams[index2++] = Team(team, pts[pos]);
    }
    getline(cin, team); //seperator line
  }
  sort(drivers, drivers + index1);
  sort(teams, teams + index2);
  puts("Drivers Standing:");
  for (int i = 0; i < index1; i++)
    printf("%-25s %d\n", (drivers[i].name + " " + drivers[i].last).c_str(), drivers[i].pts);
  puts("");
  puts("Teams Standing:");
  for (int i = 0; i < index2; i++)
    printf("%-25s %d\n", teams[i].name.c_str(), teams[i].pts);
  puts("");
}

int main() {
  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  scanf("%d", &races);
  int season = 1;
  while (races) {
    printf("Season %d:\n", season);
    solve();
    scanf("%d", &races);
    season++;
  }
  return 0;
}

