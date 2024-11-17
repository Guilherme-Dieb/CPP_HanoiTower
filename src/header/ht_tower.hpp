#pragma once

#include "ht_disk.hpp"
#include "ht_tower.hpp"
#include "ht_config.hpp"
#include "debug.hpp"

namespace HanoiTower
{
    class Tower
    {
        public:
            Disk* GetTopDisk();
            Disk* GetBottomDisk();
            int GetSize();

            Tower();
            Tower(int size);

            ~Tower();

            void PushDisk(Disk* newDisk);

            Disk* PopDisk();

            void PrintTower();

            void PrintSize();

            bool IsTowerEmpty();

            void FlushTower();

            void FillTower(int size);

        private:
            int _towerSize;
            Disk* _topDisk;
            Disk* _bottomDisk;

            void Initialize();

            void PrintStack(Disk*);

            void DestroyDisksFromTop(Disk*); 
    };
}