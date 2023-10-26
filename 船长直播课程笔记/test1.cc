#include <iostream>
#include <utility>

using namespace std;

int add(int a, int b) { return a + b; };

int main() {
  printf("add(2+3)=%d\n", add(2, 3));
  return 0;
}