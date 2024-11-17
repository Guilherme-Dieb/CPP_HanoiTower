#include <vector>

#include "debug.hpp"
#include "ht_config.hpp"

namespace HanoiTower
{
    class InputManager
    {
        public:
            InputManager(const Config&) = delete;

            static void AddCharInIntBuffer(unsigned char character);
            static int GetIntBuffer();
            static int GetInt(unsigned char character);
            static void FlushIntBuffer();
            static char GetChar();

        private:
            InputManager();
            static InputManager& GetInstance();

            int _intBuffer = 0;
            int IConvertToInt(unsigned char character);
            void IAddCharInIntBuffer(unsigned char character);
            int IGetIntBuffer();
            int IGetInt(unsigned char character);
            void IFlushIntBuffer();
            char IGetChar();
    };
}