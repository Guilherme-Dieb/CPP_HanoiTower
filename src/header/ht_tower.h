#pragma once

#include "ht_disk.h"
#include "ht_tower.h"
#include "ht_config.h"

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

        private:
            int _towerSize;
            disk* _topDisk;
            disk* _bottomDisk;

            void fillTower(int size);

            void printStack(disk*);

            void destroyDisks(disk*);
    };
}