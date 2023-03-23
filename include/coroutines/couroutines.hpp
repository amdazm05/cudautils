#ifndef _COROUTINES
#define _COROUTINES

#include "utils/util.hpp"

template<class T>
class Coroutines : std::coroutine_handle<promise>
{
    public:
    struct promise
    {
        coroutine get_return_object() { return {coroutine::from_promise(*this)}; }
        std::suspend_always initial_suspend() noexcept { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        void return_void() {}
        void unhandled_exception() {}
    };
};



#endif