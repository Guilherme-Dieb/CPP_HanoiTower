#pragma once

#include "debug.hpp"

namespace HanoiTower
{
    class Config
    {
        public:
            Config(const Config&) = delete;

            static std::string DiskPrefix();
            static std::string DiskSufix();


            static std::string TowerPrefix();
            static std::string TowerSufix();

        private:
            Config();
            static Config& GetInstance();

            std::string _diskPrefix = " ";
            std::string _diskSufix = " ";
            std::string _towerPrefix = "[";
            std::string _towerSufix = "]\n";

            std::string IDiskPrefix();
            std::string IDiskSufix();

            std::string ITowerPrefix();
            std::string ITowerSufix();
            
    };
}