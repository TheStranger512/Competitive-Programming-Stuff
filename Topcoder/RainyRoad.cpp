/*
 * Solved
 * SRM 525 Div2 Easy
 * Author: Andy Y.F. Huang
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

using namespace std;

class RainyRoad {
public:
  string isReachable(vector <string> road);
} ;

string RainyRoad::isReachable(vector <string> road) {
  for (int i = 0; i < (int) road[0].size(); i++)
    if (road[0][i] == 'W' && road[1][i] == 'W')
      return "NO";
  return "YES";
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, string p1) {
  cout << "Test " << testNum << ": [" << "{";
  for (int i = 0; int(p0.size()) > i; ++i) {
    if (i > 0) {
      cout << ",";
    }
    cout << "\"" << p0[i] << "\"";
  }
  cout << "}";
  cout << "]" << endl;
  RainyRoad *obj;
  string answer;
  obj = new RainyRoad();
  clock_t startTime = clock();
  answer = obj->isReachable(p0);
  clock_t endTime = clock();
  delete obj;
  bool res;
  res = true;
  cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
  if (hasAnswer) {
    cout << "Desired answer:" << endl;
    cout << "\t" << "\"" << p1 << "\"" << endl;
  }
  cout << "Your answer:" << endl;
  cout << "\t" << "\"" << answer << "\"" << endl;
  if (hasAnswer) {
    res = answer == p1;
  }
  if (!res) {
    cout << "DOESN'T MATCH!!!!" << endl;
  }
  else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
    cout << "FAIL the timeout" << endl;
    res = false;
  }
  else if (hasAnswer) {
    cout << "Match :-)" << endl;
  }
  else {
    cout << "OK, but is it right?" << endl;
  }
  cout << "" << endl;
  return res;
}

int main() {
  bool all_right;
  all_right = true;

  vector <string> p0;
  string p1;

  {
    // ----- test 0 -----
    string t0[] = {".W..", "...."};
    p0.assign(t0, t0 + sizeof (t0) / sizeof (t0[0]));
    p1 = "YES";
    all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 1 -----
    string t0[] = {".W..", "..W."};
    p0.assign(t0, t0 + sizeof (t0) / sizeof (t0[0]));
    p1 = "YES";
    all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 2 -----
    string t0[] = {".W..W..", "...WWW."};
    p0.assign(t0, t0 + sizeof (t0) / sizeof (t0[0]));
    p1 = "NO";
    all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 3 -----
    string t0[] = {"..", "WW"};
    p0.assign(t0, t0 + sizeof (t0) / sizeof (t0[0]));
    p1 = "YES";
    all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 4 -----
    string t0[] = {".WWWW.", "WWWWWW"};
    p0.assign(t0, t0 + sizeof (t0) / sizeof (t0[0]));
    p1 = "NO";
    all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 5 -----
    string t0[] = {".W.W.W.", "W.W.W.W"};
    p0.assign(t0, t0 + sizeof (t0) / sizeof (t0[0]));
    p1 = "YES";
    all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 6 -----
    string t0[] = {".............................................W.", ".............................................W."};
    p0.assign(t0, t0 + sizeof (t0) / sizeof (t0[0]));
    p1 = "NO";
    all_right = KawigiEdit_RunTest(6, p0, true, p1) && all_right;
    // ------------------
  }

  if (all_right) {
    cout << "You're a stud (at least on the example cases)!" << endl;
  }
  else {
    cout << "Some of the test cases had errors." << endl;
  }
  return 0;
}
// PROBLEM STATEMENT
// Fox Ciel is going to take a path to meet her friends. The path is tiled with 1x1 square tiles. It is N tiles long and 2 tiles wide. If we imagine that the path is going from the left to the right, we can view it as a rectangle with 2 rows and N columns of tiles.
// The rows of the path are numbered 0 to 1 from top to bottom, and the columns of the path are numbered 0 to N-1 from left to right. Ciel starts at the tile in row 0, column 0. She has to reach the tile in row 0, column N-1.
//
// In each step, Ciel can move to an adjacent tile. Two tiles are adjacent if they share at least one point (a side or a corner).
//
// Because it rained yesterday, some tiles are covered by puddles of water. Ciel will not step on these tiles. You are given a vector <string> road. The j-th character of i-th element is 'W' if a tile at i-th row of j-th column is covered by  water, and '.' otherwise.
//
// Return the string "YES" if she can move to her destination without entering a tile which is filled with water. Otherwise, return "NO".
//
// DEFINITION
// Class:RainyRoad
// Method:isReachable
// Parameters:vector <string>
// Returns:string
// Method signature:string isReachable(vector <string> road)
//
//
// NOTES
// -The constraints guarantee that the starting tile and the destination tile are never covered by water.
//
//
// CONSTRAINTS
// -road will contain exactly 2 elements.
// -Each elements of road will contain between 2 and 50 characters, inclusive.
// -All elements of road will contain the same number of characters.
// -Each character of road will be either '.' or 'W'.
// -The first character and the last character of 0-th element of road will be '.'.
//
//
// EXAMPLES
//
// 0)
// {".W.."
// ,"...."}
//
// Returns: "YES"
//
// One of the possible ways is as follows. Here, 'F' is the tile occupied by Fox Ciel.
//
// "FW.."
// "...."
//
// ".W.."
// "F..."
//
// ".W.."
// ".F.."
//
// ".W.."
// "..F."
//
// ".W.F"
// "...."
//
//
// 1)
// {".W.."
// ,"..W."}
//
// Returns: "YES"
//
//
//
// 2)
// {".W..W.."
// ,"...WWW."}
//
// Returns: "NO"
//
//
//
// 3)
// {".."
// ,"WW"}
//
// Returns: "YES"
//
//
//
// 4)
// {".WWWW."
// ,"WWWWWW"}
//
// Returns: "NO"
//
//
//
// 5)
// {".W.W.W."
// ,"W.W.W.W"}
//
// Returns: "YES"
//
//
//
// 6)
// {".............................................W."
// ,".............................................W."}
//
// Returns: "NO"
//
//
//
// END KAWIGIEDIT TESTING



//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
