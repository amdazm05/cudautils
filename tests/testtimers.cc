#include <timer/timer.hpp>
#include <iostream>
int main()
{
    char c =30;
    Timer<system_stopwatch,DURATION_ns> timer_n;
    timer_n.startTimer();
    while(c<54)
    {
        c++;
    }
    std::cout<<std::endl;
    timer_n.stopTimer();

    std::cout<<"Timer Time in nano seconds "<<timer_n.getTime()<<std::endl;

    c =30;
    Timer<system_stopwatch,DURATION_us> timer_u;
    timer_u.startTimer();
    while(c<54)
    {
        c++;
    }
    std::cout<<std::endl;
    timer_u.stopTimer();
    std::cout<<"Timer Time in micro seconds "<<timer_u.getTime()<<std::endl;

    c =30;
    Timer<system_stopwatch,DURATION_s> timer;
    timer.startTimer();
    while(c<54)
    {
        c++;
    }
    std::cout<<std::endl;
    timer.stopTimer();
    std::cout<<"Timer Time in seconds "<<timer.getTime()<<std::endl;


    return 0;
}