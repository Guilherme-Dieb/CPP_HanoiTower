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