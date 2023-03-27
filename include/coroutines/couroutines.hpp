#ifndef _COROUTINES
#define _COROUTINES

#include "utils/util.hpp"
class Coroutines
{
    public:
    struct promise_type
    {
        public:
        int m_val;
        Coroutines get_return_object() { return Coroutines(this); }
        std::suspend_always initial_suspend() noexcept { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        std::suspend_always yield_value(int val){m_val = val; return {};}
        void return_value(int val) {m_val = val;}
        void unhandled_exception() {}
    };
    Coroutines(promise_type * prom):
        m_handle(std::coroutine_handle<promise_type>::from_promise(*prom)){}
    ~Coroutines(){m_handle.destroy();}
    public:
    std::coroutine_handle<promise_type> m_handle;
};
// https://godbolt.org/z/Tocb6zzqT
#endif