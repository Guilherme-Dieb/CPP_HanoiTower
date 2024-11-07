#include "header/ht_game.hpp"

using namespace HanoiTower;

//GETTERS


//SETTERS


//CONSTRUCTOR
game::game(int numberOfDisks)
{
    if(numberOfDisks <= 0)
    {
        std::cout << "Game Initialization Error! Invalid Number of Disks" << std::endl;
    }

    _towerMaxSize = numberOfDisks;

    _towers.reserve(_numberOfTowers);

    _towers.push_back(new tower(numberOfDisks));
    _towers.push_back(new tower());
    _towers.push_back(new tower());
}

//DESTRUCTOR
game::~game()
{
    std::cout << "Game destroyed!" << std::endl;
    for(tower* t:_towers)
    {
        delete t;
    }
}


//FUNCTIONS
void game::printGame()
{
    int towerNumber = 0;
    for(tower* t:_towers)
    {
        std::cout << towerNumber << " -> "; 
        t->printTower();
        towerNumber++;
    }
    std::cout << std::endl;
}

void game::move(int origin, int destiny)
{
    _commands.loadAndExecuteCommand(_towers, origin, destiny);
}

void game::addMove(int origin, int destiny)
{
    _commands.loadCommand(origin, destiny);
}

void game::executeAllMoves()
{
    _commands.executeAllCommands(_towers);
}

void game::executeMove()
{
    _commands.executeCurrentCommand(_towers);
}

void game::printComands()
{
    _commands.printCommands();
}

void game::changeMove(int origin, int destiny)
{
    _commands.overwriteCommand( origin, destiny );
}

void game::undoMove()
{
    _commands.undoCommand(_towers);
}

void game::undoAllMoves()
{
    _commands.undoAllCommands(_towers);
}