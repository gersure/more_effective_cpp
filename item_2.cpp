/***********************************************************************
#   > File Name   : item_2.cpp
#   > Author      : ronaldo
#   > Description : 
#   > Create Time : 2019-06-30 11:31:31
***********************************************************************/

#include <iostream>

using namespace std;

class Widget {
 private:
  int m_;
};

class SpecialWidget : public Widget {
 private:
  int n_;
};

void update(SpecialWidget *psw) {
    
}

int main(int argc, char **argv) {
  /*  
  int a = 1;
  int &r = a;

  cout << &r << endl;
  cout << &a << endl; */

  SpecialWidget sw;
  const SpecialWidget &csw = sw;

  //update(&csw);  // 编译失败
  update(const_cast<SpecialWidget*>(&csw));
  update((SpecialWidget*)&csw);

  Widget *pw = new SpecialWidget;
  //update(pw);  // 编译失败
  update(dynamic_cast<SpecialWidget*>(pw));
  delete pw;

  return 0;  
}
