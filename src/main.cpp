#include <iostream>

#include "header/ht_disk.h"
#include "header/ht_tower.h"
#include "header/ht_game.h"

int main(int, char**){
    HanoiTower::game* myGame = new HanoiTower::game(3);
    myGame->printGame();

    myGame->move(0, 2);

    myGame->printGame();

    myGame->move(0, 1);

    myGame->printGame();

    myGame->move(2, 1);

    myGame->printGame();

    myGame->move(0, 2);

    myGame->printGame();

    myGame->move(1, 0);

    myGame->printGame();

    myGame->move(1, 2);

    myGame->printGame();

    myGame->move(0, 2);

    myGame->printGame();

    delete myGame;
}
