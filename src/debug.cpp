#include "header/debug.hpp"
#include <termios.h>
#include <unistd.h>

#define DEBUGMODE = 1
#if defined(DEBUGMODE) == 1
#define LOG(x) std::cout<<x<<std::endl
#define PRINT(x) std::cout<<x
#define CLEAR() std::system("clear")
#define TOOGLETERMINALCONFIG() struct termios settings; tcgetattr(STDIN_FILENO, &settings); settings.c_lflag &= (~ICANON); tcsetattr(STDIN_FILENO, TCSANOW, &settings);
#else
#define LOG(x)
#define PRINT(x)
#define CLEAR()
#define TOOGLETERMINALCONFIG()
#endif

void Debug::Log(std::string msg)
{
    
    LOG(msg);
}

void Debug::Print(std::string msg)
{
    PRINT(msg);
}

void Debug::Clear()
{
    CLEAR();
}

void Debug::ToogleTerminalConfig()
{
    TOOGLETERMINALCONFIG();
}