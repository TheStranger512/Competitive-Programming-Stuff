/*
 * Solved
 * SRM 494 Div1 Easy
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

class Painting {
public:
  int largestBrush(vector <string> picture);
} ;

bool paint[55][55];

int Painting::largestBrush(vector <string> pic) {
  int rows = pic.size(), cols = pic[0].size();
  int ans = 1;
  int blackcnt = 0;
  for (int r = 0; r < rows; r++)
    blackcnt += count(pic[r].begin(), pic[r].end(), 'B');
  for (int low = 1, high = min(rows, cols); low <= high; ) {
    memset(paint, false, sizeof (paint));
    int mid = (low + high) >> 1;
    for (int r = 0; r + mid <= rows; r++) {
      for (int c = 0; c + mid <= cols; c++) {
        bool ok = true;
        for (int rr = r; rr < r + mid; rr++)
          for (int cc = c; cc < c + mid; cc++)
            if (pic[rr][cc] == 'W')
              ok = false;
        if (ok)
          for (int rr = r; rr < r + mid; rr++)
            for (int cc = c; cc < c + mid; cc++)
              paint[rr][cc] = true;
      }
    }
    int cnt = 0;
    for (int r = 0; r < rows; r++)
      cnt += count(paint[r], paint[r] + cols, true);
    if (cnt == blackcnt) {
      ans = max(ans, mid);
      low = mid + 1;
    }
    else high = mid - 1;
  }
  return ans;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof

bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
  cout << "Test " << testNum << ": [" << "{";
  for (int i = 0; int(p0.size()) > i; ++i) {
    if (i > 0) {
      cout << ",";
    }
    cout << "\"" << p0[i] << "\"";
  }
  cout << "}";
  cout << "]" << endl;
  Painting *obj;
  int answer;
  obj = new Painting();
  clock_t startTime = clock();
  answer = obj->largestBrush(p0);
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

  vector <string> p0;
  int p1;

  {
    // ----- test 0 -----
    string t0[] = {"BBBB", "BBBB", "BBBB", "BBBB"};
    p0.assign(t0, t0 + sizeof (t0) / sizeof (t0[0]));
    p1 = 4;
    all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 1 -----
    string t0[] = {"BBBB", "BWWB", "BWWB", "BBBB"};
    p0.assign(t0, t0 + sizeof (t0) / sizeof (t0[0]));
    p1 = 1;
    all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 2 -----
    string t0[] = {"WBBBBB", "BBBBBB", "BBBBBB", "BBBBBB"};
    p0.assign(t0, t0 + sizeof (t0) / sizeof (t0[0]));
    p1 = 3;
    all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 3 -----
    string t0[] = {"BBBB", "BBBB", "WBBB", "BBBB", "BBBB", "BBBB"};
    p0.assign(t0, t0 + sizeof (t0) / sizeof (t0[0]));
    p1 = 2;
    all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 4 -----
    string t0[] = {"WBBBBBWWWWWWWWW", "WBBBBBBWWWWWWWW", "WBBBBBBBBBBBWWW", "WBBBBBBBBBBBWWW", "BBBBBBBBBBBBBBB", "BBBBBBBBBBBBBBB", "BBBBBBBBBBBBBBB", "BBBBBBBBWWBBBBB", "BBBBBBBBWBBBBBB", "WBBBBBBBWBBBBBW", "BBBBBBBWWBBBBBW", "BBBBBBBWWBBBBBW", "BBBBBBWWWBBBBBW", "BBBBBWWWWWWWWWW", "BBBBBWWWWWWWWWW"};
    p0.assign(t0, t0 + sizeof (t0) / sizeof (t0[0]));
    p1 = 5;
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
// Normally Mr. Grey is not a painter, but he recently had an absolutely brilliant idea for a picture. He thinks that once drawn, it will bring him world-wide fame.
//
// The picture will be painted on an NxM sheet of white paper consisting of 1x1 squares. Its rows are numbered from 0 to N-1 and the columns are numbered from 0 to M-1. The cell in row i, column j is denoted as (i, j).
//
// Of course, Mr. Grey already has a picture plan in his mind. It is given in a vector <string> picture, which contains exactly N elements, where each element contains exactly M characters. ?haracter j in element i of picture will be 'B' if the cell (i, j) must be painted black, and it will be 'W' if this cell must be left white.
//
// Mr. Grey has a lot of black paint, but unfortunately he doesn't have a brush, so he went to a local shop to buy one. The shop offers square brushes of different sizes. More exactly, for each positive integer S, one can buy an SxS brush in the shop. Using an SxS brush, Mr. Grey will be able to paint entirely black SxS squares on the sheet of paper. In other words, he can choose row R and column C such that 0 <= R <= N - S, 0 <= C <= M - S, and then paint all cells (r, c) such that R <= r < R + S and C <= c < C + S in black paint. He can repeat this operation infinitely many times. If a cell must be black according to picture, it may be painted black several times. However, if a cell must be white, then it must never be painted black.
//
// It's easy to see that every picture can be drawn using a 1x1 brush, but it will be impossible to draw some pictures using larger brushes. Buying a 1x1 brush seems to be the most practical choice. However, Mr. Grey is sure that big masters must use big brushes. Therefore, he would like to buy the largest possible brush that will still allow him to draw the picture that he has in mind.
//
// Return the maximum value of S such that it's possible to draw picture using a brush of size SxS.
//
// DEFINITION
// Class:Painting
// Method:largestBrush
// Parameters:vector <string>
// Returns:int
// Method signature:int largestBrush(vector <string> picture)
//
//
// CONSTRAINTS
// -picture will contain between 1 and 50 elements, inclusive.
// -Each element of picture will contain between 1 and 50 characters, inclusive.
// -All elements of picture will contain the same number of characters.
// -Each character in picture will be 'B' or 'W'.
// -There will be at least one 'B' character in picture.
//
//
// EXAMPLES
//
// 0)
// {"BBBB",
//  "BBBB",
//  "BBBB",
//  "BBBB"}
//
// Returns: 4
//
// It's easy to see that a solid 4x4 black square can be drawn using a 4x4 brush.
//
// 1)
// {"BBBB",
//  "BWWB",
//  "BWWB",
//  "BBBB"}
//
// Returns: 1
//
// This time we have only a border of a 4x4 square and it's necessary to have a 1x1 brush in order to draw it.
//
// 2)
// {"WBBBBB",
//  "BBBBBB",
//  "BBBBBB",
//  "BBBBBB"}
//
//
// Returns: 3
//
// A completely black 4x6 rectangle can be drawn using a 4x4 brush. However, if we want just one cell within it to remain white, the size of the brush will have to be reduced. In this example, a 3x3 brush would work.
//
// 3)
// {"BBBB",
//  "BBBB",
//  "WBBB",
//  "BBBB",
//  "BBBB",
//  "BBBB"}
//
//
// Returns: 2
//
// This is very similar to the previous example, but the white cell is in a different location. Mr. Grey will have to buy a 2x2 brush in this case.
//
// 4)
// {"WBBBBBWWWWWWWWW",
//  "WBBBBBBWWWWWWWW",
//  "WBBBBBBBBBBBWWW",
//  "WBBBBBBBBBBBWWW",
//  "BBBBBBBBBBBBBBB",
//  "BBBBBBBBBBBBBBB",
//  "BBBBBBBBBBBBBBB",
//  "BBBBBBBBWWBBBBB",
//  "BBBBBBBBWBBBBBB",
//  "WBBBBBBBWBBBBBW",
//  "BBBBBBBWWBBBBBW",
//  "BBBBBBBWWBBBBBW",
//  "BBBBBBWWWBBBBBW",
//  "BBBBBWWWWWWWWWW",
//  "BBBBBWWWWWWWWWW"}
//
//
// Returns: 5
//
//
//
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
