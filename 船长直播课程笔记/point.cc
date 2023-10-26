#include <iostream>
#include <utility>

using namespace std;

int main() {
  int a;
  int *p = &a;
  printf("& a =%p\n", &a);
  printf("p + 0=%p\n", p);
  printf("p + 1=%p\n", p + 1);
  printf("p + 2=%p\n", p + 2);
  printf("p + 3=%p\n", p + 3);
  //-------
  int *p1 = 0x0;      // int
  double *p2 = 0x0;   // double
  int(*p3)[10] = 0x0; // int [10]
  printf("p1+1=%p\n", p1 + 1);
  printf("p2+1=%p\n", p2 + 1);
  printf("p3+1=%p\n", p3 + 1);

  //-------
  int arr[5][10];
  p3 = arr;
  printf("arr+1=%p\n", arr + 1);
  printf("p3+1=%p\n", p3 + 1);

  //-------
  int(*p4[5])[10]; //数组指针数组   int([5])[10]

  int arr1[3][4][5];
  int(*p5)[4][5]; // int[4][5]
  p5 = arr1;
  printf("arr1+1=%p\n", arr1 + 1);
  printf("p5+1=%p\n", p5 + 1);

  long long num = 0x0000000100000002LL;
  int *p6 = (int *)&num;
  printf("p6+0=%d\n", *p6);
  p6 = p6 + 1;
  printf("p6+1=%d\n", *p6);

  int array[] = {0, 1, 2, 3, 4, 5, 6};
  int *point = array;
  for (int i = 0; i < 3; i++) {
    printf("%d\n", (i + 5)[&point[1] - 2]);

    //解析 (i + 5)[&point[1] - 2]
    //(i + 5)[point + 1 - 2]
    //(i + 5)[point - 1]  利用  arr[index] <==> *(arr + index)
    //*(i + 5 + point - 1)
    //*(point + i + 4)
  }

  return 0;
}