/***********************************************************************
#   > File Name   : item_3.cpp
#   > Author      : ronaldo
#   > Description : 
#   > Create Time : 2019-07-14 15:36:48
***********************************************************************/

#include <iostream>

class BST {
 friend std::ostream& operator<<(std::ostream &os, const BST &item);

 public:
 
 // 编译器合成默认构造函数
 
 private:
  int n_ = 1;
};

class BalanceBST : public BST {
 public:
 private:
  int m_ = 1;
};

std::ostream& operator<<(std::ostream &os, const BST &item) {
  std::cout << item.n_;
}

void printBSTArray(std::ostream &os, const BST array[], size_t numElements) {
  for (size_t i = 0; i < numElements; ++i) {
    os << array[i];
  }
}

void deleteArray(BST array[]) {
  delete [] array;
}

int main(int argc, char **argv) {
  BST BSTArray[10];
  BalanceBST bBSTArray[10];

  printBSTArray(std::cout, BSTArray, 10);
  printBSTArray(std::cout, bBSTArray, 10);  // error!!

  BalanceBST *balTreeArray = new BalanceBST[50];
  deleteArray(balTreeArray);  // error!!

  return 0;
}
