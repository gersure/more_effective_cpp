/***********************************************************************
#   > File Name   : item_10.cpp
#   > Author      : ronaldo
#   > Description : 
#   > Create Time : 2019-07-16 13:43:00
***********************************************************************/

#include <iostream>
#include <list>
#include <memory>
#include <string>

using namespace std;

class Image {
 public:
  Image(const string &imageFilePath) {
    // 可能抛出异常  
  }
};

class Audio {
 public:
  Audio(const string &audioFilePath) {
    // 可能抛出异常
  }
};

class PhoneNumber {
    
};

class BookEntry {
 public:
  // 在构造函数内阻止资源泄漏
  BookEntry(const string &name, const string &address, 
          const string &imageFilePath, const string &audioFilePath)
      : name_(name), 
      address_(address), 
      image_(imageFilePath != "" ? new Image(imageFilePath) : 0), 
      audio_(audioFilePath != "" ? new Audio(audioFilePath) : 0) {
    // new Image时如果抛出内存不够的异常或者Image构造函数产生的异常，不会造成内存泄漏
    // new Audio时如果抛出异常，需要释放Image的内存
    // 异常会继续沿调用链向上抛出
  }

  // 让编译器自动合成析构函数

 private:
  string name_;
  string address_;
  list<PhoneNumber> phones_;
  auto_ptr<Image> image_;
  auto_ptr<Audio> audio_;
};

void testBookEntryOnStack() {
  BookEntry b("name", "address", "imageFilePath", "audioFilePath");
  // 如果BookEntry构造函数抛出由Audio产生的异常，则异常继续向上抛出
  // b的析构函数被调用，从而释放Image的内存
}

void testBookEntryOnHeap() {
  BookEntry *pb = nullptr;
  try {
    pb = new BookEntry("name", "address", "imageFilePath", "audioFilePath");

    // ...

  } catch (...) {
    delete pb;  // 调用析构函数去释放Image的内存
    throw;  // 异常继续向上抛出
  }
  delete pb;
}

int main(int argc, char **argv) {
  try {
    testBookEntryOnStack();
    testBookEntryOnHeap();
  } catch(...) {
    // 处理异常
  }

  return 0;
}
