#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int f(int n) {
  if (n == 1)
    return 1;
  return n * f(n - 1);
}

//欧几里得算法 整数a,b的最大公约数表示为gcd(a, b)
// gcd(a, b) = gcd(b, a%b)
int gcd(int a, int b) {
  if (b == 0)
    return a;

  return gcd(b, a % b);
}

int n = 100;
int main() {

  //   cout << gcd(12, 6) << endl;
  //在主函数中实现从1打印到100
  int i = n;
  if (i == 1) {
    printf("%d\n", i);
    return 0;
  }
  n -= 1;
  main(); //向下扩展的过程
  printf("%d\n", i);
  return 0;
}
