#include <timer/timer.hpp>
#include <iostream>
int main()
{
    char c =30;
    Timer<system_stopwatch,duration> timer;
    timer.startTimer();
    while(c<54)
    {
        std::cout<<c++;
    }
    timer.stopTimer();

    std::cout<<"Timer Time in miliseconds "<<timer.getTime()<<std::endl;
    return 0;
}