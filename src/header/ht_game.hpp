#pragma once

#include <vector>
#include <iostream>

#include "ht_tower.hpp"
#include "ht_comands.hpp"
#include "debug.hpp"

namespace HanoiTower
{
    class game
    {
        public:
            game(int numberOfDisks);
            ~game();

            void printGame();

            void move(int origin, int destiny);

            void autoSolve();
        private:
            int _towerMaxSize;

            std::vector<tower*> _towers = {};
            HanoiTower::commands _commands = HanoiTower::commands();
    };
}