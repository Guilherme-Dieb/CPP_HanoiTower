#include "header/ht_tower.hpp"

using namespace HanoiTower;

Disk* Tower::GetTopDisk(){ return _topDisk; }
Disk* Tower::GetBottomDisk(){ return _bottomDisk; }

//CONTRUCTOR
Tower::Tower()
{
    Initialize();
}

Tower::Tower(int size)
{
    if(size < 0)
    {
        Debug::Log("Tower Initialization Error! Invalid Number of Disks");
    }
    _topDisk = nullptr;
    _bottomDisk = nullptr;
    FillTower(size);
}

//DESTRUCTOR
Tower::~Tower()
{
    DestroyDisksFromTop(_topDisk);
    Debug::Log("tower destroyed");
}

//FUNCTIONS
void Tower::Initialize()
{
    _towerSize = 0;
    _topDisk = nullptr;
    _bottomDisk = nullptr;
}

void Tower::PushDisk(Disk * diskToAdd)
{
    if(diskToAdd == nullptr)
    {
        Debug::Log("Failed to Add the disk");
        return;
    }
    _towerSize++;

    if(_bottomDisk == nullptr)
    {
        _bottomDisk = diskToAdd;
        _topDisk = diskToAdd;
        return;
    }

    diskToAdd->SetBottom(_topDisk);
    _topDisk->SetTop(diskToAdd);
    _topDisk = diskToAdd;
}

Disk* Tower::PopDisk()
{
    if(IsTowerEmpty())
    {
        Debug::Log("Fail to process! The Tower is Empty");
        return nullptr;
    }

    Disk* diskToPop = _topDisk;

    _topDisk = diskToPop->GetBottom();

    diskToPop->SetBottom(nullptr);

    _towerSize--;

    if(IsTowerEmpty())
    {
        _topDisk = nullptr;
        _bottomDisk = nullptr;
        return diskToPop;
    }

    _topDisk->SetTop(nullptr);

    return diskToPop;
}

void Tower::PrintSize()
{
    Debug::Log(std::to_string(_towerSize));
}

void Tower::PrintStack(Disk* diskToPrint)
{
    if(diskToPrint == nullptr){ return; }

    Disk* current = diskToPrint;

    while(current != nullptr)
    {
        current->PrintDisk();
        current = current->GetTop();
    }
}

void Tower::PrintTower()
{
    std::cout << Config::TowerPrefix();
    PrintStack(_bottomDisk);
    std::cout << Config::TowerSufix();
}

void Tower::DestroyDisksFromTop(Disk* detsroyDisk)
{
    Disk* current = detsroyDisk;

    while(current!=nullptr)
    {
        HanoiTower::Disk* toDestroy = current;
        current = current->GetBottom();
        delete toDestroy;
    }
}

void Tower::FlushTower()
{
    DestroyDisksFromTop(_topDisk);

    Initialize();
}

void Tower::FillTower(int size)
{
    if(size <= 0) { return; }

    _towerSize = 0;

    for(;size > 0; size--)
    {
        PushDisk(new Disk(size));
    }
}

int Tower::GetSize()
{
    return _towerSize;
}

bool Tower::IsTowerEmpty()
{
    if(_towerSize == 0){ return true; }

    return false;
}