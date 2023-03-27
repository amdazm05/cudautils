#include "coroutines/couroutines.hpp"

Coroutines foo()
{
    co_await  std::suspend_always{};
    std::cout<<"first point"<<std::endl;
    co_await  std::suspend_always{};
    std::cout<<"second point"<<std::endl;
    co_yield 43; 
    std::cout<<"third point yeild"<<std::endl;
    co_return 32;
}

int main()
{
    Coroutines task = foo();
    task.m_handle();
    task.m_handle();
    task.m_handle();
    std::cout<<task.m_handle.promise().m_val<<std::endl;
    task.m_handle();
    std::cout<<task.m_handle.promise().m_val<<" - flag - " <<std::boolalpha<<task.m_handle.done()<<std::endl;
    return 0;
}