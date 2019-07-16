/***********************************************************************
#   > File Name   : item_9.cpp
#   > Author      : ronaldo
#   > Description : 
#   > Create Time : 2019-07-15 21:48:05
***********************************************************************/

#include <iostream>
#include <memory>

class ALA {
 public:
  virtual void processAdoption() = 0;
};

class A : public ALA {
 public:
  virtual void processAdoption() {
    // 可能抛出异常    
  }
};

class B : public ALA {
 public:
  virtual void processAdoption() {
    // 可能抛出异常
  }
};

ALA* readALA(std::string &info) {
  return new A();
}

int main(int argc, char **argv) {
  std::string info;
  while (std::cin >> info) {
    std::auto_ptr<ALA> pa(readALA(info));
    pa->processAdoption();
  }

  return 0;
}
