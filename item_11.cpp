/***********************************************************************
#   > File Name   : item_11.cpp
#   > Author      : ronaldo
#   > Description : 
#   > Create Time : 2019-07-16 16:12:07
***********************************************************************/

class Session {
 public:
  Session() {

  }

  ~Session() {
    try {
      logDestruction(this);
    } catch (...) {
      // 禁止异常流出析构函数，防止析构函数执行不完全
    }
  }

 private:
  static void logCreation(Session *obj) {

  }

  static void logDestruction(Session *obj) {
    // 可能抛出异常
  }
};

int main(int argc, char **argv) {
  

  return 0;
}
