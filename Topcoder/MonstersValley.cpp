/*
 * Solved
 * SRM 565 Div1 Easy
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

class MonstersValley {
public:
	int minimumPrice(vector<llong> dread, vector <int> price);
};

llong dp[55][255];

int MonstersValley::minimumPrice(vector<llong> dread, vector <int> price) {
	memset(dp, 0, sizeof (dp));
	int len = dread.size(), most = 2 * len;
	dp[0][price[0]] = dread[0];
	for (int i = 1; i < len; i++) {
		for (int j = 0; j <= most; j++) {
			if (dp[i - 1][j] == 0) continue;
			if (dp[i - 1][j] >= dread[i])
				dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			dp[i][j + price[i]] = max(dp[i][j + price[i]], dp[i - 1][j] + dread[i]);
		}
	}
	for (int i = 0;;i++)
		if(dp[len - 1][i] > 0)
			return i;
	assert(false);
	return -1;
}



// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector<llong> p0, vector <int> p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}";
	cout << "]" << endl;
	MonstersValley *obj;
	int answer;
	obj = new MonstersValley();
	clock_t startTime = clock();
	answer = obj->minimumPrice(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
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
	bool all_right;
	all_right = true;
	
	vector<llong> p0;
	vector <int> p1;
	int p2;
	
	{
	// ----- test 0 -----
	llong t0[] = {8ll,5ll,10ll};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,1,2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 2;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	llong t0[] = {1ll,2ll,4ll,1000000000ll};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,1,1,2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 5;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	llong t0[] = {200ll,107ll,105ll,206ll,307ll,400ll};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,2,1,1,1,2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 2;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	llong t0[] = {5216ll,12512ll,613ll,1256ll,66ll,17202ll,30000ll,23512ll,2125ll,33333ll};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {2,2,1,1,1,1,2,1,2,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 5;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
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
// Manao is traversing a valley inhabited by monsters. During his journey, he will encounter several monsters one by one. The scariness of each monster is a positive integer. Some monsters may be scarier than others. The i-th (0-based index) monster Manao will meet has scariness equal to dread[i].
// 
// Manao is not going to fight the monsters. Instead, he will bribe some of them and make them join him. To bribe the i-th monster, Manao needs price[i] gold coins. The monsters are not too greedy, therefore each value in price will be either 1 or 2.
// 
// At the beginning, Manao travels alone. Each time he meets a monster, he first has the option to bribe it, and then the monster may decide to attack him. A monster will attack Manao if and only if he did not bribe it and its scariness is strictly greater than the total scariness of all monsters in Manao's party. In other words, whenever Manao encounters a monster that would attack him, he has to bribe it. If he encounters a monster that would not attack him, he may either bribe it, or simply walk past the monster.
// 
// 
// 
// Consider this example: Manao is traversing the valley inhabited by the Dragon, the Hydra and the Killer Rabbit. When he encounters the Dragon, he has no choice but to bribe him, spending 1 gold coin (in each test case, Manao has to bribe the first monster he meets, because when he travels alone, the total scariness of monsters in his party is zero). When they come by the Hydra, Manao can either pass or bribe her. In the end, he needs to get past the Killer Rabbit. If Manao bribed the Hydra, the total scariness of his party exceeds the Rabbit's, so they will pass. Otherwise, the Rabbit has to be bribed for two gold coins. Therefore, the optimal choice is to bribe the Hydra and then to walk past the Killer Rabbit. The total cost of getting through the valley this way is 2 gold coins.
// 
// You are given the vector<long long> dread and the vector <int> price. Compute the minimum price Manao will pay to safely pass the valley.
// 
// DEFINITION
// Class:MonstersValley
// Method:minimumPrice
// Parameters:vector<long long>, vector <int>
// Returns:int
// Method signature:int minimumPrice(vector<long long> dread, vector <int> price)
// 
// 
// CONSTRAINTS
// -dread will contain between 1 and 50 elements, inclusive.
// -Each element of dread will be between 1 and 1,000,000,000,000 (10^12), inclusive.
// -price will contain the same number of elements as dread.
// -Each element of price will be either 1 or 2.
// 
// 
// EXAMPLES
// 
// 0)
// {8, 5, 10}
// {1, 1, 2}
// 
// Returns: 2
// 
// The example from the problem statement.
// 
// 1)
// {1, 2, 4, 1000000000}
// {1, 1, 1, 2}
// 
// Returns: 5
// 
// Manao has to bribe all monsters in the valley.
// 
// 2)
// {200, 107, 105, 206, 307, 400}
// {1, 2, 1, 1, 1, 2}
// 
// Returns: 2
// 
// Manao can bribe monsters 0 and 3.
// 
// 3)
// {5216, 12512, 613, 1256, 66, 17202, 30000, 23512, 2125, 33333}
// {2, 2, 1, 1, 1, 1, 2, 1, 2, 1}
// 
// Returns: 5
// 
// Bribing monsters 0, 1 and 5 is sufficient to pass safely.
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
