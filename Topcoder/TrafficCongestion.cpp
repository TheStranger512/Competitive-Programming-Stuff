/* Solved
 * SRM 585 Div1 Easy
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

struct TrafficCongestion {
	int theMinCars(int treeHeight);
};

#define MOD 1000000007

static int f[1 << 20];

int TrafficCongestion::theMinCars(int H) {
  f[0] = f[1] = 1;
  int sum = 0;
  for (int i = 2; i <= H; i++) {
    sum += 2 * f[i - 2] % MOD;
    if (sum >= MOD) sum -= MOD;
    f[i] = sum + 1;
    if (f[i] >= MOD) f[i] -= MOD;
  }
  return f[H];
}


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << p0;
	cout << "]" << endl;
	TrafficCongestion *obj;
	int answer;
	obj = new TrafficCongestion();
	clock_t startTime = clock();
	answer = obj->theMinCars(p0);
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

	int p0;
	int p1;

	{
	// ----- test 0 -----
	p0 = 1;
	p1 = 1;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 2;
	p1 = 3;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = 3;
	p1 = 5;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = 585858;
	p1 = 548973404;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	p0 = 1000000;
	all_right = KawigiEdit_RunTest(4, p0, false, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 5 -----
	p0 = 0;
	p1 = 1;
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
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
// There are some cities and some roads connecting them together.
// The road network has the topology of a perfect binary tree (see below for a picture), in which the cities are nodes and the roads are edges.
//
// You are given the int treeHeight giving the height of the tree.
// (The height of a perfect binary tree is the number of edges on the path between the root node and any leaf node.)
// Thus, there are 2^(treeHeight+1)-1 cities and 2^(treeHeight+1)-2 roads in total.
//
// The picture below shows how the road network looks like when treeHeight = 2.
//
//
//
// We want to send some cars into the road network.
// Each car will be traveling from its starting city to its destination city without visiting the same city twice.
// (Note that the route of each car is uniquely determined by its starting and its destination city.)
// It is possible for the starting city to be equal to the destination city, in that case the car only visits that single city.
//
// Our goal is to send out the cars in such a way that each city will be visited by exactly one car.
// Let X be the smallest number of cars we need in order to do so.
// Compute and return the value X modulo 1,000,000,007.
//
// DEFINITION
// Class:TrafficCongestion
// Method:theMinCars
// Parameters:int
// Returns:int
// Method signature:int theMinCars(int treeHeight)
//
//
// CONSTRAINTS
// -treeHeight will be between 0 and 1,000,000, inclusive.
//
//
// EXAMPLES
//
// 0)
// 1
//
// Returns: 1
//
// In this case, one car can visit all the cities.
//
//
//
// 1)
// 2
//
// Returns: 3
//
// Here is one way to visit all cities exactly once by three cars:
//
//
//
//
// 2)
// 3
//
// Returns: 5
//
//
//
// 3)
// 585858
//
// Returns: 548973404
//
//
//
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
