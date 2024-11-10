#pragma once

#include <vector>

#include "ht_tower.hpp"
#include "debug.hpp"

namespace HanoiTower
{
    class Commands{
        public:
            ~Commands();

            bool LoadCommand(int origin, int destiny);
            bool LoadAndExecuteCommand(std::vector<Tower*> towers, int origin, int destiny);

            void OverwriteCommand(int origin, int destiny);
            
            bool ExecuteCurrentCommand(std::vector<Tower*> towers);
            bool ExecuteAllCommands(std::vector<Tower*> towers);

            bool UndoCommand(std::vector<Tower*> towers);
            void UndoAllCommands(std::vector<Tower*> towers);

            void PrintCommands();

        private:
            int _nextCommandID = 0;
            int _totalCommands = -1;
            struct sCommand
            {
                public:
                    int origin;
                    int destiny;

                    ~sCommand(){Debug::Log("Command Deleted");}
            };
            std::vector<sCommand*> _commands = {};

            void ExecuteCommand(std::vector<Tower*>, sCommand*);
            bool IsCommandIDValid(int);
            bool DoesTowerExists(std::vector<Tower*>, int);
            bool CanCommandBeExecuted(Tower*, Tower* );
    };
}