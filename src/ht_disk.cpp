#include "header/ht_disk.h"

#include <iostream>

using namespace HanoiTower;

//GETTERS
int disk::getSize(){return diskSize;}

disk* disk::getTop(){return topDisk;}

disk* disk::getBottom(){return bottomDisk;}

//SETTERS
void disk::setTop(disk* top)
{
    topDisk = top;
}

void disk::setBottom(disk* bottom)
{
    bottomDisk = bottom;
}

//CONSTRUCTOR
disk::disk(int size, disk* top, disk* bottom)
{
    diskSize = size;
    setTop(top);
    setBottom(bottom);
}

disk::disk(int size)
{
    diskSize = size;
    setTop(nullptr);
    setBottom(nullptr);
}

//FUNCTIONS
void disk::printSize()
{
    std::cout << diskSize << std::endl;
}

void disk::printDisk()
{
    std::cout << diskSize << " ";
}