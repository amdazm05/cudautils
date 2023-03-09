#ifndef _TIMER
#define _TIMER

#include "utils/util.hpp"

// The default is seconds
#define DURATION_s std::chrono::duration<double>
#define DURATION_ns std::chrono::duration<double,std::nano>
#define DURATION_us std::chrono::duration<double,std::micro>

// for more references
// https://en.cppreference.com/w/cpp/chrono/duration

#if __cplusplus >= 202002L
    #define DURATION_minutes std::chrono::duration<double,std::ratio<60>>
     #define DURATION_days std::chrono::duration<double,std::ratio<3600>>>
#endif

using system_stopwatch = std::chrono::system_clock;
using monotonic_stopwatch = std::chrono::steady_clock;

template<class TypeofClock,class DurationType>
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
        DurationType elapsedTime;
};

template<class TypeofClock,class DurationType>
Timer<TypeofClock,DurationType>::Timer()
{

}

template<class TypeofClock, class DurationType>
void Timer<TypeofClock,DurationType>::startTimer()
{
    start = TypeofClock::now();
}

template<class TypeofClock, class DurationType>
double Timer<TypeofClock,DurationType>::getTime()
{
    return elapsedTime.count();
}

template<class TypeofClock, class DurationType>
void Timer<TypeofClock,DurationType>::stopTimer()
{
    stop = TypeofClock::now();
    elapsedTime = stop - start;
}

template<class TypeofClock, class DurationType>
Timer<TypeofClock,DurationType>::~Timer()
{

}

#endif //_TIMER