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

void Analyzer::AnalyzeDisks(Disk* disk, int towerID)
{
    if(disk == nullptr) 
    {
        Debug::Log("Data colection of Tower " + std::to_string(towerID) + " complete!");
        return;
    }

    Disk * currentDisk = disk;

    do
    {
    data[currentDisk->GetSize()-1] = towerID;
    currentDisk = currentDisk->GetBottom();

    }while (currentDisk != nullptr);
    
}

void Analyzer::Analyze(std::vector<Tower*> towers)
{
    int numberOfTowers = towers.size();
    for(int i = 0; i < numberOfTowers; i++)
    {
        AnalyzeDisks(towers[i]->GetTopDisk(), i);
    }
}

void Analyzer::LoadCommands(Commands* commands, int origin, int aux, int destiny, int dataID)
{
    if(dataID < 0)
    {
        Debug::Log("Analyzes Finished!");
        return;
    }

    int nextDataID = dataID;

    int nextData = -1;
    //move top tower out of the way
    do
    {
        nextDataID--;
        nextData = data[nextDataID];
    } while (nextData == aux);

    if(nextData == origin)
    {
        LoadCommands(commands, origin, destiny, aux, nextDataID);
    } 
    else
    {
        LoadCommands(commands, destiny, origin, aux, nextDataID);
    }

    // move piece
    commands->LoadCommand(origin, destiny);

    //move tower to the top of the piece
    GenericLoadCommands(commands, aux, origin, destiny, dataID - 1);
}

void Analyzer::GenericLoadCommands(Commands* commands, int origin, int aux, int destiny, int dataID)
{
    if(dataID < 0)
    {
        Debug::Log("Analyzes Finished!");
        return;
    }

    int nextDataID = dataID - 1;

    //move top tower out of the way
    GenericLoadCommands(commands, origin, destiny, aux, nextDataID);

    //move piece
    commands->LoadCommand(origin, destiny);

    //move tower to the top of the piece
    GenericLoadCommands(commands, aux, origin, destiny, nextDataID);

}

void Analyzer::GenerateSolution(Commands* commands)
{
    int initialID = _dataAmount - 1;

    towerBaseID origin = ORIGINTOWER;
    towerBaseID aux = AUXTOWER;
    towerBaseID destiny = DESTINYTOWER;

    LoadCommands(commands, origin, aux, destiny, initialID);
}

void Analyzer::PrintData()
{
    Debug::Log("------------------");
    Debug::Log("Data:");
    for(int i = 0; i < _dataAmount; i++)
    {
        Debug::Log("Disk " + std::to_string(i+1) + " in Tower " + std::to_string(data[i]));
    }
    Debug::Log("------------------\n");
}