/***********************************************************************
#   > File Name   : item_19.cpp
#   > Author      : ronaldo
#   > Description : 
#   > Create Time : 2019-07-17 14:39:38
***********************************************************************/

#include <string>

using namespace std;

size_t countChar(const string &str, char ch) {
  // ...
  return 0;
}

void uppercasify(string &str) {

}

int main(int argc, char **argv) {
  char buffer[32] = {0};
  char c;
  countChar(buffer, c);  // 产生临时对象，引用参数绑定在临时对象上

  char book[] = "More Effective C++";
  uppercasify(book);  // 不会产生临时对象，编译失败

  return 0;
}
