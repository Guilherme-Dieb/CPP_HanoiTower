#include "header/ht_game.hpp"

int main(int, char**)
{
    Debug::Log("DEBUG VERSION\n");

    HanoiTower::Game myGame = HanoiTower::Game();

    myGame.Run();
}
