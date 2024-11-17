#include "header/ht_config.hpp"

using namespace HanoiTower;

// Private
Config::Config()
{
    //TODO: make it possible to load config from a file
}

Config &Config::GetInstance()
{
    static Config instance;
    return instance;
}

std::string Config::IDiskPrefix()
{
    return _diskPrefix;
}

std::string Config::IDiskSufix()
{
    return _diskSufix;
}

std::string Config::ITowerPrefix()
{
    return _towerPrefix;
}

std::string Config::ITowerSufix()
{
    return _towerSufix;
}

std::string Config::ITowerIDtoPrintConnector()
{
    return _towerIDtoPrintConnector;
}

char Config::IBackSpace()
{
    return _backSpace;
}

char Config::IYes()
{
    return _yes;
}

char Config::INo()
{
    return _no;
}

char Config::IEnter()
{
    return _enter;
}

char Config::IQuit()
{
    return _quit;
}

char Config::IAuto()
{
    return _auto;
}

//Public
std::string Config::DiskPrefix()
{
    return GetInstance().IDiskPrefix();
}

std::string Config::DiskSufix()
{
    return GetInstance().IDiskSufix();
}

std::string Config::TowerPrefix()
{
    return GetInstance().ITowerPrefix();
}

std::string Config::TowerSufix()
{
    return GetInstance().ITowerSufix();
}

std::string Config::TowerIDtoPrintConnector()
{
    return GetInstance().ITowerIDtoPrintConnector();
}

char Config::BackSpace()
{
    return GetInstance().IBackSpace();
}

char Config::Yes()
{
    return GetInstance().IYes();
}

char Config::No()
{
    return GetInstance().INo();
}

char Config::Enter()
{
    return GetInstance().IEnter();
}

char Config::Quit()
{
    return GetInstance().IQuit();
}

char Config::Auto()
{
    return GetInstance().IAuto();
}