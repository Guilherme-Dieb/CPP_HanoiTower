#include <iostream>

#include "header/ht_disk.hpp"
#include "header/ht_tower.hpp"
#include "header/ht_game.hpp"

int main(int, char**){
    Debug::Log("DEBUG VERSION\n");

    HanoiTower::Game myGame = HanoiTower::Game(3);
    myGame.PrintGame();

    myGame.AddMove(0, 2);
    myGame.ExecuteMove();

    myGame.AddMove(0, 2);
    myGame.ExecuteMove();

    myGame.PrintGame();

    myGame.AddMove(0, 1);

    myGame.AddMove(2, 1);

    myGame.AddMove(0, 2);

    myGame.AddMove(1, 0);

    myGame.AddMove(1, 2);

    myGame.AddMove(0, 2);

    myGame.ExecuteAllMoves();

    myGame.PrintComands();
    
    myGame.PrintGame();
    
    myGame.UndoMove();

    myGame.UndoAllMoves();

    myGame.PrintComands();

    myGame.PrintGame();
}
