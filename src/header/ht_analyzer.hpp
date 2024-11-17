#pragma once

#include <vector>

#include "ht_tower.hpp"
#include "ht_disk.hpp"
#include "ht_commands.hpp"
#include "debug.hpp"

namespace HanoiTower
{   
    enum towerBaseID
    {
        ORIGINTOWER = 0,
        AUXTOWER = 1,
        DESTINYTOWER = 2
    };

    class Analyzer
    {
    public:
        Analyzer(int dataAmount);
        ~Analyzer();

        void Analyze(std::vector<Tower*> towers);
        void GenerateSolution(Commands* commands);

        void PrintData();

    private:
        int _dataAmount;
        
        int* data = nullptr;

        void AnalyzeDisks(Disk*, int);
        void LoadCommands(Commands* commands, int origin, int aux, int destiny, int dataID);
        void GenericLoadCommands(Commands* commands, int origin, int aux, int destiny, int dataID);
    };    
}