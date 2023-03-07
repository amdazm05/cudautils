#ifndef _TIMER
#define _TIMER

#include "utils/util.hpp"

using system_stopwatch = std::chrono::system_clock;
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
        TypeofClock start;
        TypeofClock stop;
        Duration elapsedTime;
};

template<class TypeofClock, class Duration>
Timer<T>::Timer()
{

}

template<class TypeofClock, class Duration>
void Timer<T>::startTimer()
{
    start = T::now();
}

template<class TypeofClock, class Duration>
double Timer<TypeofClock,Duration>::getTime()
{
    return elapsedTime.count;
}

template<class TypeofClock, class Duration>
void Timer<TypeofClock,Duration>::stopTimer()
{
    stop = T::now();
    elapsedTime = start - stop;
}

template<class TypeofClock, class Duration>
Timer<TypeofClock,Duration>::~Timer()
{

}

#endif //_TIMER