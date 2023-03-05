#ifndef _TIMER
#define _TIMER

#include "utils/util.hpp"

class Timer
{
    public:
        Timer();
        void startTimer();
        void stopTimer();
        ~Timer();
    private:
        using system_stopwatch = std::chrono::system_clock;
        using monotonic_stopwatch = std::chrono::steady_clock;
};

#endif //_TIMER