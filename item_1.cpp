/***********************************************************************
#   > File Name   : item_1.cpp
#   > Author      : ronaldo
#   > Description : 
#   > Create Time : 2019-06-28 12:32:11
***********************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
  string s1("hello");
  string s2("world");

  string &rs = s1;
  string *ps = &s1;

  rs = s2;  // 对s1重新赋值
  ps = &s2;

  cout << s1 << endl;
  cout << s2 << endl;

  vector<int> v(10);
  v[5] = 20;  // operator[] 返回的是引用

  return 0;
}
