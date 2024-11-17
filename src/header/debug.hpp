#pragma once

#include <iostream>
#include <string>

namespace Debug
{
    void Log(std::string msg);
    void Print(std::string msg);
    void Clear();
    void ToogleTerminalConfig();
}