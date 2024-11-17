#pragma once

#include "debug.hpp"
#include "ht_config.hpp"

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
            static std::string TowerIDtoPrintConnector();

            static char BackSpace();
            static char Yes();
            static char No();
            static char Enter();
            static char Quit();
            static char Auto();

        private:
            Config();
            static Config& GetInstance();

            std::string _diskPrefix = " ";
            std::string _diskSufix = " ";
            std::string _towerPrefix = "[";
            std::string _towerSufix = "]\n";
            std::string _towerIDtoPrintConnector = " -> ";

            char _backSpace = '\177';
            char _yes = 'y';
            char _no = 'n';
            char _enter = '\n';
            char _quit = 'q';
            char _auto = 'a';

            std::string IDiskPrefix();
            std::string IDiskSufix();

            std::string ITowerPrefix();
            std::string ITowerSufix();
            std::string ITowerIDtoPrintConnector();

            char IBackSpace();
            char IYes();
            char INo();
            char IEnter();
            char IQuit();
            char IAuto();
    };
}