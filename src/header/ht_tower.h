#pragma once

#include "ht_disk.h"

namespace HanoiTower
{
    class tower
    {
        public:
            disk* getTopDisk();
            disk* getBottomDisk();

            tower();
            tower(int size);

            ~tower();

            void addDisk(disk* newDisk);

            disk* popDisk();

            void printTower();

            void printSize();

        private:
            int towerSize;
            disk* topDisk;
            disk* bottomDisk;

            void printStack(disk*);

            void destroyDisks(disk*);
    };
}