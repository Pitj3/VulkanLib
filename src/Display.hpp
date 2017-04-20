#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "Common.hpp"

class Display
{
    public:
        Display(uint16 width, uint16 height);
        ~Display();

        void swapBuffers();

    private:
        uint8 _width, _height;

        GLFWwindow* _window;
};

#endif // DISPLAY_H_