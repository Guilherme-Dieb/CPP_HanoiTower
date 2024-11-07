#include "header/ht_config.hpp"

using namespace HanoiTower;

// Private
config::config()
{
    //TODO: make it possible to load config from a file
}

config &config::getInstance()
{
    static config instance;
    return instance;
}

std::string config::iDiskPrefix()
{
    return _diskPrefix;
}

std::string config::iDiskSufix()
{
    return _diskSufix;
}

std::string config::iTowerPrefix()
{
    return _towerPrefix;
}

std::string config::iTowerSufix()
{
    return _towerSufix;
}

//Public
std::string config::diskPrefix()
{
    return getInstance().iDiskPrefix();
}

std::string config::diskSufix()
{
    return getInstance().iDiskSufix();
}

std::string config::towerPrefix()
{
    return getInstance().iTowerPrefix();
}

std::string config::towerSufix()
{
    return getInstance().iTowerSufix();
}