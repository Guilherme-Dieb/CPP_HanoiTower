#pragma once

namespace HanoiTower
{
    class disk
    {
        public:
            int getSize();
            disk* getNext();
            disk* getPrevious();

            void setNext(disk*);
            void setPrevious(disk*);

            disk(int, disk*, disk*);

            void printSize();

        private:
            int diskSize;
            disk* nextDisk;
            disk* previousDisk;
    };
}