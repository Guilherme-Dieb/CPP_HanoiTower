#pragma once

#include "ht_disk.hpp"
#include "ht_tower.hpp"
#include "ht_config.hpp"
#include "debug.hpp"

namespace HanoiTower
{
    class tower
    {
        public:
            disk* getTopDisk();
            disk* getBottomDisk();
            int getSize();

            tower();
            tower(int size);

            ~tower();

            void pushDisk(disk* newDisk);

            disk* popDisk();

            void printTower();

            void printSize();

            bool isTowerEmpty();

        private:
            int _towerSize;
            disk* _topDisk;
            disk* _bottomDisk;

            void fillTower(int size);

            void printStack(disk*);

            void destroyDisks(disk*); 
    };
}