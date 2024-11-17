#include "header/ht_inputmanager.hpp"

using namespace HanoiTower;

//PUBLIC FUNCTIONS
InputManager::InputManager()
{
    //TODO load prefs from file
}

/// @brief Receive a char, if digit add it to the buffer, if enter clear the buffer, if backspace remove the last input added to the buffer
/// @param character 
/// @return
void InputManager::AddCharInIntBuffer(unsigned char character)
{
    GetInstance().IAddCharInIntBuffer(character);
}

/// @brief Receive a char and convert it to int
/// @param character 
/// @return Return a positive int value if char is a digit, return -1 otherwise
int InputManager::GetInt(unsigned char character)
{
    return GetInstance().IGetInt(character);
}

int InputManager::GetIntBuffer()
{
    return GetInstance().IGetIntBuffer();
}

void InputManager::FlushIntBuffer()
{
    GetInstance().IFlushIntBuffer();
}

char InputManager::GetChar()
{
    return GetInstance().IGetChar();
}

InputManager &InputManager::GetInstance()
{
    static InputManager instance;
    return instance;
}

//INTERNAL FUNCTIONS FROM THE SINGLETON 
void InputManager::IAddCharInIntBuffer(unsigned char character)
{
    if(character == Config::BackSpace())
    {
        _intBuffer = _intBuffer / 10;

        return;
    }

    int toAdd = IGetInt(character);

    if(toAdd < 0)
    {
        return;
    }

    _intBuffer = _intBuffer * 10 + toAdd;
}

int InputManager::IGetInt(unsigned char character)
{
    if(!std::isdigit(character))
    {
        return -1;
    }

    return IConvertToInt(character);
}

int InputManager::IConvertToInt(unsigned char character)
{
    return ((int)character - (int)'0');
}

int InputManager::IGetIntBuffer()
{
    return _intBuffer;
}

char InputManager::IGetChar()
{
    Debug::ToogleTerminalConfig();

    char character = std::cin.get();

    Debug::ToogleTerminalConfig();

    return character;
}

void InputManager::IFlushIntBuffer()
{
    _intBuffer = 0;
}