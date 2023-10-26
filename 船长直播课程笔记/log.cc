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

#define INFO 0
#define DEBUG 1
#define ERROR 2
#define LOG_LEVEL DEBUG
#define LOG(log_level)                                                         \
  if (log_level >= LOG_LEVEL)                                                  \
  printf("[%s, %d]", __FILE__, __LINE__), printf

int main() {
  int a = 123;
  LOG(INFO)("a = %d\n", a);
  LOG(INFO)("info log level\n");
  LOG(DEBUG)("debug log level\n");
  LOG(ERROR)("error log level\n");
  printf("hello world\n");

  return 0;
}