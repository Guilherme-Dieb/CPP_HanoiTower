#include "header/ht_disk.hpp"

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
        debug::log("Disk Initialization Error! Size of Disks can't be negative");
    }
    _diskSize = size;
    setTop(top);
    setBottom(bottom);
}

disk::disk(int size)
{
    if(size <= 0)
    {
        debug::log("Initialization Error! Size of Disks can't be negative");
    }
    _diskSize = size;
    std::cout << "Disk Created: " << size << std::endl;
    setTop(nullptr);
    setBottom(nullptr);
}

//DESTRUCTOR
disk::~disk()
{
    debug::log("Disk " + std::to_string(_diskSize) + " Destroyed");
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