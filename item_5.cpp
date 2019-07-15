/***********************************************************************
#   > File Name   : item_5.cpp
#   > Author      : ronaldo
#   > Description : 
#   > Create Time : 2019-07-15 11:02:10
***********************************************************************/

#include <assert.h>
#include <iostream>

class Rational {
 public:
  Rational(int n, int d) : n_(n), d_(d) {

  }

  // 类型转换运算符
  operator double() const {
    return static_cast<double>(n_) / d_;
  }

 private:
  int n_, d_;   
};

template<typename T>
class Array {
 public:
  explicit Array(int size) : size_(size), ptr_(new T[size_]) {  

  }

  ~Array() {
    delete [] ptr_;
  }

  T& operator[](size_t index) {
    assert(index < size_);
    return *(ptr_ + index);
    //return ptr_[index];
  }

  Array(const Array&) = delete;
  Array& operator=(const Array&) = delete;

 private:
  int size_;

  T* ptr_;
};

bool operator==(const Array<int> &lhs, const Array<int> &rhs) {
  
}

int main(int argc, char **argv) {
  Rational r1(3, 4);
  double d = 0.5 * r1;
  std::cout << d << std::endl;

  Rational r2(1, 2);
  // 虽然Rational没有重载<<符，但定义了类型转换运算符，也可执行成功，但通常不符合预期
  std::cout << r2 << std::endl;

  Array<int> a(10);
  Array<int> b(10);

  for (size_t idx = 0; idx < 10; ++idx) {
    if (a == b[idx]) {  // 如果没有explicit，发生隐式类型转换
      // ...
    } else {
      // ...
    }
  }

  return 0;
}
