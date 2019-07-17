/***********************************************************************
#   > File Name   : item_21.cpp
#   > Author      : ronaldo
#   > Description : 
#   > Create Time : 2019-07-17 15:28:13
***********************************************************************/

#include <iostream>

using namespace std;

class UPInt {
 public:
  UPInt(int n) : n_(n) {

  }
 
  int n() const {
    return n_;    
  }

 private:
  int n_;
};

ostream& operator<<(ostream &os, const UPInt &item) {
  os << item.n();
}

// 使用重载避免隐式类型转换

const UPInt operator+(const UPInt &lhs, const UPInt &rhs) {
  return UPInt(lhs.n() + rhs.n());
}

const UPInt operator+(const UPInt &lhs, int rhs) {
  return UPInt(lhs.n() + rhs);
}

const UPInt operator+(int lhs, const UPInt &rhs) {
  return UPInt(lhs + rhs.n());
}

int main(int argc, char **argv) {
  UPInt upi1(3);
  UPInt upi2(5);
  cout << upi1 + upi2 << endl;  // 8

  cout << upi1 + 2 << endl;  // 5
  cout << 10 + upi2 << endl;  // 15
  return 0;
}
