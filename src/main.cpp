#include <iostream>
//#include "header/log.h"
#include "header/ht_disk.h"
#include "header/ht_tower.h"

int main(int, char**){
    HanoiTower::tower* myTower = new HanoiTower::tower(10);

    myTower->printTower();

    std::cout << "" <<std::endl;

    delete myTower;
}
