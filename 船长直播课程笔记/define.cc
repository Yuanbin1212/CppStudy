#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define PI 3.1415926
#define S(a, b) a *b
#define RUN(func)                                                              \
  {                                                                            \
    printf("run %s\n", #func);                                                 \
    func;                                                                      \
  }

void test(int x) { printf("test function : x = %d\n", x); }

#define CAT(a, b) a##b
#define MAX(a, b)                                                              \
  ({                                                                           \
    int __a = (a), __b = (b);                                                  \
    (__a) > (__b) ? (__a) : (__b);                                             \
  })

#define TEST(func)                                                             \
  { printf("run %s = %d\n", #func, func); }

int main() {
  printf("PI= %lf\n", PI);
  printf("s(3, 4)= %d\n", S(3, 4));
  printf("s(3, 4 + 7)= %d\n", S(3, 4 + 7));

  printf("__DATE__ = %s\n", __DATE__);
  printf("__TIME__ = %s\n", __TIME__);
  printf("__FILE__ = %s\n", __FILE__);
  printf("__LINE__ = %d\n", __LINE__);
  printf("__func__ = %s\n", __func__);
  //   printf("__FUNC__ = %s\n", __FUNC__);
  printf("__PRETTY_FUNCTION__ = %s\n", __PRETTY_FUNCTION__);
  RUN(test(3)); //{ printf("run %s\n", "test(3)"); test(3); };

  int n10 = 123;
  CAT(n1, 0) = 999;
  printf("n10 = %d\n", n10);

  TEST(MAX(2, 3));
  TEST(5 + MAX(2, 3));
  TEST(MAX(2, MAX(3, 4)));
  TEST(MAX(2, 3 > 4 ? 3 : 4));
  int a = 7;
  TEST(MAX(a++, 6));
  printf("a = %d\n", a);
  return 0;
}
