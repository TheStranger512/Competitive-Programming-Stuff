/* Solved
 * SRM 586 Div1 Easy
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

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

struct PiecewiseLinearFunction {
  int maximumSolutions(vector <int> Y);
} ;

int PiecewiseLinearFunction::maximumSolutions(vector <int> y) {
  int N = y.size();
  vector<double> v;
  for (int i = 1; i < N; i++) {
    if (y[i] == y[i - 1])
      return -1;
    if (y[i - 1] < y[i]) {
      v.push_back(y[i - 1] + 0.5);
      v.push_back(y[i] - 0.5);
    }
    else {
      v.push_back(y[i - 1] - 0.5);
      v.push_back(y[i] + 0.5);
    }
  }
  int res = 0;
  for (int i = 0; i < v.size(); i++) {
    int cnt = 0;
    for (int j = 0; j + 1 < N; j++) {
      int a = min(y[j], y[j + 1]);
      int b = max(y[j], y[j + 1]);
      if (a <= v[i] && v[i] <= b)
        cnt++;
    }
    res = max(res, cnt);
  }
  for (int i = 0; i < N; i++) {
    int cnt = count(y.begin(), y.end(), y[i]);
    for (int j = 0; j + 1 < N; j++) {
      int a = min(y[j], y[j + 1]);
      int b = max(y[j], y[j + 1]);
      if (a < y[i] && y[i] < b)
        cnt++;
    }
    res = max(res, cnt);
  }
  return res;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof

bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, int p1) {
  cout << "Test " << testNum << ": [" << "{";
  for (int i = 0; int(p0.size()) > i; ++i) {
    if (i > 0) {
      cout << ",";
    }
    cout << p0[i];
  }
  cout << "}";
  cout << "]" << endl;
  PiecewiseLinearFunction *obj;
  int answer;
  obj = new PiecewiseLinearFunction();
  clock_t startTime = clock();
  answer = obj->maximumSolutions(p0);
  clock_t endTime = clock();
  delete obj;
  bool res;
  res = true;
  cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
  if (hasAnswer) {
    cout << "Desired answer:" << endl;
    cout << "\t" << p1 << endl;
  }
  cout << "Your answer:" << endl;
  cout << "\t" << answer << endl;
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
  #ifdef AZN
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif

  bool all_right;
  all_right = true;

  vector <int> p0;
  int p1;

  {
    // ----- test 0 -----
    int t0[] = {3, 2};
    p0.assign(t0, t0 + sizeof (t0) / sizeof (t0[0]));
    p1 = 1;
    all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 1 -----
    int t0[] = {4, 4};
    p0.assign(t0, t0 + sizeof (t0) / sizeof (t0[0]));
    p1 = -1;
    all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 2 -----
    int t0[] = {1, 4, -1, 2};
    p0.assign(t0, t0 + sizeof (t0) / sizeof (t0[0]));
    p1 = 3;
    all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 3 -----
    int t0[] = {2, 1, 2, 1, 3, 2, 3, 2};
    p0.assign(t0, t0 + sizeof (t0) / sizeof (t0[0]));
    p1 = 5;
    all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 4 -----
    int t0[] = {125612666, -991004227, 0, 6, 88023, -1000000000, 1000000000, -1000000000, 1000000000};
    p0.assign(t0, t0 + sizeof (t0) / sizeof (t0[0]));
    p1 = 6;
    all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
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
// F is a function that is defined on all real numbers from the closed interval [1,N].
// You are given a vector <int> Y with N elements.
// For each i (1 <= i <= N) we have F(i) = Y[i-1].
// Additionally, you know that F is piecewise linear: for each i, on the interval [i,i+1] F is a linear function.
// The function F is uniquely determined by this information.
// For example, if F(4)=1 and F(5)=6 then we must have F(4.7)=4.5.
//
// As another example, this is the plot of the function F for Y = {1, 4, -1, 2}.
//
//
//
// Given a real number y, we can count the number of solutions to the equation F(x)=y.
// For example, for the function plotted above there are 0 solutions for y=7, there is 1 solution for y=4, and there are 3 solutions for y=1.1.
// We are looking for the largest number of solutions such an equation can have.
// For the function plotted above the answer would be 3: there is no y such that F(x)=y has more than 3 solutions.
//
// If there is an y such that the equation F(x)=y has infinitely many solutions, return -1.
// Otherwise, return the maximum possible number of solutions such an equation may have.
//
//
// DEFINITION
// Class:PiecewiseLinearFunction
// Method:maximumSolutions
// Parameters:vector <int>
// Returns:int
// Method signature:int maximumSolutions(vector <int> Y)
//
//
// CONSTRAINTS
// -Y will contain between 2 and 50 elements, inclusive.
// -Each element of Y will be between -1,000,000,000 and 1,000,000,000, inclusive.
//
//
// EXAMPLES
//
// 0)
// {3, 2}
//
// Returns: 1
//
// The graph of this function is a line segment between (1, 3) and (2, 2). For any y such that 2 ? y ? 3 the equation F(x)=y has 1 solution, and for any other y it has 0 solutions.
//
// 1)
// {4, 4}
//
// Returns: -1
//
// The function's plot is a horizontal line segment between points (1, 4) and (2, 4). For y=4, F(x)=y has infinitely many solutions.
//
// 2)
// {1, 4, -1, 2}
//
// Returns: 3
//
// This is the example from the problem statement. Three solutions are obtained for any value of y between 1 and 2, inclusive:
//
//
//
// 3)
// {2, 1, 2, 1, 3, 2, 3, 2}
//
// Returns: 5
//
//
//
// 4)
// {125612666, -991004227, 0, 6, 88023, -1000000000, 1000000000, -1000000000, 1000000000}
//
// Returns: 6
//
//
//
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
