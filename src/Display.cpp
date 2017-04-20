#include "Display.hpp"

Display::Display(uint16 width, uint16 height)
{
    _width = width;
    _height = height;

    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    _window = glfwCreateWindow((int)width, (int)height, "Vulkan Display", nullptr, nullptr);
}

Display::~Display()
{
    glfwDestroyWindow(_window);
    glfwTerminate();
}

void Display::swapBuffers()
{
    glfwSwapBuffers(_window);
}