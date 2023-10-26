#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <functional> //bind
#include <iostream>
#include <map>
#include <mutex>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

void test() {
  printf("hello test\n");
  return;
}

void f(int x, int y) {
  printf("x = %d, y = %d!\n", x, y);
  return;
}

void add_n(int &n) {
  n += 1;
  return;
}

bool in_range(int a, int b, char c) { return c >= a and c <= b; }

typedef function<bool(char)> FUNC_T;
bool OR(FUNC_T f1, FUNC_T f2, char c) { return f1(c) || f2(c); }

int main() {
  auto f1 = bind(test);
  f1();
  f1();

  auto f2 = bind(f, 2, 3);
  f2();

  auto f3 = bind(f, 2, std::placeholders::_1);
  f3(100);

  auto f4 = bind(f, std::placeholders::_4, std::placeholders::_1);
  f4(1, 2, 3, 4); // x = 4, y = 1!

  int n = 100;
  auto f5 = bind(add_n, ref(n));
  f5();
  f5();
  f5();
  f5();
  cout << n << endl;

  char c;
  function<bool(char)> is_upper =
      bind(in_range, 'A', 'Z', std::placeholders::_1);
  function<bool(char)> is_lower =
      bind(in_range, 'a', 'z', std::placeholders::_1);
  auto is_alpha = bind(OR, is_upper, is_lower, std::placeholders::_1);
  auto is_digit = bind(in_range, '0', '9', std::placeholders::_1);
  cout << is_alpha('a') << endl;
  cout << is_upper('A') << endl;
  cout << is_lower('a') << endl;
  cout << is_digit('4') << endl;

  return 0;
}
