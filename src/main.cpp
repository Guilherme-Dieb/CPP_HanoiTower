#include <iostream>

#include "header/ht_disk.hpp"
#include "header/ht_tower.hpp"
#include "header/ht_game.hpp"

int main(int, char**){
    debug::log("DEBUG VERSION\n");

    HanoiTower::game myGame = HanoiTower::game(3);
    myGame.printGame();

    myGame.addMove(0, 2);

    myGame.printGame();

    myGame.addMove(0, 1);

    myGame.addMove(2, 1);

    myGame.addMove(0, 2);

    myGame.addMove(1, 0);

    myGame.addMove(1, 2);

    myGame.addMove(0, 2);

    myGame.executeAllMoves();

    myGame.printComands();
    
    myGame.printGame();
    
    myGame.undoMove();

    myGame.undoAllMoves();

    myGame.printComands();

    //myGame.executeAllMoves();

    myGame.printGame();
}
