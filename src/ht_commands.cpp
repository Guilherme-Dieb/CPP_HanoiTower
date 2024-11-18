#include "header/ht_commands.hpp"

using namespace HanoiTower;

//DESTRUCTOR
Commands::~Commands()
{
    FlushCommands();
}

/// @brief 
/// @param origin 
/// @param destiny 
/// @return false if it fails to add the command 
bool Commands::LoadCommand(int origin, int destiny)
{
    sCommand* c = new sCommand;

    if(c == nullptr) 
    {
        Debug::Log("Failed to Add Command");
        return false;
    }

    c->origin = origin;
    c->destiny = destiny;
    _commands.push_back(c);
    _totalCommands++;

    return true;
}

/// @brief 
/// @param commandID 
/// @return true if Command with commandID corresponds to a command that can be executed;
bool Commands::IsCommandIDValid(int commandID)
{
    if(commandID <= _totalCommands && commandID >= 0) { return true; }

    return false;
}

/// @brief 
/// @param _towers 
/// @param towerID 
/// @return true if towerID is valid 
bool Commands::DoesTowerExists(std::vector<Tower*> towers, int towerID)
{
    if(towerID >= 0 && towerID < (int)towers.size())
    {
        return true;
    }

    Debug::Log("Tower " + std::to_string(towerID) + " don't Exist!");
    return false;
}

/// @brief 
/// @param _towers 
/// @param command 
/// @return false if the command is invalid 
void Commands::ExecuteCommand(std::vector<Tower*> towers, sCommand* command)
{
    int origin = command->origin;
    int destiny = command->destiny;

    if(!DoesTowerExists(towers, origin) || !DoesTowerExists(towers, destiny))
    {
        Debug::Log("Invalid Comand: Tower " + std::to_string(origin) + " or Tower " + std::to_string(destiny) + " don't Exixt!");
        return;
    }

    Tower* originTower = towers[origin];

    if(originTower->IsTowerEmpty())
    {
        Debug::Log("Invalid Comand: Tower " + std::to_string(origin) + " is Empty!");
        return;
    }

    Tower* destinyTower = towers[destiny];

    if(!CanCommandBeExecuted(originTower, destinyTower))
    {
        Debug::Log("Invalid Comand: Top Disk of Tower " + std::to_string(origin) + " is Bigger than Top Disk of Tower" + std::to_string(destiny) + "!");
        return;
    }

    destinyTower->PushDisk(originTower->PopDisk());
}

/// @brief 
/// @param _towers 
/// @return false if it fail's to execute the current command 
bool Commands::ExecuteCurrentCommand(std::vector<Tower*> towers)
{
    if(!IsCommandIDValid(_nextCommandID))
    {
        return false;
    }

    sCommand* currentCommand = _commands[_nextCommandID];

    ExecuteCommand(towers, currentCommand);

    _nextCommandID++;

    return true;
}

bool Commands::PrintCommand(int commandID)
{
    if(!IsCommandIDValid(commandID))
    {
        return false;
    }

    sCommand* c = _commands[commandID];

    Debug::Print("Command " + std::to_string(commandID) + ": "+ std::to_string(c->origin) + Config::TowerIDtoPrintConnector() + std::to_string(c->destiny));

    return true;
}

/// @brief 
/// @param _towers 
/// @return true if is able to execute the code 
bool Commands::ExecuteAndPrintAllCommands(std::vector<Tower*> towers)
{
    do
    {
        Debug::Log("------------------");
        PrintCommand(_nextCommandID - 1);
        Debug::Log("\n------------------");

        int towerNumber = 0;
        for(Tower* t:towers)
        {
            Debug::Print(std::to_string(towerNumber) + Config::TowerIDtoPrintConnector());
            t->PrintTower();
            towerNumber++;
        }
    }
    while (ExecuteCurrentCommand(towers));

    return true;
}

/// @brief 
/// @param _towers 
/// @return true if is able to execute the code 
bool Commands::ExecuteAllCommands(std::vector<Tower*> towers)
{
    while (ExecuteCurrentCommand(towers));

    return true;
}

/// @brief 
/// @param _towers 
/// @param origin 
/// @param destiny 
/// @return false if it can't add or execute the command 
bool Commands::LoadAndExecuteCommand(std::vector<Tower*> towers, int origin, int destiny)
{
    if(!LoadCommand(origin, destiny))
    {
        return false;
    }

    if(!ExecuteCurrentCommand(towers))
    {
        return false;
    }
    
    return true;
}

/// @brief 
/// @param towers 
/// @return false if it fails to undo
bool Commands::UndoCommand(std::vector<Tower*> towers)
{
    if(_nextCommandID == 0)
    {
        Debug::Log("No Command to Undo!");
        return false;
    }

    sCommand* uCommand = new sCommand;

    if(uCommand == nullptr)
    {
        Debug::Log("Failed to Create Undo Comand!");
        return false;
    }

    _nextCommandID--;

    sCommand* currentComand = _commands[_nextCommandID];

    uCommand->destiny = currentComand->origin;
    uCommand->origin = currentComand->destiny;

    ExecuteCommand(towers, uCommand);

    return true;
}

void Commands::UndoAllCommands(std::vector<Tower*> towers)
{
    while (UndoCommand(towers));
}

void Commands::OverwriteCommand(int origin, int destiny)
{

    for(; _totalCommands >= _nextCommandID; _totalCommands--)
    {
        sCommand* c = _commands[_totalCommands];
        _commands.pop_back();
        delete c;
    }

    LoadCommand(origin, destiny);
}

void Commands::PrintCommands()
{
    Debug::Log("COMMANDS IN STACK - BEGIN");

    int i = 0;
    while (PrintCommand(i))
    {
        std::string aux = "";
        if(i == _nextCommandID){ aux = " *"; }

        Debug::Log(aux);
        i++;
    }

    Debug::Log("COMMANDS IN STACK - END");
}

void Commands::FlushCommands()
{
    for(sCommand* c:_commands)
    {
        delete c;
    }

    _commands.clear();

    _nextCommandID = 0;
    _totalCommands = -1;
}

bool Commands::CanCommandBeExecuted(Tower* originTower, Tower* destinyTower)
{
    if(destinyTower->GetSize() == 0) { return true; }

    return originTower->GetTopDisk()->GetSize() < destinyTower->GetTopDisk()->GetSize();
}