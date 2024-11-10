#include "header/ht_game.hpp"

using namespace HanoiTower;

//GETTERS


//SETTERS


//CONSTRUCTOR
Game::Game(int numberOfDisks)
{
    if(numberOfDisks <= 0)
    {
        Debug::Log("Game Initialization Error! Invalid Number of Disks");
    }

    _towerMaxSize = numberOfDisks;

    _towers.reserve(_numberOfTowers);

    _towers.push_back(new Tower(numberOfDisks));
    _towers.push_back(new Tower());
    _towers.push_back(new Tower());
}

//DESTRUCTOR
Game::~Game()
{
    Debug::Log("Game destroyed!");
    for(Tower* t:_towers)
    {
        delete t;
    }
}


//FUNCTIONS
void Game::PrintGame()
{
    int towerNumber = 0;
    for(Tower* t:_towers)
    {
        std::cout << towerNumber << " -> "; 
        t->PrintTower();
        towerNumber++;
    }
    std::cout << std::endl;
}

void Game::Move(int origin, int destiny)
{
    _commands.LoadAndExecuteCommand(_towers, origin, destiny);
}

void Game::AddMove(int origin, int destiny)
{
    _commands.LoadCommand(origin, destiny);
}

void Game::ExecuteAllMoves()
{
    _commands.ExecuteAllCommands(_towers);
}

void Game::ExecuteMove()
{
    _commands.ExecuteCurrentCommand(_towers);
}

void Game::PrintComands()
{
    _commands.PrintCommands();
}

void Game::ChangeMove(int origin, int destiny)
{
    _commands.OverwriteCommand( origin, destiny );
}

void Game::UndoMove()
{
    _commands.UndoCommand(_towers);
}

void Game::UndoAllMoves()
{
    _commands.UndoAllCommands(_towers);
}