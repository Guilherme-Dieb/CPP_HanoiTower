#pragma once

#include <vector>
#include <iostream>

#include "ht_tower.hpp"
#include "ht_disk.hpp"
#include "debug.hpp"

namespace HanoiTower
{   
    class analyzer
    {
    public:
        analyzer(int dataAmount);
        ~analyzer();

        void analyze(std::vector<tower*> towers);
        void printData();

    private:
        int _dataAmount;
        int* data = nullptr;

        void analyzeDisks(disk*, int);
    };    
}