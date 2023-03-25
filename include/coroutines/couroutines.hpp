#ifndef _COROUTINES
#define _COROUTINES

#include "utils/util.hpp"

template<class T>
class Coroutines : std::coroutine_handle<promise>
{
    public:
    struct promise
    {
        int m_val;
        coroutine get_return_object() { return {coroutine::from_promise(*this)}; }
        std::suspend_always initial_suspend() noexcept { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        std::suspend_always yield_value(int val){m_value = val; return {};}
        void return_value(int val) {m_val = int}
        void return_void() {}
        void unhandled_exception() {}
    };
    Coroutine(promise * prom):
        m_handle(std::coroutine_handle<promise>::from_promise(*prom)){}
    ~Coroutines(){m_handle.destroy();}
    std::coroutine_handle<promise> m_handle;
};
// https://godbolt.org/z/Tocb6zzqT
#endif