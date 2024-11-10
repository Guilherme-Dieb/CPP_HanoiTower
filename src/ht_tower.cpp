#include "header/ht_tower.hpp"

using namespace HanoiTower;

disk* tower::getTopDisk(){ return _topDisk; }
disk* tower::getBottomDisk(){ return _bottomDisk; }

//CONTRUCTOR
tower::tower()
{
    _towerSize = 0;
    _topDisk = nullptr;
    _bottomDisk = nullptr;
}

tower::tower(int size)
{
    if(size < 0)
    {
        std::cout << "Tower Initialization Error! Invalid Number of Disks" << std::endl;
    }
    _topDisk = nullptr;
    _bottomDisk = nullptr;
    fillTower(size);
}

//DESTRUCTOR
tower::~tower()
{
    destroyDisks(_topDisk);
    std::cout<< "tower destroyed" << std::endl;
}

//FUNCTIONS
void tower::pushDisk(disk * diskToAdd)
{
    if(diskToAdd == nullptr)
    {
        std::cout << "Failed to Add the disk" << std::endl;
        return;
    }
    _towerSize++;

    if(_bottomDisk == nullptr)
    {
        _bottomDisk = diskToAdd;
        _topDisk = diskToAdd;
        return;
    }

    diskToAdd->setBottom(_topDisk);
    _topDisk->setTop(diskToAdd);
    _topDisk = diskToAdd;
}

disk* tower::popDisk()
{
    if(isTowerEmpty())
    {
        std::cout << "Fail to process! The Tower is Empty" << std::endl;
        return nullptr;
    }

    disk* diskToPop = _topDisk;

    _topDisk = diskToPop->getBottom();

    diskToPop->setBottom(nullptr);

    _towerSize--;

    if(isTowerEmpty())
    {
        _topDisk = nullptr;
        _bottomDisk = nullptr;
        return diskToPop;
    }

    _topDisk->setTop(nullptr);

    return diskToPop;
}

void tower::printSize()
{
    std::cout << _towerSize << std::endl;
}

void tower::printStack(disk* diskToPrint)
{
    if(diskToPrint == nullptr){ return; }

    disk* current = diskToPrint;

    while(current != nullptr)
    {
        current->printDisk();
        current = current->getTop();
    }
}

void tower::printTower()
{
    std::cout << config::towerPrefix();
    printStack(_bottomDisk);
    std::cout << config::towerSufix();
}

void tower::destroyDisks(disk* detsroyDisk)
{    
    if(detsroyDisk == nullptr){ return; }

    disk* current = detsroyDisk;

    while(current!=nullptr)
    {
        HanoiTower::disk* toDestroy = current;
        current = current->getBottom();
        delete toDestroy;
    }
}

void tower::fillTower(int size)
{
    if(size <= 0) { return; }

    _towerSize = 0;

    //size--;

    for(;size > 0; size--)
    {
        pushDisk(new disk(size));
    }
}

int tower::getSize()
{
    return _towerSize;
}

bool tower::isTowerEmpty()
{
    if(_towerSize == 0){ return true; }

    return false;
}