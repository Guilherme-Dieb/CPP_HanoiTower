#include "header/ht_analyzer.hpp"

using namespace HanoiTower;

Analyzer::Analyzer(int dataAmount)
{
    _dataAmount = dataAmount;
    data = new int[_dataAmount];
    for(int i=0; i < dataAmount; i++)
    {
        data[i] = -1;
    }
}

Analyzer::~Analyzer()
{
    if( data != nullptr ){ delete []data; }
}

void Analyzer::AnalyzeDisks(Disk* _disk, int towerID)
{
    if(_disk == nullptr) 
    {
        Debug::Log("Data colection of Tower " + std::to_string(towerID) + " complete!");
        return;
    }

    data[_disk->GetSize()] = towerID;
}

void Analyzer::Analyze(std::vector<Tower*> towers)
{
    int numberOfTowers = towers.size();
    for(int i = 0; i < numberOfTowers; i++)
    {
        AnalyzeDisks(towers[i]->GetTopDisk(), i);
    }
}

void Analyzer::PrintData()
{
    for(int i = 0; i < _dataAmount;);
}