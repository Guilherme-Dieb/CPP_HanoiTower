#pragma once

#include "ht_tower.hpp"
#include "ht_commands.hpp"
#include "ht_analyzer.hpp"
#include "ht_inputmanager.hpp"
#include "debug.hpp"

namespace HanoiTower
{
    class Game
    {
        public:
            Game();
            ~Game();

            void Run();

            void PrintTowers();

            void Move(int origin, int destiny);

            void AddMove(int origin, int destiny);

            void ChangeMove(int origin, int destiny);

            void ExecuteMove();
            void ExecuteAllMoves();

            void UndoMove();
            void UndoAllMoves();

            void PrintComands();

            void Analyze();

            void AutoSolve();
            
        private:
            enum GameState
            {
                UPDATE,
                END,
                CONTINUE,
                INITIALIZE,
                AUTO,
                NOSTATE,
            } _gameState, _previousGameState;

            const int _numberOfTowers = 3;
            int _towerMaxSize;
            bool isRunning;

            std::vector<Tower*> _towers = {};
            Commands _commands;
            
            void FlushTowers();
            void InitializeTowers(int numberOfDisks);

            bool IsNumberOfDisksValid(int);
            bool IsTowerIDValid(int);
            bool HasThePlayerWon();

            void UpdateScreen();
            void InitializationScreen();
            void DoYouWishToPlayAgain();
            bool AreYouSureYouWantToQuit();

            void ChangeGameState(GameState);

            void Continue();
            void Initialize();
            void Update();
            void Auto();
            void End();

    };
}