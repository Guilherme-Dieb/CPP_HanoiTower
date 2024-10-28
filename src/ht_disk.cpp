#pragma once

#include "header/ht_disk.h"

#include <iostream>

using namespace HanoiTower;

//GETTERS
int disk::getSize(){return diskSize;}

disk* disk::getNext(){return nextDisk;}

disk* disk::getPrevious(){return previousDisk;}

//SETTERS
void disk::setNext(disk* next)
{
    nextDisk = next;
}

void disk::setPrevious(disk* previous)
{
    previousDisk = previous;
}

//CONSTRUCTOR
disk::disk(int size, disk* next, disk* previous)
{
    diskSize = size;
    setNext(next);
    setPrevious(previous);
}

//FUNCTIONS
void disk::printSize()
{
    std::cout << diskSize << std::endl;
}