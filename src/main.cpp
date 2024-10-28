#include <iostream>
//#include "header/log.h"
#include "header/ht_disk.h"

int main(int, char**){
    HanoiTower::disk* testDisk = new HanoiTower::disk(0,nullptr,nullptr);

    testDisk->printSize();
}
