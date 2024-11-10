#include "header/ht_analyzer.hpp"

using namespace HanoiTower;

analyzer::analyzer(int dataAmount)
{
    _dataAmount = dataAmount;
    data = new int[_dataAmount];
    for(int i=0; i < dataAmount; i++)
    {
        data[i] = -1;
    }
}

analyzer::~analyzer()
{
    if( data != nullptr ){ delete []data; }
}

void analyzer::analyzeDisks(disk* _disk, int towerID)
{
    if(_disk == nullptr) 
    {
        debug::log("Data colection of Tower " + std::to_string(towerID) + " complete!");
        return;
    }

    data[_disk->getSize()] = towerID;
}

void analyzer::analyze(std::vector<tower*> towers)
{
    int numberOfTowers = towers.size();
    for(int i = 0; i < numberOfTowers; i++)
    {
        analyzeDisks(towers[i]->getTopDisk(), i);
    }
}

void analyzer::printData()
{
    for(int i = 0; i < _dataAmount;);
}