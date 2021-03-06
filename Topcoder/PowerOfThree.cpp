/*
 * Solved
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

using namespace std;

struct PowerOfThree {
  string ableToGet(int x, int y);
};

string PowerOfThree::ableToGet(int x, int y) {
  x = abs(x);
  y = abs(y);
  int d1[21] = { 0 }, d2[21] = { 0 }, end;
  for (int i = 0; ; i++) {
    d1[i] = x % 3;
    d2[i] = y % 3;
    if (x == 0 && y == 0) {
      end = i;
      break;
    }
    x /= 3;
    y /= 3;
  }
  //plnarr(d1, d1 + 20);
  //plnarr(d2, d2 + 20);
  for (int i = 0; i <= end; i++) {
    if (d1[i] == 3) {
      d1[i] = 0;
      d1[i + 1]++;
    }
    if (d2[i] == 3) {
      d2[i] = 0;
      d2[i + 1]++;
    }
    if (min(d1[i], d2[i]) > 0 || (i != end && max(d1[i], d2[i]) == 0))
      return "Impossible";
    if (d1[i] == 2)
      d1[i + 1]++;
    else if (d2[i] == 2)
      d2[i + 1]++;
  }
  return "Possible";
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, string p2) {
  cout << "Test " << testNum << ": [" << p0 << "," << p1;
  cout << "]" << endl;
  PowerOfThree *obj;
  string answer;
  obj = new PowerOfThree();
  clock_t startTime = clock();
  answer = obj->ableToGet(p0, p1);
  clock_t endTime = clock();
  delete obj;
  bool res;
  res = true;
  cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
  if (hasAnswer) {
    cout << "Desired answer:" << endl;
    cout << "\t" << "\"" << p2 << "\"" << endl;
  }
  cout << "Your answer:" << endl;
  cout << "\t" << "\"" << answer << "\"" << endl;
  if (hasAnswer) {
    res = answer == p2;
  }
  if (!res) {
    cout << "DOESN'T MATCH!!!!" << endl;
  } else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
    cout << "FAIL the timeout" << endl;
    res = false;
  } else if (hasAnswer) {
    cout << "Match :-)" << endl;
  } else {
    cout << "OK, but is it right?" << endl;
  }
  cout << "" << endl;
  return res;
}
int main() {
#ifdef AZN
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
#endif

  bool all_right;
  all_right = true;

  int p0;
  int p1;
  string p2;

  {
    // ----- test 0 -----
    p0 = 1;
    p1 = 3;
    p2 = "Possible";
    all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
    // ------------------
  }

  {
    // ----- test 1 -----
    p0 = 0;
    p1 = 2;
    p2 = "Possible";
    all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
    // ------------------
  }

  {
    // ----- test 2 -----
    p0 = 1;
    p1 = 9;
    p2 = "Impossible";
    all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
    // ------------------
  }

  {
    // ----- test 3 -----
    p0 = 3;
    p1 = 0;
    p2 = "Impossible";
    all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
    // ------------------
  }

  {
    // ----- test 4 -----
    p0 = 1;
    p1 = 1;
    p2 = "Impossible";
    all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
    // ------------------
  }

  {
    // ----- test 5 -----
    p0 = -6890;
    p1 = 18252;
    p2 = "Possible";
    all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
    // ------------------
  }

  {
    // ----- test 6 -----
    p0 = 1000000000;
    p1 = -1000000000;
    p2 = "Impossible";
    all_right = KawigiEdit_RunTest(6, p0, p1, true, p2) && all_right;
    // ------------------
  }

  {
    // ----- test 7 -----
    p0 = 0;
    p1 = 0;
    p2 = "Possible";
    all_right = KawigiEdit_RunTest(7, p0, p1, true, p2) && all_right;
    // ------------------
  }

  if (all_right) {
    cout << "You're a stud (at least on the example cases)!" << endl;
  } else {
    cout << "Some of the test cases had errors." << endl;
  }
  return 0;
}
// PROBLEM STATEMENT
// Fox Ciel has a robot.
// The robot is located on an infinite plane.
// At the beginning, the robot starts at the coordinates (0, 0).
// The robot can then make several steps.
// The steps are numbered starting from 0.
// 
// In each step, Ciel must choose one of four directions for the robot: left (x coordinate decreases), right (x coordinate increases), up (y coordinate increases), or down (y coordinate decreases).
// In step k, the robot will move 3^k units in the chosen direction.
// It is not allowed to skip a step.
// 
// You are given ints x and y.
// Return "Possible" (quotes for clarity) if it is possible that the robot reaches the point (x,y) after some (possibly zero) steps.
// Otherwise, return "Impossible".
// 
// DEFINITION
// Class:PowerOfThree
// Method:ableToGet
// Parameters:int, int
// Returns:string
// Method signature:string ableToGet(int x, int y)
// 
// 
// CONSTRAINTS
// -x will be between -1,000,000,000 and 1,000,000,000, inclusive.
// -y will be between -1,000,000,000 and 1,000,000,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 1
// 3
// 
// Returns: "Possible"
// 
// In step 0 Ciel will send the robot right to (1,0). In step 1 she will send it up to (1,3).
// 
// 1)
// 0
// 2
// 
// Returns: "Possible"
// 
// The robot will move from (0,0) down to (0,-1) and then up to (0,2).
// 
// 2)
// 1
// 9
// 
// Returns: "Impossible"
// 
// Note that it is not allowed to move the robot right in step 0, skip step 1, and then move the robot up in step 2.
// 
// 3)
// 3
// 0
// 
// Returns: "Impossible"
// 
// 
// 
// 4)
// 1
// 1
// 
// Returns: "Impossible"
// 
// 
// 
// 5)
// -6890
// 18252
// 
// Returns: "Possible"
// 
// 
// 
// 6)
// 1000000000
// -1000000000
// 
// Returns: "Impossible"
// 
// 
// 
// 7)
// 0
// 0
// 
// Returns: "Possible"
// 
// 
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
