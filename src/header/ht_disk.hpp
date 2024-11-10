#pragma once

#include "ht_config.hpp"
#include "debug.hpp"

namespace HanoiTower
{
    class Disk
    {
        public:
            int GetSize();
            Disk* GetTop();
            Disk* GetBottom();

            void SetTop(Disk*);
            void SetBottom(Disk*);

            Disk(int size);
            Disk(int size, Disk* top, Disk* bottom);

            ~Disk();

            void PrintSize();

            void PrintDisk();

        private:
            int _diskSize;
            Disk* _topDisk;
            Disk* _bottomDisk;
    };
}