#pragma once

#include <vector>
#include <iostream>

#include "ht_tower.hpp"
#include "ht_commands.hpp"
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

            void addMove(int origin, int destiny);

            void changeMove(int origin, int destiny);

            void executeMove();
            void executeAllMoves();

            void undoMove();
            void undoAllMoves();

            void printComands();

            void autoSolve();
        private:
            const int _numberOfTowers = 3;
            int _towerMaxSize;

            std::vector<tower*> _towers = {};
            HanoiTower::commands _commands = HanoiTower::commands();
    };
}