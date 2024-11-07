#pragma once

#include <iostream>
#include <string>

#include "ht_config.hpp"
#include "debug.hpp"

namespace HanoiTower
{
    class disk
    {
        public:
            int getSize();
            disk* getTop();
            disk* getBottom();

            void setTop(disk*);
            void setBottom(disk*);

            disk(int size);
            disk(int size, disk* top, disk* bottom);

            ~disk();

            void printSize();

            void printDisk();

        private:
            int _diskSize;
            disk* _topDisk;
            disk* _bottomDisk;
    };
}