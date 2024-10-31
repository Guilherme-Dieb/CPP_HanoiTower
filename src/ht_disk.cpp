#include "header/ht_disk.h"

using namespace HanoiTower;

//GETTERS
int disk::getSize(){return _diskSize;}

disk* disk::getTop(){return _topDisk;}

disk* disk::getBottom(){return _bottomDisk;}

//SETTERS
void disk::setTop(disk* top)
{
    _topDisk = top;
}

void disk::setBottom(disk* bottom)
{
    _bottomDisk = bottom;
}

//CONSTRUCTOR
disk::disk(int size, disk* top, disk* bottom)
{
    if(size <= 0)
    {
        std::cout << "Disk Initialization Error! Size of Disks can't be negative" << std::endl;
    }
    _diskSize = size;
    setTop(top);
    setBottom(bottom);
}

disk::disk(int size)
{
    if(size <= 0)
    {
        std::cout << "Initialization Error! Size of Disks can't be negative" << std::endl;
    }
    _diskSize = size;
    setTop(nullptr);
    setBottom(nullptr);
}

//FUNCTIONS
void disk::printSize()
{
    std::cout << _diskSize << std::endl;
}

void disk::printDisk()
{
    std::cout << config::diskPrefix() << _diskSize << config::diskSufix();
}