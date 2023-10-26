#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <mutex>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <thread>
#include <vector>
using namespace std;

#define MAX_N 5000000
int ans;
mutex mutex_x; //此处定义无实际性作用

void test() {
  cout << this_thread::get_id() << endl;
  for (size_t i = 0; i < 100000000; i++) {
  };
  printf("hello test\n");
  return;
}
void f(int x, int y) {
  cout << this_thread::get_id() << endl;
  printf("x = %d, y = %d!\n", x, y);
  return;
}

void add_n(int &n) {
  cout << this_thread::get_id() << endl;
  n += 1;
  return;
}

int is_prime(int x) {
  if (x <= 1)
    return 0;
  for (size_t i = 2; i * i <= x; i++) {
    if (x % i == 0)
      return 0;
  }
  return 1;
}

void count_prime(int b, int e) {
  for (size_t i = b; i <= e; i++) {
    // unique_lock<mutex> lock(mutex_x); //抢占锁，自动释放
    // ans += is_prime(i); //非原子化操作

    // 无锁化编程
    int ret = is_prime(i);
    __sync_fetch_and_add(&ans, ret);
  }
  return;
}

int main() {
  int n = 99;
  cout << this_thread::get_id() << endl;
  thread x(test);
  thread y(f, 2, 3);
  //   thread z(add_n, n);
  thread z(add_n, ref(n));

  printf("hello main\n");
  x.join();
  y.join();
  z.join();
  printf("n = %d!\n", n);

  int batch = MAX_N / 10;
  int ret[10];
  thread *threads[10];
  ans = 0;
  for (size_t i = 0, j = 1; i < 10; i++, j += batch) {
    threads[i] = new thread(count_prime, j, j + batch - 1);
  }

  for (size_t i = 0; i < 10; i++) {
    threads[i]->join();
  }
  cout << ans << endl;
  return 0;
}