#ifndef _TIMER
#define _TIMER

#include "utils/util.hpp"

using system_stopwatch = std::chrono::system_clock;
using duration = std::chrono::duration<double>;
using monotonic_stopwatch = std::chrono::steady_clock;
template<class TypeofClock, class Duration>
class Timer
{
    public:
        Timer();
        void startTimer();
        void stopTimer();
        double getTime();
        ~Timer();
    private:
        std::chrono::time_point<TypeofClock> start;
        std::chrono::time_point<TypeofClock>  stop;
        Duration elapsedTime;
};

template<class TypeofClock, class Duration>
Timer<TypeofClock,Duration>::Timer()
{

}

template<class TypeofClock, class Duration>
void Timer<TypeofClock,Duration>::startTimer()
{
    start = TypeofClock::now();
}

template<class TypeofClock, class Duration>
double  Timer<TypeofClock,Duration>::getTime()
{
    return elapsedTime.count();
}

template<class TypeofClock, class Duration>
void Timer<TypeofClock,Duration>::stopTimer()
{
    stop = TypeofClock::now();
    elapsedTime = stop - start;
}

template<class TypeofClock, class Duration>
Timer<TypeofClock,Duration>::~Timer()
{

}

#endif //_TIMER