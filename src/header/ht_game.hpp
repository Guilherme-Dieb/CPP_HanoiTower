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
            bool _isRunning;
            bool _areCommandsHidden;

            std::vector<Tower*> _towers = {};
            Commands _commands;
            
            void FlushTowers();
            void InitializeTowers(int numberOfDisks);

            bool IsNumberOfDisksValid(int);
            bool IsTowerIDValid(int);
            bool HasThePlayerWon();
            
            void UpdateScreen();
            void InitializationScreen();
            void DoYouWishToPlayAgainScreen();
            void AutoSolveScreen();
            bool AreYouSureYouWantToQuitScreen();

            void ToggleCommandsVisibility();

            void ChangeGameState(GameState);

            void PrintCommands();
            void PrintTowers();
            void AutoSolve();

            void Continue();
            void Initialize();
            void Update();
            void Auto();
            void End();

    };
}