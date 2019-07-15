/***********************************************************************
#   > File Name   : item_6.cpp
#   > Author      : ronaldo
#   > Description : 
#   > Create Time : 2019-07-15 12:47:04
***********************************************************************/

#include <iostream>

class UPInt {
 friend std::ostream& operator<<(std::ostream& os, const UPInt &item);

 public:
  UPInt(int n) : n_(n) {

  }

  // 前置式
  UPInt& operator++() {
    (*this) += 1;
    return *this;
  }

  // 后置式
  const UPInt operator++(int) {
    UPInt old_value = *this;
    ++(*this);
    return old_value;
  }

  // 前置式
  UPInt& operator--() {
    (*this) -= 1;
    return *this;
  }

  // 后置式
  const UPInt operator--(int) {
    UPInt old_value = *this;
    --(*this);
    return old_value;
  }

  UPInt& operator+=(int v) {
    n_ += v;
    return *this;
  }

  UPInt& operator-=(int v) {
    n_ -= v;
    return *this;
  }

  const UPInt& operator=(const UPInt &rhs) {
    n_ = rhs.n_;
    return *this;
  }
 private:
  int n_;
};

std::ostream& operator<<(std::ostream& os, const UPInt &item) {
  os << item.n_;  
}

int main(int argc, char **argv) {
  UPInt upi(5);
  std::cout << upi++ << std::endl;  // 5
  std::cout << ++upi << std::endl;  // 7
  
  std::cout << --upi << std::endl;  // 6 
  std::cout << upi-- << std::endl;  // 6
  
  return 0;
}
