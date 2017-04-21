#ifndef EVENT_MANAGER_H_H
#define EVENT_MANAGER_H_H

class EventManager
{
    public:
        static EventManager* get();
        static void destroy();
        
        ~EventManager();

        void poll();

    private:
        static EventManager* instance;
        EventManager();
};

#endif // EVENT_MANAGER_H_H