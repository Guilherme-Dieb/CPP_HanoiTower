#include "header/ht_comands.hpp"

using namespace HanoiTower;

//DESTRUCTOR
commands::~commands()
{
    for(sCommand* c:_commands)
    {
        delete c;
    }
}

/// @brief 
/// @param origin 
/// @param destiny 
/// @return false if it fails to add the command 
bool commands::loadCommand(int origin, int destiny)
{
    sCommand* c = new sCommand;

    if(c == nullptr) 
    {
        debug::log("Failed to Add Command");
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
bool commands::isCommandIDValid(int commandID)
{
    if(commandID <= _totalCommands && _nextCommandID >= 0) { return true; }


    debug::log("Invalid Command ID");
    return false;
}

/// @brief 
/// @param _towers 
/// @param towerID 
/// @return true if towerID is valid 
bool commands::doesTowerExists(std::vector<tower*> towers, int towerID)
{
    if(towerID >= 0 && towerID < towers.size())
    {
        return true;
    }

    debug::log("Tower " + std::to_string(towerID) + " don't Exist!");
    return false;
}

/// @brief 
/// @param _towers 
/// @param command 
/// @return false if the command is invalid 
void commands::executeCommand(std::vector<tower*> towers, sCommand* command)
{
    int origin = command->origin;
    int destiny = command->destiny;

    if(!doesTowerExists(towers, origin) || !doesTowerExists(towers, destiny))
    {
        return;
    }

    tower* originTower = towers[origin];

    if(originTower->isTowerEmpty())
    {
        debug::log("Invalid Comand: Tower " + std::to_string(origin) + " is Empty!");
        return;
    }

    tower* destinyTower = towers[destiny];

    destinyTower->pushDisk(originTower->popDisk());
}

/// @brief 
/// @param _towers 
/// @return false if it fail's to execute the current command 
bool commands::executeCurrentCommand(std::vector<tower*> towers)
{
    if(!isCommandIDValid(_nextCommandID))
    {
        return false;
    }

    int toExecuteCommandID = _nextCommandID + 1;

    sCommand* currentCommand = _commands[_nextCommandID];

    executeCommand(towers, currentCommand);

    _nextCommandID++;

    return true;
}

void commands::executeAllCommand(std::vector<tower*> _towers)
{

}