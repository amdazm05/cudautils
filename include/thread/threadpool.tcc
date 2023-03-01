#ifndef _THREADPOOL
#define _THREADPOOL

#include "utils/util.hpp"
#include "thread/threadsafetaskqueue.tcc"

// What this class does:
// This is a thread pool manager , it recieves a task and  is able to execute that in a pool typically equal to the number of users specified by the user
// Execute arbitrary functions
// template tells the type of arguements that is to be passed in to the task 
// something along these lines 
class ThreadPoolManager 
{
    private:
    std::atomic_bool _isDone;
    std::vector<std::thread> _workers;
    ThreadSafeTaskQueue<std::function<void()>> _threadQueueInstance;
    std::shared_ptr<ThreadPoolManager> _instance;
    // A pool is supposed to have the threads equal to the number of hardware concurrent threads possible
    std::size_t _numberOfThreads; // = std::thread::hardware_concurrency()
    ThreadPoolManager();
    ThreadPoolManager(std::size_t numberOfThreads);

    public:
    static void init(bool isBlockingModel);
    static std::shared_ptr<ThreadPoolManager> get_instance();

    // Now this needs to be binded
    template<class T, class... Args>
    std::future<typename std::result_of<T(Args...)>::type> queueTask(T && invokAble , Args && ... arguments);
};

#endif //_THREADPOOL
// For some clarity see the example you made
// https://godbolt.org/z/a6nrEjMdc
// helpful thread for my understanding
// https://stackoverflow.com/questions/63240416/whats-the-difference-between-unique-lock-and-shared-lock-in-c
// My inspirations : https://github.com/USCiLab/cereal
// Most notably : // to be honest its more of a learning goal here :)
// https://github.com/progschj/ThreadPool/blob/master/ThreadPool.h