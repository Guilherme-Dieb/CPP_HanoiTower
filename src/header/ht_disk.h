#pragma once

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
            disk(int seze, disk* top, disk* bottom);

            void printSize();

            void printDisk();

        private:
            int diskSize;
            disk* topDisk;
            disk* bottomDisk;
    };
}