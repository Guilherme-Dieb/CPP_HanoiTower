#include <iostream>

#include "header/ht_disk.hpp"
#include "header/ht_tower.hpp"
#include "header/ht_game.hpp"

int main(int, char**){
    debug::log("DEBUG VERSION\n");

    HanoiTower::game myGame = HanoiTower::game(3);
    myGame.printGame();

    myGame.move(0, 2);

    myGame.printGame();

    myGame.move(0, 1);

    myGame.printGame();

    myGame.move(2, 1);

    myGame.printGame();

    myGame.move(0, 2);

    myGame.printGame();

    myGame.move(1, 0);

    myGame.printGame();

    myGame.move(1, 2);

    myGame.printGame();

    myGame.move(0, 2);

    myGame.printGame();
}
