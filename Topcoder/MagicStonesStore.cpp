/*
 * 
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
template <class A> inline void pln(A a){cout << a << endl;}
template <class it> inline void plnarr(it begin, it end)
{cout<<'[';if(begin<end){while (true){cout<<(*begin);if(++begin==end)break;else cout<<',';}}cout<<']'<<endl;}
typedef long long llong;

class MagicStonesStore {
public:
	string ableToDivide(int n);
};

bool prime[2222];

string MagicStonesStore::ableToDivide(int n) {
	memset(prime, true, sizeof(prime));
	n <<= 1;
	prime[0] = prime[1] = false;
	for (int i = 2; i * i <= n; i++)
		if (prime[i])
			for (int j = i * i; j <= n; j +=i)
				prime[j]=false;
	for (int i =1;i<n;i++)
		if(prime[i]&&prime[n-i])
			return "YES";
	return "NO";
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << p0;
	cout << "]" << endl;
	MagicStonesStore *obj;
	string answer;
	obj = new MagicStonesStore();
	clock_t startTime = clock();
	answer = obj->ableToDivide(p0);
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
	bool all_right;
	all_right = true;
	
	int p0;
	string p1;
	
	{
	// ----- test 0 -----
	p0 = 1;
	p1 = "NO";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 2;
	p1 = "YES";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 3;
	p1 = "YES";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 5;
	p1 = "YES";
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
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
// Today is the Christmas Eve. People around the world celebrate this 
// holiday. The following story takes place in the land of reindeer, where Santa Claus resides.
// 
// 
// 
// The currency in the land of reindeer are magic stones. Santa's reindeer have 2n magic stones (i.e., an even number of them). They want to divide the stones into two piggy banks. Santa's reindeer are very fond of primes, therefore they want each piggy bank to contain a prime number of magic stones.
// 
// 
// 
// You are given an int n. If it is possible to divide 2n magic stones into two piggy banks, each containing a prime number of stones, return "YES", otherwise return "NO" (quotes for clarity).
// 
// DEFINITION
// Class:MagicStonesStore
// Method:ableToDivide
// Parameters:int
// Returns:string
// Method signature:string ableToDivide(int n)
// 
// 
// NOTES
// -A positive integer is prime if and only if it has exactly two positive integer divisors. The first few prime numbers are 2, 3, 5, 7, 11, ...
// -The number zero is not a prime number, hence you are not allowed to leave any piggy bank empty.
// 
// 
// CONSTRAINTS
// -n will be between 1 and 1,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 1
// 
// Returns: "NO"
// 
// As n=1, we are dividing 2 magic stones into two piggy banks. In this case is impossible to have a prime number of stones in each piggy bank.
// 
// 1)
// 2
// 
// Returns: "YES"
// 
// The only valid way of dividing the stones in this case is to put 2 magic stones into each of the piggy banks.
// 
// 2)
// 3
// 
// Returns: "YES"
// 
// Now the only way is to put 3 magic stones into each of the piggy banks.
// 
// 3)
// 5
// 
// Returns: "YES"
// 
// For 2n=10 stones we have two valid ways of dividing them: either as 5 + 5 or as 7 + 3.
// 
// END KAWIGIEDIT TESTING



//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!