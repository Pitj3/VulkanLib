#include "Common.hpp"

#include "EventManager.hpp"

EventManager* EventManager::instance;

EventManager::EventManager()
{
    
}

EventManager::~EventManager()
{

}

EventManager* EventManager::get()
{
    if(instance == nullptr)
    {
        instance = new EventManager();
    }

    return instance;
}

void EventManager::destroy()
{
    delete instance;
}

void EventManager::poll()
{
    glfwPollEvents();
}