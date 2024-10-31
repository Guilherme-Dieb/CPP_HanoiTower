#pragma once

#include <iostream>
#include <string>

namespace HanoiTower
{
    class config
    {
        public:
            config(const config&) = delete;

            static std::string diskPrefix();
            static std::string diskSufix();


            static std::string towerPrefix();
            static std::string towerSufix();

        private:
            config();
            static config& getInstance();

            std::string _diskPrefix = " ";
            std::string _diskSufix = " ";
            std::string _towerPrefix = "[";
            std::string _towerSufix = "]\n";

            std::string iDiskPrefix();
            std::string iDiskSufix();

            std::string iTowerPrefix();
            std::string iTowerSufix();
            
    };
}