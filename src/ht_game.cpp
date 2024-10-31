#include "header/ht_game.h"

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

    _towers.reserve(3);

    _towers.push_back(new tower(numberOfDisks));
    
    _towers.push_back(new tower());

    _towers.push_back(new tower());
}

//DESTRUCTOR
game::~game()
{
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

void HanoiTower::game::move(int origin, int destiny)
{
    if(origin < 0 || destiny < 0 || origin > _towers.size() - 1 || destiny > _towers.size() - 1 || origin == destiny)
    {
        std::cout << "Invalid Move!" << std::endl;
        return;
    }

    tower* originTower = _towers[origin];

    if(originTower->getSize() <= 0)
    {
        std::cout << "Invalid Move! Origin Tower is Empty" << std::endl;
        return;
    }

    tower* destinyTower = _towers[destiny];

    destinyTower->pushDisk(originTower->popDisk());

}