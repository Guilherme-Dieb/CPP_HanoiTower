#include "header/debug.hpp"

#define DEBUGMODE = 1
#if defined(DEBUGMODE) == 1
#define LOG(x) std::cout<<x<<std::endl
#else
#define LOG(x)
#endif

void Debug::Log(std::string msg)
{
    
    LOG(msg);
}