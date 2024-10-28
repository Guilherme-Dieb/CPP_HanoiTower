#include <iostream>

#include "header/ht_tower.h"
#include "header/ht_disk.h"

using namespace HanoiTower;

disk* tower::getTopDisk(){ return topDisk; }
disk* tower::getBottomDisk(){ return bottomDisk; }

//CONTRUCTOR
tower::tower()
{
    towerSize = 0;
    topDisk = nullptr;
    bottomDisk = nullptr;
}

tower::tower(int size)
{
    towerSize = 0;
    
    for(;size > 0; size--)
    {
        addDisk(new disk(size));
    }
}

//DESTRUCTOR
tower::~tower()
{
    destroyDisks(topDisk);
}

//FUNCTIONS
void tower::addDisk(disk * diskToAdd)
{
    if(diskToAdd == nullptr)
    {
        std::cout << "Failed to create the disk" << std::endl;
        return;
    }
    towerSize++;

    if(bottomDisk == nullptr)
    {
        bottomDisk = diskToAdd;
        topDisk = diskToAdd;
        return;
    }

    diskToAdd->setBottom(topDisk);
    topDisk->setTop(diskToAdd);
    topDisk = diskToAdd;
}

disk* tower::popDisk()
{
    if(towerSize == 0)
    {
        std::cout << "Fail to process! The Tower is Empty" << std::endl;
        return nullptr;
    }

    towerSize--;

    disk* diskToPop = topDisk;

    topDisk = diskToPop->getBottom();

    if(towerSize == 0)
    {
        bottomDisk = nullptr;
    }

    return diskToPop;
}

void tower::printSize()
{
    std::cout << towerSize << std::endl;
}

void tower::printStack(disk* diskToPrint)
{
    if(diskToPrint == nullptr){ return; }

    printStack(diskToPrint->getBottom());

    diskToPrint->printDisk();
}

void tower::printTower()
{
    printStack(topDisk);
}

void tower::destroyDisks(disk* disk)
{
    if(disk == nullptr){ return; }

    destroyDisks(disk->getBottom());

    delete disk;
}
