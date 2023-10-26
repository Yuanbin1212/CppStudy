#include <iostream>

using namespace std;

void (*f)();
void test1() {
  printf("funtion test1\n");
  return;
};

void test2() {
  printf("funtion test2\n");
  return;
};

void test3() {
  printf("funtion test3\n");
  return;
};

int main() {
  void (*fp)();
  fp = test1;
  fp();

  fp = test2;
  fp();

  fp = test3;
  fp();

  void (*arry[3])() = {test1, test2, test3};
  for (size_t i = 0; i < 10; i++) {
    arry[rand() % 3]();
  }

  const int *p1;       // [p 是一个]  [指针，指向]  整形  常量
  int const *p2;       // [p 是一个]  [指针，指向]  常量  整形
  int *const p3 = 0x0; // [p 是一个]  常量  [指针，指向]  整形
                       // 申明一个常量的时候必须理解给他初始化
  float(*p[5])[10];    // [p 是一个][指针数组，指向] 浮点型数组

  return 0;
}
