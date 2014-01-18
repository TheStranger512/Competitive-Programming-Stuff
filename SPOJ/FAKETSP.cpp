/* Solved
 * 4993. Traveling Salesman
 * File:   FAKETSP.cpp
 * Author: Andy Y.F. Huang
 * Created on August 3, 2012, 10:57 PM
 */

#include <cstdio>
#include <cmath>
#include <cstring>
#include <sstream>


#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace FAKETSP {
char str[1010];
stringstream ss;

inline double dist(double x1, double y1, double x2, double y2) {
  double a = x1 - x2, b = y1 - y2;
  return sqrt(a * a + b * b);
}

double todouble(int start, int end) {
  ss.clear();
  for (int i = start; i < end; i++)
    ss << str[i];
  double ans;
  ss >> ans;
  return ans;
}

void solve(int test_num) {
  scanf("%[^\r\n]\r\n", str);
  int a = strrchr(str, '(') - str, b = strrchr(str, ',') - str, c = strrchr(str, ')') - str;
  double x = todouble(a + 1, b), y = todouble(b + 1, c), total = 0;
  while (scanf("%[^\r\n]\r\n", str) != EOF) {
    a = strrchr(str, '(') - str, b = strrchr(str, ',') - str, c = strrchr(str, ')') - str;
    double nx = todouble(a + 1, b), ny = todouble(b + 1, c);
    total += dist(x, y, nx, ny);
    x = nx, y = ny;
    printf("The salesman has traveled a total of %.3lf kilometers.\n", total);
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve(1);
}
}

int main() {
  FAKETSP::solve();
  return 0;
}

