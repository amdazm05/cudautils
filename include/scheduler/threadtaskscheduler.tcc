#ifndef _TASKSCHEDULER
#define _TASKSCHEDULER

#include "utils/util.hpp"

class TaskScheduler
{
    private:
        std::mutex _mtx
        bool _continueflag;
        std::condition_variable _condition;
    public:
        TaskScheduler();
        
        template<typename T, typename ...Args>
        void scheduleTaskAt(std::chrono::system_clock::time_point timePoint, T && invokable, Args... arguments);

        template<typename T, typename ...Args>
        void scheduleTaskEvery(std::chrono::system_clock::duration timePoint, T && invokable, Args... arguments);

};

#endif //_TASKSCHEDULER