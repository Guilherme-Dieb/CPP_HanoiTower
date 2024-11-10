#pragma once

#include <vector>

#include "ht_tower.hpp"
#include "ht_disk.hpp"
#include "debug.hpp"

namespace HanoiTower
{   
    class Analyzer
    {
    public:
        Analyzer(int dataAmount);
        ~Analyzer();

        void Analyze(std::vector<Tower*> towers);
        void PrintData();

    private:
        int _dataAmount;
        int* data = nullptr;

        void AnalyzeDisks(Disk*, int);
    };    
}