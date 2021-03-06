/*
 * Solved
 * SRM TCO 13 Round 1A Easy
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

struct HouseBuilding {
	int getMinimum(vector <string> area);
};

int height[55][55];

int HouseBuilding::getMinimum(vector <string> area) {
  const int rows = area.size(), cols = area.front().size();
  for (int r = 0; r < rows; r++)
    for (int c = 0; c < cols; c++)
      height[r][c] = area[r][c] - '0';
  int best = 1 << 20;
  for (int low = 0; low < 9; low++) {
    int high = low + 1, temp = 0;
    for (int r = 0; r < rows; r++)
      for (int c = 0; c < cols; c++)
        temp += min(abs(height[r][c] - low), abs(height[r][c] - high));
    best = min(best, temp);
  }
  return best;

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
	HouseBuilding *obj;
	int answer;
	obj = new HouseBuilding();
	clock_t startTime = clock();
	answer = obj->getMinimum(p0);
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

	vector <string> p0;
	int p1;

	{
	// ----- test 0 -----
	string t0[] = {"10","31"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	string t0[] = {"54454","61551"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 7;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	string t0[] = {"989"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	string t0[] = {"90"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 8;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	string t0[] = {"5781252","2471255","0000291","1212489"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 53;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
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
// Manao is building a new house. He already purchased a rectangular area where he will place the house. The basement of the house should be built on a level ground, so Manao will have to level the entire area. The area is leveled if the difference between the heights of its lowest and highest square meter is at most 1. Manao wants to measure the effort he needs to put into ground leveling.
//
// You are given a vector <string> area. Each character in area denotes the height at the corresponding square meter of Manao's area. Using 1 unit of effort, Manao can change the height of any square meter on his area by 1 up or down. Return the minimum total effort he needs to put to obtain a leveled area.
//
//
// DEFINITION
// Class:HouseBuilding
// Method:getMinimum
// Parameters:vector <string>
// Returns:int
// Method signature:int getMinimum(vector <string> area)
//
//
// CONSTRAINTS
// -area will contain between 1 and 50 elements, inclusive.
// -Each element of area will be between 1 and 50 characters long, inclusive.
// -All elements of area will be of the same length.
// -Each element of area will contain digits ('0'-'9') only.
//
//
// EXAMPLES
//
// 0)
// {"10",
//  "31"}
//
// Returns: 2
//
// The given area is not leveled, because the minimum height is 0 and the maximum height is 3. Manao needs to reduce the height of lower left square by 2.
//
// 1)
// {"54454",
//  "61551"}
//
// Returns: 7
//
// In the optimal solution each square will have height either 4 or 5. To reach such a configuration, Manao should reduce the height of one square from 6 to 5, and increase the heights of two other squares from 1 to 4.
//
// 2)
// {"989"}
//
// Returns: 0
//
// The area is already leveled.
//
// 3)
// {"90"}
//
// Returns: 8
//
//
//
// 4)
// {"5781252",
//  "2471255",
//  "0000291",
//  "1212489"}
//
// Returns: 53
//
//
//
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
