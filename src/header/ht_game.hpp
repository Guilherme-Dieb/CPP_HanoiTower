#pragma once

#include "ht_tower.hpp"
#include "ht_commands.hpp"
#include "debug.hpp"

namespace HanoiTower
{
    class Game
    {
        public:
            Game(int numberOfDisks);
            ~Game();

            void PrintGame();

            void Move(int origin, int destiny);

            void AddMove(int origin, int destiny);

            void ChangeMove(int origin, int destiny);

            void ExecuteMove();
            void ExecuteAllMoves();

            void UndoMove();
            void UndoAllMoves();

            void PrintComands();

            void AutoSolve();
        private:
            const int _numberOfTowers = 3;
            int _towerMaxSize;

            std::vector<Tower*> _towers = {};
            HanoiTower::Commands _commands = HanoiTower::Commands();
    };
}