/***********************************************************************
#   > File Name   : item_20.cpp
#   > Author      : ronaldo
#   > Description : 
#   > Create Time : 2019-07-17 14:50:35
***********************************************************************/

#include <iostream>

using namespace std;

class Rational {
 public:
  Rational(int n, int d = 1) : n_(n), d_(d) {

  }

  int n() const {
    return n_;
  }

  int d() const {
    return d_;
  }

 private:
  int n_, d_;
};

// 编译器执行返回值优化
const Rational operator*(const Rational &lhs, const Rational &rhs) {
  return Rational(lhs.n() * rhs.n(), lhs.d() * rhs.d());
}

ostream& operator<<(ostream &os, const Rational &item) {
  os << item.n() << "/" << item.d();
}

int main(int argc, char **argv) {
  Rational a(2, 5);
  Rational b(3, 2);

  cout << a*b << endl;

  return 0;  
}
