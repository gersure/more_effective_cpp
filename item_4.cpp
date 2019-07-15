/***********************************************************************
#   > File Name   : item_4.cpp
#   > Author      : ronaldo
#   > Description : 
#   > Create Time : 2019-07-14 16:59:29
***********************************************************************/

class EquipmentPiece {
 public:
  EquipmentPiece(int IDNumber) : id_(IDNumber) {

  }

  // 编译器不会合成默认构造函数
  
 private:
  int id_;
};

int main(int argc, char **argv) {
  //EquipmentPiece bestPieces[10];  // 没有默认构造函数，编译失败
  
  int id_0 = 0, id_1 = 1, id_2 = 2;
  /*
  EquipmentPiece ep_0(id_0); 
  EquipmentPiece ep_1(id_1);
  EquipmentPiece ep_2(id_2); */

  EquipmentPiece bestPieces[] = {
    //ep_0, ep_1, ep_2
    EquipmentPiece(id_0), 
    EquipmentPiece(id_1),
    EquipmentPiece(id_2)
  };

  return 0;
}
