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
            bool loadAndExecuteCommand(std::vector<tower*> towers, int origin, int destiny);

            void overwriteCommand(int origin, int destiny);
            
            bool executeCurrentCommand(std::vector<tower*> towers);
            bool executeAllCommands(std::vector<tower*> towers);

            bool undoCommand(std::vector<tower*> towers);
            void undoAllCommands(std::vector<tower*> towers);

            void printCommands();

        private:
            int _nextCommandID = 0;
            int _totalCommands = -1;
            struct sCommand
            {
                public:
                    int origin;
                    int destiny;

                    ~sCommand(){debug::log("Command Deleted");}
            };
            std::vector<sCommand*> _commands = {};

            void executeCommand(std::vector<tower*>, sCommand*);
            bool isCommandIDValid(int);
            bool doesTowerExists(std::vector<tower*>, int);
            bool canCommandBeExecuted(tower*, tower* );
    };
}