#ifndef _THREAD_QUEUE
#define _THREAD_QUEUE

#include "utils/util.hpp"

class thread_queue
{
    public:
        thread_safe_queue();
        ~thread_safe_queue();
        void enqueue();
        void dequeue();
    private:
        std::queue<std::thread> queueManager;
};

#endif //_THREAD_QUEUE