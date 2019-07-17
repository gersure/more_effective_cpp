/***********************************************************************
#   > File Name   : item_22.cpp
#   > Author      : ronaldo
#   > Description : 
#   > Create Time : 2019-07-17 16:13:47
***********************************************************************/

#include <iostream>

using namespace std;

class Rational {
 friend ostream& operator<<(ostream &os, const Rational &item);

 public:
  Rational(int n, int d) : n_(n), d_(d) {

  }

  Rational& operator+=(const Rational &rhs) {
    n_ += rhs.n_;
    d_ += rhs.d_;
    return *this;
  }

 private:
  int n_, d_;
};

const Rational operator+(const Rational &lhs, const Rational &rhs) {
  // 以操作符复合形式实现独身形式
  // 返回值优化
  return (Rational)lhs += rhs;
}

ostream& operator<<(ostream &os, const Rational &item) {
  os << item.n_ << "/" << item.d_;
}

int main(int argc, char **argv) {
  Rational a(3, 5);
  Rational b(2, 7);
  cout << a + b << endl;

  return 0;
}
