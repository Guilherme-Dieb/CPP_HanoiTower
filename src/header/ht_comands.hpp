#pragma once

#include <vector>
#include <iostream>

#include "ht_tower.hpp"
#include "debug.hpp"

namespace HanoiTower
{
    class commands{
        public:
            ~commands();

            bool loadCommand(int origin, int destiny);
            bool executeCurrentCommand(std::vector<tower*> _towers);
            void executeAllCommand(std::vector<tower*> _towers);

        private:
            int _nextCommandID = 0;
            int _totalCommands = -1;
            struct sCommand
            {
                public:
                    int origin;
                    int destiny;
            };
            std::vector<sCommand*> _commands = {};

            void executeCommand(std::vector<tower*>, sCommand*);
            bool isCommandIDValid(int);
            bool doesTowerExists(std::vector<tower*>, int towerID);
    };
}