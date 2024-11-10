#include "header/ht_disk.hpp"

using namespace HanoiTower;

//GETTERS
int Disk::GetSize(){return _diskSize;}

Disk* Disk::GetTop(){return _topDisk;}

Disk* Disk::GetBottom(){return _bottomDisk;}

//SETTERS
void Disk::SetTop(Disk* top)
{
    _topDisk = top;
}

void Disk::SetBottom(Disk* bottom)
{
    _bottomDisk = bottom;
}

//CONSTRUCTOR
Disk::Disk(int size, Disk* top, Disk* bottom)
{
    if(size <= 0)
    {
        Debug::Log("Disk Initialization Error! Size of Disks can't be negative");
    }
    _diskSize = size;
    SetTop(top);
    SetBottom(bottom);
}

Disk::Disk(int size)
{
    if(size <= 0)
    {
        Debug::Log("Initialization Error! Size of Disks can't be negative");
    }
    _diskSize = size;
    Debug::Log("Disk Created: ");
    SetTop(nullptr);
    SetBottom(nullptr);
}

//DESTRUCTOR
Disk::~Disk()
{
    Debug::Log("Disk " + std::to_string(_diskSize) + " Destroyed");
}

//FUNCTIONS
void Disk::PrintSize()
{
    Debug::Log(std::to_string(_diskSize));
}

void Disk::PrintDisk()
{
    std::cout << Config::DiskPrefix() << _diskSize << Config::DiskSufix();
}